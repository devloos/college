import copy
import pprint

import pymongo
import pytest
from beanie import init_beanie
from motor.motor_asyncio import AsyncIOMotorClient
from pydantic import ValidationError
from pymongo.errors import DuplicateKeyError

from CarModel import CarModel, TransmissionType
from Manufacturer import Manufacturer

"""
I found that making these test object globals was the easiest way to make them
available to the individual tests after they have been created.  There may well 
be better approaches, and I'm certainly open to improving on this approach."""
test_Manufacturer: Manufacturer
test_CarModel: CarModel
database_name = "BeanieAdvanced"

def get_Manufacturer():
    manufacturer_dict = {
        'name': 'Ford',
        'address': '123 Ford St. Detroit Michigan'
    }
    return manufacturer_dict

def get_CarModel(manufacturer: Manufacturer):
    car_dict = {
        'manufacturer': manufacturer,
        'manufacturerName': manufacturer.name,
        'modelName': 'Taurus',
        'modelYear': 2022,
        'fuelEconomyCity': 25,
        'fuelEconomyHwy': 30,
        'transmissionType': TransmissionType.MANUAL,
        'climateControlZones': 1,
        'rangeGasoline': 350,
        'rangeElectric': 0,
        'MSRP': 20000.35
    }
    return car_dict

@pytest.fixture
async def init(event_loop):
    client = AsyncIOMotorClient("mongodb://localhost:27017/?directConnection=true&replicaSet=rs0&w=majority")
    # Be sure to change the database name to whatever you want in your MongoDB database.
    db = client.get_database(database_name)
    await init_beanie(database=db, document_models=[CarModel, Manufacturer])
    global test_Manufacturer
    test_Manufacturer = Manufacturer(**get_Manufacturer())
    global test_CarModel
    test_CarModel = CarModel(**get_CarModel(test_Manufacturer))
    # another approach would be to yield the client, and then follow that with
    # a statement to drop the test database.
    return client

@pytest.mark.asyncio
async def test_insert_CarModel(init):
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session = session)
            await test_CarModel.insert(session = session)
            # Use the simple find in Beanie.  Notice that the names that we are searching on
            # are the mapped entity attribute names, and the find returns objects, rather than
            # Python dictionaries.
            car_models = await CarModel.find(CarModel.manufacturerName == test_CarModel.manufacturerName,
                                             CarModel.modelName==test_CarModel.modelName,
                                             CarModel.modelYear==test_CarModel.modelYear,
                                             session = session).to_list()
            # Make sure that there is exactly one of them in the database.
            assert len(car_models)  == 1
            await test_CarModel.delete(session=session)
            await test_Manufacturer.delete(session=session)


@pytest.mark.asyncio
async def test_pipeline_CarModel(init):
    """
    This does exactly the same as test_insert_CarModel, but instead of using the simple form
    of the find, we're using a very simple MongoDB pipeline aggregation as a demonstration.
    :param init: Fixture to give us a connection to the database.
    :return: None
    """
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session=session)
            await test_CarModel.insert(session=session)
            """Find that instance using a MongoDB pipeline.  Several things to note here:
            The $and operator takes a list of conditions.  In this case, each condition is =
            The $match pipeline stage has just one operand in this cae, the $and.
            The field name that we are searching on is the PHYSICAL name.  That is because
            we are essentially just using Beanie as a "pass through" to MongoDB.
            On the other hand, the values that we are searching FOR are attributes in our 
            car_model object that we just inserted.
            """
            pipeline = [
                {"$match": {"$and": [{"manufacturer_name": test_CarModel.manufacturerName},
                                     {"model_name": test_CarModel.modelName},
                                     {"model_year": test_CarModel.modelYear}]}}
            ]
            """
            The pipeline variable is just a dictionary as far as Python is concerned.  But 
            this dictionary specifies a sequence (in this case a very short sequence) of 
            pipeline stages to process the data in MongoDB.  We use the same session as an 
            argument to the aggregate method as we would for a simple find."""
            car_models = await CarModel.aggregate(pipeline, session=session).to_list()
            # Make sure that there is exactly one of them in the database.
            assert len(car_models)  == 1
            # Note that using the $pipeline means that we get dictionaries, not objects, returned.
            for car_model_iter in car_models:
                pprint.pprint(car_model_iter)
            await test_CarModel.delete(session=session)
            await test_Manufacturer.delete(session=session)

