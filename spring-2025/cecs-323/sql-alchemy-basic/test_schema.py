from typing import Generator
import logging
from configparser import ConfigParser

import pytest
from sqlalchemy.exc import StatementError, DataError
from sqlalchemy.orm import sessionmaker, Session

from starter import metadata, get_test_engine
from schema import Schema
from datetime import datetime


def get_schema() -> Schema:
    return Schema('My Schema', 'A description of my schema', datetime(2000, 12, 1))


@pytest.fixture(scope='function')
def db_session() -> Generator[Session]:
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


def test_insert_schema(db_session: Session):
    """
    See whether we can insert a car model into the database and verify that it is
    there by searching for it.
    :param db_session: The database connection.
    :return: None
    """
    # So far, car is just a database instance in memory, nothing more.
    schema = get_schema()
    # In SQLAlchemy, everything happens in the session.  In Beanie, it's the objects
    # themselves that inherit the necessary methods.
    db_session.add(schema)
    # perform the insert in the database.  But the new row is still not visible to other
    # sessions until we commit.  The commit operation performs an implicit flush().
    db_session.flush()
    # We know that we started with 0 rows in the table, so the one we just inserted must be the only one.
    count = db_session.query(Schema).filter_by(name=schema.name).count()
    # check to make sure that there is one and only one row in the car_model table.
    assert count == 1


def test_bad_type_schema(db_session: Session):
    schema = get_schema()
    schema.createdAt = "swanky"

    with pytest.raises(StatementError) as SE:
        db_session.add(schema)
        db_session.flush()


def test_string_too_long_schema(db_session: Session):
    schema = get_schema()
    schema.name = "*" * 100

    with pytest.raises(DataError) as DE:
        db_session.add(schema)
        db_session.flush()

    # make sure its a length error
    assert str(DE.value).find('value too long for type character varying') > -1


def test_delete_schema(db_session: Session):
    schema = get_schema()

    db_session.add(schema)
    db_session.flush()

    count = db_session.query(Schema).filter_by(name=schema.name).count()

    assert count == 1

    db_session.delete(schema)
    db_session.flush()

    count = db_session.query(Schema).filter_by(name=schema.name).count()

    assert count == 0
