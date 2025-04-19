from beanie import init_beanie, PydanticObjectId
from beanie.odm.operators.find.logical import And
from motor.motor_asyncio import AsyncIOMotorClient


from instructor import Instructor
from part_time_instructor import PartTimeInstructor
from building import Building
from full_time_instructor import FullTimeInstructor
from shared_office import SharedOffice
from single_office import SingleOffice
from office import Office
import asyncio

from menu_definitions import *
# Local host installation of MongoDB.  This will have to change for Atlas.
url = "mongodb://localhost:27018/?directConnection=true&replicaSet=rs0&w=majority"
# name of the MongoDB database.
database = "Categorization"


def rollback(session):
    """
    I'm not terribly proud of this.  The only way that I've found to rollback a transaction is to throw
    an exception.  And I found I could not just make raising the RuntimeError the action in response to
    a particular menu item select.  So this method allows me to raise an exception, which then causes
    a rollback in MongoDB.  There must be a better way.
    :param session: The connection to the database.
    :return: None
    """
    raise RuntimeError("manual rollback requested")


async def next_office_id(session):
    results = await Office.find({}, session=session).sort("-_id").limit(1).to_list()

    if not results:
        latest = 0
    else:
        latest = results[0].id

    return latest + 1


async def add(sess):
    add_action: str = ''
    while add_action != add_menu.last_action():
        add_action = add_menu.menu_prompt()
        if add_action != add_menu.last_action():
            await eval(add_action)


async def delete(sess):
    delete_action: str = ''
    while delete_action != delete_menu.last_action():
        delete_action = delete_menu.menu_prompt()
        if delete_action != delete_menu.last_action():
            await eval(delete_action)


async def list_objects(sess):
    list_action: str = ''
    while list_action != list_menu.last_action():
        list_action = list_menu.menu_prompt()
        if list_action != add_menu.last_action():
            await eval(list_action)


async def select_building(session):
    building: Building = None
    while building is None:
        name = input("Enter the building name: ")
        building = await Building.find(Building.name == name).first_or_none()
    return building


async def select_office(session, cls):
    if issubclass(cls, Office):
        office: Office = None
        while office is None:
            id = int(input("Enter the office id: "))
            office = await cls.find(cls.id == id, with_children=True, session=session).first_or_none()
        return office
    else:
        raise TypeError(f"{cls.__name__} not a subclass of Office")


async def select_instructor(session, cls):
    if issubclass(cls, Instructor):
        instructor: Instructor = None
        while instructor is None:
            last_name = input("Enter the instructor's last name: ")
            first_name = input("Enter the instructor's first name: ")

            instructor = await cls.find(cls.lastName == last_name,
                                        cls.firstName == first_name,
                                        with_children=True, session=session).first_or_none()
        return instructor
    else:
        raise TypeError(f"{cls.__name__} not a subclass of Instructor")


async def prompt_instructor(session):
    last_name = input("Enter the instructor's last name: ")
    first_name = input("Enter the instructor's first name: ")
    return {'first_name': first_name, 'last_name': last_name}


async def add_instructor(session):
    instructor_dict = await prompt_instructor(session)

    type = input('Full or Part Time Instructor (full/part)[full]: ')

    new_instructor = None

    if type.lower() == 'part':
        office = await select_office(session, SharedOffice)
        instructor_dict['sharedOffice'] = office
        new_instructor = PartTimeInstructor(**instructor_dict)
    else:
        office = await select_office(session, SingleOffice)
        instructor_dict['singleOffice'] = office
        new_instructor = FullTimeInstructor(**instructor_dict)

    await new_instructor.insert(session=session)


async def add_building(session):
    name = input("Name of the new building: ")
    gridPos = input("Grid POS of the new building: ")
    new_building = Building(name=name, grid_pos=gridPos)
    await new_building.insert(session=session)