@pytest.mark.asyncio
async def test_delete_CarModel(init):
    """
    See if we can create and then delete a CarModel.
    :param init: The database connection.
    :return: None
    """
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session = session)
            await test_CarModel.insert(session = session)
            car_models = await CarModel.find(CarModel.manufacturerName == test_CarModel.manufacturerName,
                                             CarModel.modelName==test_CarModel.modelName,
                                             CarModel.modelYear==test_CarModel.modelYear,
                                             session = session).to_list()
            assert len(car_models)  == 1
            # Go find the document that I just inserted.
            stored_car = await CarModel.find_one(CarModel.manufacturerName == test_CarModel.manufacturerName,
                                                 CarModel.modelName == test_CarModel.modelName,
                                                 CarModel.modelYear == test_CarModel.modelYear,
                                                 session = session)
            # Delete that document.
            await stored_car.delete(session = session)
            car_models = await CarModel.find(CarModel.manufacturerName == test_CarModel.manufacturerName,
                                             CarModel.modelName==test_CarModel.modelName,
                                             CarModel.modelYear==test_CarModel.modelYear,
                                             session = session).to_list()
            assert len(car_models)  == 0
            await test_Manufacturer.delete(session=session)

@pytest.mark.asyncio
async def test_duplicate_CarModel(init):
    """
    Prove that the uniqueness constraint works.
    :param init: The database connection.
    :return: None
    """
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session = session)
            # Make a copy for testing the unique index
            test_CarModelDupe = copy.copy(test_CarModel)
            await test_CarModel.insert(session = session)
            # Use the simple find in Beanie.  Notice that the names that we are searching on
            # are the mapped entity attribute names, and the find returns objects, rather than
            # Python dictionaries.
            car_models = await CarModel.find(CarModel.manufacturerName == test_CarModel.manufacturerName,
                                             CarModel.modelName==test_CarModel.modelName,
                                             CarModel.modelYear==test_CarModel.modelYear,
                                             session = session).to_list()
            # Make sure that there is exactly one of them in the database.
            assert len(car_models)  == 1
            try:
                await test_CarModelDupe.insert(session = session)
            except DuplicateKeyError as DKE:
                await session.abort_transaction()
                print(f"exception: {DKE.__class__.__name__} raised.  Other Info: {str(DKE)}")

            await test_CarModel.delete(session=session)
            await test_Manufacturer.delete(session=session)


@pytest.mark.asyncio
async def test_bad_type_CarModel(init):
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session = session)
            car_model_dict = test_CarModel.__dict__
            car_model_dict["rangeElectric"] = "swanky"
            with pytest.raises(ValidationError) as SE:
                car_model = CarModel.model_validate(car_model_dict)
                await car_model.insert(session=session)
            print(f"exception: {SE.value.__class__.__name__} raised.  Other Info: {str(SE.value)}")
            await test_Manufacturer.delete(session=session)


@pytest.mark.asyncio
async def test_bad_model_Year_CarModel(init):
    """
    This test is a bit of a "look ahead" because the CarModel class has a validator for
    modelYear that Pydantic calls.  So you could say that this isn't really something
    that we can do just yet, that this should wait until the next Beanie assignment
    where we go into depth on the various sorts of constraints that Beanie can implement.
    :param init: The fixture to create the connection to the database.
    :return: None
    """
    new_client = await init
    car_model_dict = test_CarModel.__dict__
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            # Put in a model year that predates Henry Ford.
            car_model_dict["modelYear"] = 1856
            with pytest.raises(ValidationError) as SE:
                car_model = CarModel.model_validate(car_model_dict)
                await car_model.insert(session=session)
            print(f"exception: {SE.value.__class__.__name__} raised.  Other Info: {str(SE.value)}")

@pytest.mark.asyncio
async def test_tooLongString_CarModel(init):
    """
    Make the model name too long.
    :param init: The fixture to create the connection to the database.
    :return: None
    """
    new_client = await init
    car_model_dict = test_CarModel.__dict__
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            # Put in a model year that predates Henry Ford.
            car_model_dict["modelName"] = 'abc'
            with pytest.raises(ValidationError) as SE:
                car_model = CarModel.model_validate(car_model_dict)
                await car_model.insert(session=session)
            print(f"exception: {SE.value.__class__.__name__} raised.  Other Info: {str(SE.value)}")


@pytest.mark.asyncio
async def test_orphan(init):
    """
    This is more of a demonstration than it is an actual test.  There are no consequences in MongoDB
    or Beanie when a referenced document is deleted.  There is no cascade delete feature either.  One
    argument in favor of using embedding rather than referencing.  With referencing, every time that
    you add a new collection as a child to some other collection, the code that you use for deleting
    from that parent collection has to be updated.
    :param init:
    :return:
    """
    new_client = await init
    async with await new_client.start_session() as session:
        async with session.start_transaction():
            await test_Manufacturer.insert(session = session)
            await test_CarModel.insert(session = session)
            try:
                await test_Manufacturer.delete()
                # Ideally, we should never get here, Beanie should throw an exception.  But it does not,
                # so the test "fails".
                assert 1 == 0
            except Exception as orphan:
                await session.abort_transaction()
                print(f"exception: {orphan.__class__.__name__} raised.  Other Info: {str(orphan)}")
            await test_CarModel.delete(session=session)
            await test_Manufacturer.delete(session=session)
