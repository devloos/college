from instructor import Instructor
from shared_office import SharedOffice
from beanie import Link
from pydantic import Field


class PartTimeInstructor(Instructor):
    sharedOffice: Link[SharedOffice]
