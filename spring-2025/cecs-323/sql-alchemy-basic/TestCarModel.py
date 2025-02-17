import logging
from configparser import ConfigParser

import pytest
from sqlalchemy.exc import IntegrityError, StatementError, DataError
from sqlalchemy.orm import sessionmaker

from Utilities import get_test_engine, get_Ford
from orm_base import metadata, Base
from CarModel import CarModel


@pytest.fixture(scope='function')
def db_session():
    config = ConfigParser()
    config.read('config.ini')  # the config.ini file has to be in the working directory.
    log_level = eval(config['logging']['level'])
    # log_level = logging.DEBUG
    logging.basicConfig(level=log_level)
    logging.getLogger("sqlalchemy.engine").setLevel(log_level)
    logging.getLogger("sqlalchemy.pool").setLevel(log_level)
    engine = get_test_engine()
    metadata.drop_all(bind=engine)
    metadata.create_all(bind=engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    # "return" the session that we've just created.
    yield session
    # Then control comes back here where we wipe out the schema.
    session.close()
    Base.metadata.drop_all(bind=engine)


def test_insert_CarModel(db_session):
    """
    See whether we can insert a car model into the database and verify that it is
    there by searching for it.
    :param db_session: The database connection.
    :return: None
    """
    # So far, car is just a database instance in memory, nothing more.
    car = get_Ford()
    # In SQLAlchemy, everything happens in the session.  In Beanie, it's the objects
    # themselves that inherit the necessary methods.
    db_session.add(car)
    # perform the insert in the database.  But the new row is still not visible to other
    # sessions until we commit.  The commit operation performs an implicit flush().
    db_session.flush()
    # We know that we started with 0 rows in the table, so the one we just inserted must be the only one.
    car_count = (db_session.query(CarModel).
                 filter_by(manufacturerName=car.manufacturerName,
                 modelName=car.modelName,
                 modelYear=car.modelYear).
                 count())
    # check to make sure that there is one and only one row in the car_model table.
    assert car_count == 1


def test_delete_CarModel(db_session):
    car = get_Ford()
    db_session.add(car)
    db_session.flush()
    car_count = db_session.query(CarModel).\
        filter_by(manufacturerName=car.manufacturerName,
                  modelName=car.modelName,
                  modelYear=car.modelYear).\
        count()
    assert car_count == 1
    stored_car = db_session.query(CarModel).\
        filter_by(manufacturerName=car.manufacturerName,
                  modelName=car.modelName,
                  modelYear=car.modelYear).\
        first()
    db_session.delete(stored_car)
    db_session.flush()
    car_count = db_session.query(CarModel).\
        filter_by(manufacturerName=car.manufacturerName,
                  modelName=car.modelName,
                  modelYear=car.modelYear).\
        count()
    assert car_count == 0


def test_duplicate_CarModel(db_session):
    car = get_Ford()
    db_session.add(car)
    db_session.flush()
    car_repeat = get_Ford()
    db_session.add(car_repeat)
    with pytest.raises(IntegrityError) as IE:
        db_session.flush()
    assert str(IE).find(
        'duplicate key value violates unique constraint "car_model_pk"') > -1


def test_bad_type_CarModel(db_session):
    car = get_Ford()
    car.rangeElectric = "swanky"
    with pytest.raises(StatementError) as SE:
        db_session.add(car)
        db_session.flush()


def test_bad_modelYear_CarModel(db_session):
    car = get_Ford()
    with pytest.raises(ValueError) as VE:
        """
        Note that the validation occurs IN SQLAlchemy at the time that I make the 
        change to the year.  Which means that the exception is raised before we
        even add this object to the session because the car object is a member 
        of the CarModel class."""
        car.modelYear = 1856
        db_session.add(car)
        db_session.flush()
    assert str(VE.value).find('Model year predates Henry Ford') > -1


def test_tooLongString_CarModel(db_session):
    car = get_Ford()
    with pytest.raises(DataError) as DE:
        car.manufacturerName = "Way Too Long String"
        db_session.add(car)
        db_session.flush()
    assert str(DE.value).find('value too long for type character varying') > -1
