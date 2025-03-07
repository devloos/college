from typing import AsyncGenerator
import pytest
from beanie import init_beanie
from motor.motor_asyncio import AsyncIOMotorClient, AsyncIOMotorClientSession
from pydantic import ValidationError
from pymongo.errors import DuplicateKeyError

from datetime import datetime
from schema_object import SchemaObject
from schema import Schema
import pytest_asyncio


def get_schema():
    schema_dict = {
        'name': 'My Schema',
        'description': 'A description of my schema',
        'createdAt': datetime(2000, 12, 1),
    }

    return schema_dict


def get_schema_object():
    schema_objects_dict = {
        'name': 'My Schema Object',
        'description': 'A description of my schema object',
        'createdAt': datetime(2013, 12, 1),
        'schemaName': 'My Schema',
    }

    return schema_objects_dict


@pytest_asyncio.fixture()
async def session() -> AsyncGenerator[AsyncIOMotorClientSession]:
    motor_client = AsyncIOMotorClient(
        "mongodb://localhost:27018/?directConnection=true&replicaSet=rs0&w=majority"
    )
    # Be sure to change the database name to whatever you want in your MongoDB database.
    db = motor_client.get_database("BeanieDemo")
    await init_beanie(database=db, document_models=[Schema, SchemaObject])

    async with await motor_client.start_session() as session:
        async with session.start_transaction():
            schema_dict = get_schema()
            schema_model = Schema(**schema_dict)

            await schema_model.insert(session=session)

            yield session

            await schema_model.delete(session=session)


@pytest.mark.asyncio
async def test_insert_schema_object(session: AsyncIOMotorClientSession):
    schema_object_dict = get_schema_object()
    schema_object_model = SchemaObject(**schema_object_dict)

    await schema_object_model.insert(session=session)

    schema_objects = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

    assert len(schema_objects) == 1

    await schema_object_model.delete(session=session)


@pytest.mark.asyncio
async def test_bad_type_schema_object(session: AsyncIOMotorClientSession):
    schema_object_dict = get_schema_object()
    schema_object_dict['createdAt'] = "not a time"

    with pytest.raises(ValidationError) as SE:
        schema_object_model = SchemaObject.model_validate(schema_object_dict)
        await schema_object_model.insert(session=session)


@pytest.mark.asyncio
async def test_string_too_long_schema_object(session: AsyncIOMotorClientSession):
    schema_object_dict = get_schema_object()
    schema_object_dict['name'] = '0' * 84

    with pytest.raises(ValidationError) as SE:
        schema_object_model = SchemaObject(**schema_object_dict)
        await schema_object_model.insert(session=session)


@pytest.mark.asyncio
async def test_delete_schema_object(session: AsyncIOMotorClientSession):
    schema_object_dict = get_schema_object()
    schema_object_model = SchemaObject(**schema_object_dict)

    await schema_object_model.insert(session=session)

    schema_object_models = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

    assert len(schema_object_models) == 1

    schema_object_model = await SchemaObject.find_one(SchemaObject.name == schema_object_model.name, session=session)

    await schema_object_model.delete(session=session)

    schema_object_models = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

    assert len(schema_object_models) == 0


# def test_non_existent_schema(db_session: Session):
#     # store schema object
#     schema_object = get_schema_object()
#     schema_object.schemaName = 'Non Existent Schema'
#     db_session.add(schema_object)

#     with pytest.raises(IntegrityError) as IE:
#         db_session.flush()

#     assert str(IE.value).find('violates foreign key constraint') > -1


# def test_delete_parent(db_session: Session):
#     # store schema object
#     schema_object = get_schema_object()
#     db_session.add(schema_object)
#     db_session.flush()

#     # delete schema parent
#     schema = get_schema()
#     stored_schema = db_session.query(Schema).filter_by(
#         name=schema.name
#     ).first()
#     db_session.delete(stored_schema)

#     with pytest.raises(IntegrityError) as IE:
#         db_session.flush()

#     assert str(IE.value).find('violates foreign key constraint') > -1


# def test_duplicate_schema_object(db_session: Session):
#     schema_object = get_schema_object()
#     db_session.add(schema_object)
#     db_session.flush()

#     schema_object = get_schema_object()
#     db_session.add(schema_object)

#     with pytest.raises(IntegrityError) as IE:
#         db_session.flush()

#     assert str(IE).find(
#         'duplicate key value violates unique constraint "schema_objects_pk_01"') > -1

@pytest.mark.asyncio
async def test_duplicate_schema_object(session: AsyncIOMotorClientSession):
    # insert first schema object
    schema_object_dict = get_schema_object()
    schema_object_model = SchemaObject(**schema_object_dict)

    await schema_object_model.insert(session=session)

    # insert second schema object
    try:
        schema_object_model = SchemaObject(**schema_object_dict.copy())
        await schema_object_model.insert(session=session)
    except DuplicateKeyError as DKE:
        await session.abort_transaction()


# def test_duplicate_schema_object_different_parents(db_session: Session):
#     # Create schema object
#     schema_object = get_schema_object()
#     db_session.add(schema_object)
#     db_session.flush()

#     # Insert new schema
#     schema = get_schema()
#     schema.name = 'Another Schema'
#     db_session.add(schema)
#     db_session.flush()

#     # Create another schema object with same name but different schema
#     schema_object = get_schema_object()
#     schema_object.schemaName = schema.name
#     db_session.add(schema_object)
#     db_session.flush()

#     assert db_session.query(SchemaObject).count() == 2


@pytest.mark.asyncio
async def test_name_too_short_schema_object(session: AsyncIOMotorClientSession):
    schema_object_dict = get_schema_object()
    schema_object_dict['name'] = 'SHRT'

    with pytest.raises(ValidationError) as SE:
        schema_model = SchemaObject(**schema_object_dict)
        await schema_model.insert(session=session)
