from instructor import Instructor
from single_office import SingleOffice
from beanie import Link
from pydantic import Field


class FullTimeInstructor(Instructor):
    singleOffice: Link[SingleOffice]
