import pytest
from beanie import init_beanie
from motor.motor_asyncio import AsyncIOMotorClient
from pydantic import ValidationError

from schema import Schema
from datetime import datetime

from schema import Schema


def get_schema():
    schema_dict = {
        'name': 'My Schema',
        'description': 'A description of my schema',
        'createdAt': datetime(2000, 12, 1),
    }

    return schema_dict


@pytest.fixture()
async def init():
    client = AsyncIOMotorClient(
        "mongodb://localhost:27018/?directConnection=true&replicaSet=rs0&w=majority"
    )
    # Be sure to change the database name to whatever you want in your MongoDB database.
    db = client.get_database("BeanieDemo")
    await init_beanie(database=db, document_models=[Schema])
    return client


@pytest.mark.asyncio
async def test_insert_schema(init):
    new_client: AsyncIOMotorClient = await init

    async with await new_client.start_session() as session:
        async with session.start_transaction():
            schema_dict = get_schema()
            schema_model = Schema(**schema_dict)

            await schema_model.insert(session=session)
            schemas = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

            assert len(schemas) == 1

            await schema_model.delete(session=session)


@pytest.mark.asyncio
async def test_bad_type_schema(init):
    new_client: AsyncIOMotorClient = await init

    async with await new_client.start_session() as session:
        async with session.start_transaction():
            schema_dict = get_schema()
            schema_dict['createdAt'] = "not a time"

            with pytest.raises(ValidationError) as SE:
                schema_model = Schema.model_validate(schema_dict)
                await schema_model.insert(session=session)

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
            schema_dict = get_schema()
            schema_model = Schema(**schema_dict)

            await schema_model.insert(session=session)

            schema_models = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

            assert len(schema_models) == 1

            schema_model = await Schema.find_one(Schema.name == schema_model.name, session=session)

            await schema_model.delete(session=session)

            schema_models = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

            assert len(schema_models) == 0
