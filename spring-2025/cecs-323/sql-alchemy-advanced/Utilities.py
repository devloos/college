from configparser import ConfigParser
from sqlalchemy import create_engine, Engine
from Manufacturer import Manufacturer
from CarModel import CarModel
config = ConfigParser()
config.read('config.ini')


def get_test_engine() -> Engine:
    config = ConfigParser()
    config.read('config.ini')  # the config.ini file has to be in the working directory.
    userID: str = config['credentials']['userid']
    password: str = config['credentials']['password']
    host: str = config['credentials']['host']
    port: str = config['credentials']['port']
    database: str = config['credentials']['database']
    # 'psycopg2' in this part of the db_url instructs SQLAlchemy that we are connecting to a PostgreSQL database.
    db_url: str = f"postgresql+psycopg2://{userID}:{password}@{host}:{port}/{database}"
    db_url_display: str = f"postgresql+psycopg2://{userID}:********@{host}:{port}/{database}"
    # The engine is the connection to the PostgreSQL database
    return create_engine(db_url, pool_size=5, pool_recycle=3600, echo=False)

def get_Ford(manufacturer: Manufacturer) -> CarModel:
    """
    This just stuffs some representative values into an instance of CarModel so that I don't
    have to do this repeatedly in my test cases.
    :return: A canned instance of CarModel.
    """
    # the setup in TestCarModel creates the Ford manufacturer for me, and I reference it here.
    car = CarModel(manufacturer, 'Taurus', 1984, 25,
                   30, 'manual', 1, 350, 0,
                   20000.35)
    return car

def get_ford_motor_co():
    ford = Manufacturer('Ford', '123 Ford St. Detroit Michigan')
    return ford