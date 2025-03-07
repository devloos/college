from typing import AsyncGenerator
import pytest
from beanie import init_beanie
from motor.motor_asyncio import AsyncIOMotorClient, AsyncIOMotorClientSession
from pydantic import ValidationError
from pymongo.errors import DuplicateKeyError

from schema import Schema
from datetime import datetime

from schema import Schema
import pytest_asyncio


def get_schema():
    schema_dict = {
        'name': 'My Schema',
        'description': 'A description of my schema',
        'createdAt': datetime(2000, 12, 1),
    }

    return schema_dict


@pytest_asyncio.fixture()
async def session() -> AsyncGenerator[AsyncIOMotorClientSession]:
    motor_client = AsyncIOMotorClient(
        "mongodb://localhost:27018/?directConnection=true&replicaSet=rs0&w=majority"
    )
    # Be sure to change the database name to whatever you want in your MongoDB database.
    db = motor_client.get_database("BeanieDemo")
    await init_beanie(database=db, document_models=[Schema])

    async with await motor_client.start_session() as session:
        async with session.start_transaction():
            yield session


@pytest.mark.asyncio
async def test_insert_schema(session: AsyncIOMotorClientSession):
    schema_dict = get_schema()
    schema_model = Schema(**schema_dict)

    await schema_model.insert(session=session)
    schemas = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

    assert len(schemas) == 1

    await schema_model.delete(session=session)


@pytest.mark.asyncio
async def test_bad_type_schema(session: AsyncIOMotorClientSession):
    schema_dict = get_schema()
    schema_dict['createdAt'] = "not a time"

    with pytest.raises(ValidationError) as SE:
        schema_model = Schema.model_validate(schema_dict)
        await schema_model.insert(session=session)


@pytest.mark.asyncio
async def test_string_too_long_schema(session: AsyncIOMotorClientSession):
    schema_dict = get_schema()
    schema_dict['name'] = '0' * 84

    with pytest.raises(ValidationError) as SE:
        schema_model = Schema(**schema_dict)
        await schema_model.insert(session=session)


@pytest.mark.asyncio
async def test_delete_schema(session: AsyncIOMotorClientSession):
    schema_dict = get_schema()
    schema_model = Schema(**schema_dict)

    await schema_model.insert(session=session)

    schema_models = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

    assert len(schema_models) == 1

    schema_model = await Schema.find_one(Schema.name == schema_model.name, session=session)

    await schema_model.delete(session=session)

    schema_models = await Schema.find(Schema.name == schema_model.name, session=session).to_list()

    assert len(schema_models) == 0


@pytest.mark.asyncio
async def test_duplicate_schema(session: AsyncIOMotorClientSession):
    # insert first schema
    schema_dict = get_schema()
    schema_model = Schema(**schema_dict)

    await schema_model.insert(session=session)

    # insert second schema
    try:
        schema_model = Schema(**schema_dict.copy())
        await schema_model.insert(session=session)
    except DuplicateKeyError as DKE:
        await session.abort_transaction()


@pytest.mark.asyncio
async def test_name_too_short_schema(session: AsyncIOMotorClientSession):
    schema_dict = get_schema()
    schema_dict['name'] = 'SHRT'

    with pytest.raises(ValidationError) as SE:
        schema_model = Schema(**schema_dict)
        await schema_model.insert(session=session)
