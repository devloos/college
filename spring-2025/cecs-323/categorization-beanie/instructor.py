from beanie import Document
from pydantic import Field


class Instructor(Document):
    lastName: str = Field(alias='last_name', min_length=4, max_length=90)
    firstName: str = Field(alias='first_name', min_length=4, max_length=90)

    class Settings:
        is_root = True
        name = 'instructors'

    def __str__(self):
        return f"Instructor - id: {self.id} last name: {self.lastName} first name: {self.firstName} "
