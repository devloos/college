from beanie import Document, Link
from pydantic import Field
from building import Building


class Office(Document):
    id: int = Field(..., alias="_id")
    building: Link[Building]

    class Settings:
        is_root = True
        name = 'offices'

    def __str__(self):
        return f"Office - id: {self.id} Building: {self.building}"
