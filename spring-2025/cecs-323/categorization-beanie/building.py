import pymongo
from beanie import Document
from pydantic import Field, ConfigDict
from pymongo import IndexModel


class Building(Document):
    model_config = ConfigDict(extra='forbid')   # Prohibit gratuitous fields
    name: str = Field(alias="name", min_length=3, max_length=80)
    gridPos: str = Field(alias='grid_pos', min_length=2, max_length=2)

    class Settings:
        name = 'buildings'
        # indexes = [
        #     IndexModel([('abbreviation', pymongo.ASCENDING)],
        #                unique=True, name='departments_pk'),
        #     IndexModel([('name', pymongo.ASCENDING)],
        #                unique=True, name='departments_uk_01')
        # ]

    def __str__(self):
        return f"Building - name: {self.name} Grid POS: {self.gridPos}"
