from menu import Menu
from option import Option
"""
This little file just has the menus declared.  Each variable (e.g. menu_main) has 
its own set of options and actions.  Although, you'll see that the "action" could
be something other than an operation to perform.

Doing the menu declarations here seemed like a cleaner way to define them.  When
this is imported in main.py, these assignment statements are executed and the 
variables are constructed.  To be honest, I'm not sure whether these are global
variables or not in Python.
"""

menu_main = Menu('main', 'Please select one of the following options:', [
    Option("Add", "add()"),
    Option("List", "list_objects()"),
    Option("Delete", "delete()"),
    Option("Boilerplate Data", "boilerplate(sess)"),
    Option("Commit", "sess.commit()"),
    Option("Rollback", "session_rollback(sess)"),
    Option("Exit this application", "pass")
])

add_menu = Menu('add', 'Please indicate what you want to add:', [
    Option("Nurse", "add_nurse(sess)"),
    Option("Shift", "add_shift(sess)"),
    Option("Nurse to Shift", "add_nurse_shift(sess)"),
    Option("Shift to Nurse", "add_shift_nurse(sess)"),
    Option("Exit", "pass")
])

delete_menu = Menu('delete', 'Please indicate what you want to delete from:', [
    Option("Nurse", "delete_nurse(sess)"),
    Option("Shift", "delete_shift(sess)"),
    Option("Nurse to Shift", "delete_nurse_shift(sess)"),
    Option("Shift to Nurse", "delete_shift_nurse(sess)"),
    Option("Exit", "pass")
])

list_menu = Menu('list', 'Please indicate what you want to list:', [
    Option("Nurse", "list_nurse(sess)"),
    Option("Shift", "list_shift(sess)"),
    Option("Nurse to Shift", "list_nurse_shift(sess)"),
    Option("Shift to Nurse", "list_shift_nurse(sess)"),
    Option("Exit", "pass")
])

# A menu to prompt for the amount of logging information to go to the console.
debug_select = Menu('debug select', 'Please select a debug level:', [
    Option("Informational", "logging.INFO"),
    Option("Debug", "logging.DEBUG"),
    Option("Error", "logging.ERROR")
])
