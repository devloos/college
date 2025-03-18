import logging
from pprint import pprint
from sqlalchemy import select

from menu_definitions import menu_main, add_menu, delete_menu, list_menu, debug_select
from db_connection import engine, Session
from sqlalchemy.orm import Session as SessionType
from orm_base import metadata
from models.shift import Shift
from models.nurse import Nurse
from models.nurse_shift import NurseShift
from option import Option
from menu import Menu
from datetime import datetime


def add():
    add_action: str = ''
    while add_action != add_menu.last_action():
        add_action = add_menu.menu_prompt()
        exec(add_action)


def delete():
    delete_action: str = ''
    while delete_action != delete_menu.last_action():
        delete_action = delete_menu.menu_prompt()
        exec(delete_action)


def list_objects():
    list_action: str = ''
    while list_action != list_menu.last_action():
        list_action = list_menu.menu_prompt()
        exec(list_action)


def add_shift(sess: SessionType):
    """
    Prompt the user for the information for a new shift and validate
    the input to make sure that we do not create any duplicates.
    :param session: The connection to the database.
    :return:        None
    """
    is_unique_name: bool = False
    name: str = ''
    while not is_unique_name:
        name = input("Shift name--> ")
        name_count: int = sess.query(Shift).filter(Shift.name == name).count()

        is_unique_name = name_count == 0

        if not is_unique_name:
            print("We already have a shift by that name.  Try again.")

    shift = Shift(name, datetime.now(), datetime.now())

    sess.add(shift)


def add_nurse(sess: SessionType):
    """
    Prompt the user for the information for a new student and validate
    the input to make sure that we do not create any duplicates.
    :param session: The connection to the database.
    :return:        None
    """
    last_name = input("Nurse last name--> ")
    first_name = input("Nurse first name-->")
    nurse = Nurse(last_name, first_name)
    sess.add(nurse)


def add_nurse_shift(sess: SessionType):
    is_unique_nurse_shift = False

    while not is_unique_nurse_shift:
        nurse = select_nurse(sess)
        shift: Shift = select_shift(sess)
        nurse_shift_count: int = sess.query(NurseShift).filter(NurseShift.employeeId == nurse.employeeId,
                                                               NurseShift.shiftName == shift.name).count()
        is_unique_nurse_shift = nurse_shift_count == 0

        if is_unique_nurse_shift:
            nurse.add_shift(shift)
            sess.add(nurse)
        else:
            print("That nurse already has that shift.  Try again.")

    sess.flush()


def add_shift_nurse(sess: SessionType):
    is_unique_nurse_shift = False

    while not is_unique_nurse_shift:
        nurse = select_nurse(sess)
        shift: Shift = select_shift(sess)
        nurse_shift_count: int = sess.query(NurseShift).filter(NurseShift.employeeId == nurse.employeeId,
                                                               NurseShift.shiftName == shift.name).count()
        is_unique_nurse_shift = nurse_shift_count == 0

        if is_unique_nurse_shift:
            shift.add_nurse(nurse)
            sess.add(shift)
        else:
            print("That shift already has that nurse.  Try again.")

    sess.flush()


def select_nurse(sess: SessionType) -> Nurse:
    """
    Select a nurse by the employee id
    :param sess:    The connection to the database.
    :return:        The selected student.
    """
    found: bool = False
    employee_id: int = 0

    while not found:
        employee_id = int(input("Nurse's employee id--> "))
        name_count: int = sess.query(Nurse).filter(
            Nurse.employeeId == employee_id
        ).count()

        found = name_count == 1

        if not found:
            print("No nurse found by that id.  Try again.")

    nurse: Nurse = sess.query(Nurse).filter(Nurse.employeeId == employee_id).first()

    return nurse


def select_shift(sess: SessionType) -> Shift:
    """
    Select a shift by its name.
    :param sess:    The connection to the database.
    :return:        The selected student.
    """
    found: bool = False
    name: str = ''

    while not found:
        name = input("Shift's name--> ")
        name_count: int = sess.query(Shift).filter(Shift.name == name).count()

        found = name_count == 1

        if not found:
            print("No Shift found by that name.  Try again.")

    shift: Shift = sess.query(Shift).filter(Shift.name == name).first()

    return shift


def delete_nurse(sess: SessionType):
    nurse = select_nurse(sess)
    sess.delete(nurse)


def delete_shift(sess: SessionType):
    shift = select_shift(sess)
    sess.delete(shift)


def delete_nurse_shift(sess: SessionType):
    print("Prompting you for the nurse and the shift that they no longer have.")
    nurse = select_nurse(sess)
    shift = select_shift(sess)
    nurse.remove_shift(shift)


