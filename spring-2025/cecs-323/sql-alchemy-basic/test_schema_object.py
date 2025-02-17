from typing import Generator
import logging
from configparser import ConfigParser

import pytest
from sqlalchemy.exc import StatementError, DataError
from sqlalchemy.orm import sessionmaker, Session

from starter import metadata, get_test_engine
from schema_object import SchemaObject
from schema import Schema
from datetime import datetime


def get_schema() -> Schema:
    return Schema('My Schema', 'A description of my schema', datetime(1980, 8, 1))


def get_schema_object() -> SchemaObject:
    return SchemaObject('My Schema', 'My Schema Object', 'A description of my schema object', datetime(2000, 12, 1))


@pytest.fixture(scope='function')
def db_session() -> Generator[Session]:
    config = ConfigParser()
    config.read('config.ini')

    log_level = eval(config['logging']['level'])
    logging.basicConfig(level=log_level)
    logging.getLogger("sqlalchemy.engine").setLevel(log_level)
    logging.getLogger("sqlalchemy.pool").setLevel(log_level)

    engine = get_test_engine()
    metadata.drop_all(bind=engine)
    metadata.create_all(bind=engine)

    Session = sessionmaker(bind=engine)
    session = Session()

    # create schema first
    schema = get_schema()

    session.add(schema)
    session.flush()

    yield session

    session.close()


def test_insert_schema_object(db_session: Session):
    schema_object = get_schema_object()

    db_session.add(schema_object)
    db_session.flush()

    count = db_session.query(SchemaObject).filter_by(name=schema_object.name).count()

    assert count == 1


def test_bad_type_schema(db_session: Session):
    schema_object = get_schema_object()
    schema_object.createdAt = "swanky"

    with pytest.raises(StatementError) as SE:
        db_session.add(schema_object)
        db_session.flush()


def test_string_too_long_schema(db_session: Session):
    schema_object = get_schema_object()
    schema_object.name = "*" * 100

    with pytest.raises(DataError) as DE:
        db_session.add(schema_object)
        db_session.flush()

    # make sure its a length error
    assert str(DE.value).find('value too long for type character varying') > -1


def test_delete_schema(db_session: Session):
    schema_object = get_schema_object()

    db_session.add(schema_object)
    db_session.flush()

    count = db_session.query(SchemaObject).filter_by(name=schema_object.name).count()

    assert count == 1

    db_session.delete(schema_object)
    db_session.flush()

    count = db_session.query(SchemaObject).filter_by(name=schema_object.name).count()

    assert count == 0