async def add_office(session):
    id = await next_office_id(session)
    building = await select_building(session)

    type = input('Shared or Single Office (shared/single)[single]: ')

    new_office: Office = None

    if type.lower() == 'shared':
        new_office = SharedOffice(id=id, building=building)
    else:
        new_office = SingleOffice(id=id, building=building)

    await new_office.insert(session=session)


async def list_buildings(session):
    buildings = await Building.find({}, with_children=True, session=session).sort(+Building.gridPos).to_list()
    for building in buildings:
        print(building)


async def list_instructors(session):
    instructors = await Instructor.find({}, with_children=True, session=session).sort(+Instructor.lastName, +Instructor.firstName).to_list()
    for instructor in instructors:
        print(instructor)


async def delete_instructor(session):
    instructor = await select_instructor(session, Instructor)
    await instructor.delete(session=session)


async def delete_building(session):
    building = await select_building(session)
    await building.delete(session=session)


async def boilerplate(session):
    """
    Stub method that you can customize to suit.  "Boilerplate" data is data that you need in the database
    that allows you to teste.  In this case, maybe you want to have a few Department instances in the
    database to start with.  You don't want to have to enter that data in.  Just remember that you only
    need to execute the boilerplate option once.
    :param session: The database connection.
    :return: None
    """
    print("Boilerplate")


async def main() -> bool:
    """
    Loop through the menu options until the user indicates that they are ending the session.  The
    reason that I took this approach is that I kept running into problems issuing the instruction
    sess.commit_transaction() or sess.rollback_transaction().  But I found that doing that
    indirectly works.  Falling out of the inner with (see below) implicitly performs a commit.
    raising an exception implicitly performs a rollback.  There is probably a better way to do this.
    Once the session ends, we have to create a new one.  I don't know whether I could have retained
    the same session and just start a new transaction or not, I took the simple approach and
    start over with a brand-new session and a new transaction within that session whenever we
    end the transaction.
    :return: A flag to show whether the user wants to exit the application.  If they end the session
    without indicating that they want to end the application, then the calling routine can loop
    again and start up a brand-new session and transaction.  If the user indicates that they want
    to exit the application, then the transaction and session terminate normally which amounts to
    an implicit commit.
    I may be able to establish the client just once, no matter how many times the user elects to
    end the transaction.  If that's the case, then these next three statements could be moved out
    of the main method.
    """
    client = AsyncIOMotorClient(url)
    db = client.get_database(database)
    """
    Be careful to add each class to the document_models list here in init_beanie.  If you forget, 
    Python will allow you to create instances of the class (assuming that you imported the 
    corresponding module), but Beanie will apparently not be aware of the proper structure 
    of the class.  I'm not sure how that works in the background.  Just don't forget.
    """
    await init_beanie(database=db,
                      document_models=[Building, FullTimeInstructor, PartTimeInstructor, Office, Instructor, SingleOffice, SharedOffice])
    main_action: str = ''
    async with await client.start_session() as sess:
        async with sess.start_transaction():
            # commit, rollback, and "exit" all need special treatment.
            while main_action != menu_main.last_action() and \
                    main_action.find('commit') == -1 and \
                    main_action.find('rollback') == -1:
                main_action = menu_main.menu_prompt()
                print('next action: ', main_action)
                if main_action != menu_main.last_action() and \
                        main_action.find('commit') == -1:
                    await eval(main_action)
    # Let the caller know how the user exited this main().
    return main_action == menu_main.last_action()

if __name__ == '__main__':
    print('Commencing')
    leave: bool = False
    while not leave:
        try:
            leave = asyncio.run(main())
            print('Successful run of main')
        except Exception as e:
            """
            One way to get here is for the user to call for a rollback.  The other way to end up 
            here is if one of the operations throws an exception of its own.  For instance, if the 
            user attempts to store a duplicate department.
            One liability with this management of exceptions is that you do not see the whole 
            stack trace.  That's good if the message of the exception itself is useful, but 
            sometimes you want more.  I suppose we could have a little menu prompt here to 
            ask whether you just want to see the str() of the exception or the whole 9 yards.
            """
            print(e)