def delete_shift_nurse(sess: SessionType):
    print("Prompting you for the shift and the nurse who no longer has that shift.")

    shift = select_shift(sess)
    nurse = select_nurse(sess)
    shift.remove_nurse(nurse)


def list_nurse(sess: SessionType):
    """
    List all nurses in the database.
    :param sess:    The current connection to the database.
    :return:
    """
    nurses: list[Nurse] = list(sess.query(Nurse).order_by(
        Nurse.lastName, Nurse.firstName))
    for nurse in nurses:
        print(nurse)


def list_shift(sess: SessionType):
    """
    List all shifts in the database.
    :param sess:    The current connection to the database.
    :return:
    """
    shifts: list[Shift] = list(sess.query(Shift).order_by(Shift.name))
    for shift in shifts:
        print(shift)


def list_nurse_shift(sess: SessionType):
    """Prompt the user for the student, and then list the shifts that the nurse has.
    :param sess:    The connection to the database
    :return:        None
    """
    nurse: Nurse = select_nurse(sess)
    recs = sess.query(Nurse).join(NurseShift, Nurse.employeeId == NurseShift.employeeId).join(
        Shift, NurseShift.shiftName == Shift.name).filter(
        Nurse.employeeId == nurse.employeeId).add_columns(
        Nurse.lastName, Nurse.firstName, Shift.name).all()

    for stu in recs:
        print(
            f"Nurse name: {stu.lastName}, {stu.firstName}, Shift: {stu.name}")


def list_shift_nurse(sess: SessionType):
    """Prompt the user for the shift, then list the nurses who have that shift.
    :param sess:    The connection to the database.
    :return:        None
    """
    shift = select_shift(sess)
    recs = sess.query(Nurse).join(NurseShift, Nurse.employeeId == NurseShift.employeeId).join(
        Shift, NurseShift.shiftName == Shift.name).filter(
        Shift.name == shift.name).add_columns(
        Nurse.lastName, Nurse.firstName, Shift.name).all()

    for stu in recs:
        print(
            f"Nurse name: {stu.lastName}, {stu.firstName}, Shift: {stu.name}")


def boilerplate(sess: SessionType):
    """
    Add boilerplate data initially to jump start the testing.  Remember that there is no
    checking of this data, so only run this option once from the console, or you will
    get a uniqueness constraint violation from the database.
    :param sess:    The session that's open.
    :return:        None
    """
    shift1 = Shift('Fun Shift', datetime.now(), datetime.now())
    shift2 = Shift('Boring Shift', datetime.now(), datetime.now())

    nurse1 = Nurse('Brown', 'David')
    nurse2 = Nurse('Brown', 'Mary')
    nurse3 = Nurse('Disposable', 'Bandit')

    nurse1.add_shift(shift1)
    nurse2.add_shift(shift1)
    nurse2.add_shift(shift2)

    sess.add(shift1)
    sess.add(shift2)

    sess.add(nurse1)
    sess.add(nurse2)
    sess.add(nurse3)

    sess.flush()  # Force SQLAlchemy to update the database, although not commit


def session_rollback(sess: SessionType):
    """
    Give the user a chance to roll back to the most recent commit point.
    :param sess:    The connection to the database.
    :return:        None
    """
    confirm_menu = Menu('main', 'Please select one of the following options:', [
        Option("Yes, I really want to roll back this session", "sess.rollback()"),
        Option("No, I hit this option by mistake", "pass")
    ])
    exec(confirm_menu.menu_prompt())


if __name__ == '__main__':
    print('Starting off')
    logging.basicConfig()
    # use the logging factory to create our first logger.
    # for more logging messages, set the level to logging.DEBUG.
    # logging_action will be the text string name of the logging level, for instance 'logging.INFO'
    logging_action = debug_select.menu_prompt()
    # eval will return the integer value of whichever logging level variable name the user selected.
    logging.getLogger("sqlalchemy.engine").setLevel(eval(logging_action))
    # use the logging factory to create our second logger.
    # for more logging messages, set the level to logging.DEBUG.
    logging.getLogger("sqlalchemy.pool").setLevel(eval(logging_action))

    metadata.drop_all(bind=engine)  # start with a clean slate while in development

    # Create whatever tables are called for by our "Entity" classes.
    metadata.create_all(bind=engine)

    with Session() as sess:
        main_action: str = ''
        while main_action != menu_main.last_action():
            main_action = menu_main.menu_prompt()
            print('next action: ', main_action)
            exec(main_action)
        sess.commit()
    print('Ending normally')
