import pytest
from beanie import init_beanie, BeanieObjectId
from motor.motor_asyncio import AsyncIOMotorClient
from pydantic import ValidationError

from datetime import datetime
from schema_object import SchemaObject


def get_schema_object():
    schema_objects_dict = {
        'name': 'My Schema Object',
        'description': 'A description of my schema object',
        'createdAt': datetime(2013, 12, 1),
        'schemaId': BeanieObjectId(),
    }

    return schema_objects_dict


@pytest.fixture()
async def init():
    client = AsyncIOMotorClient(
        "mongodb://localhost:27018/?directConnection=true&replicaSet=rs0&w=majority"
    )
    # Be sure to change the database name to whatever you want in your MongoDB database.
    db = client.get_database("BeanieDemo")
    await init_beanie(database=db, document_models=[SchemaObject])

    return client


@pytest.mark.asyncio
async def test_insert_schema(init):
    new_client: AsyncIOMotorClient = await init

    async with await new_client.start_session() as session:
        async with session.start_transaction():
            schema_object_dict = get_schema_object()
            schema_object_model = SchemaObject(**schema_object_dict)

            await schema_object_model.insert(session=session)

            schema_objects = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

            assert len(schema_objects) == 1

            await schema_object_model.delete(session=session)


@pytest.mark.asyncio
async def test_bad_type_schema(init):
    new_client: AsyncIOMotorClient = await init

    async with await new_client.start_session() as session:
        async with session.start_transaction():
            schema_object_dict = get_schema_object()
            schema_object_dict['createdAt'] = "not a time"

            with pytest.raises(ValidationError) as SE:
                schema_object_model = SchemaObject.model_validate(schema_object_dict)
                await schema_object_model.insert(session=session)

            print(
                f"exception: {SE.value.__class__.__name__} raised.  Other Info: {str(SE.value)}")


@pytest.mark.asyncio
async def test_string_too_long_schema(init):
    pass


@pytest.mark.asyncio
async def test_delete_schema(init):
    new_client: AsyncIOMotorClient = await init

    async with await new_client.start_session() as session:
        async with session.start_transaction():
            schema_object_dict = get_schema_object()
            schema_object_model = SchemaObject(**schema_object_dict)

            await schema_object_model.insert(session=session)

            schema_object_models = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

            assert len(schema_object_models) == 1

            schema_object_model = await SchemaObject.find_one(SchemaObject.name == schema_object_model.name, session=session)

            await schema_object_model.delete(session=session)

            schema_object_models = await SchemaObject.find(SchemaObject.name == schema_object_model.name, session=session).to_list()

            assert len(schema_object_models) == 0
