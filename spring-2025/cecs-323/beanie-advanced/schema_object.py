from beanie import Document, Indexed, Link
from beanie import Document, Indexed, Link, BeanieObjectId
from pydantic import Field, ConfigDict, AfterValidator, field_validator
from datetime import datetime
from datetime import datetime
from pymongo import IndexModel, ASCENDING


class SchemaObject(Document):
    class Settings:
        name = 'schema_objects'
        indexes = [
            IndexModel(
                [('name', ASCENDING), ('schema_name', ASCENDING)], unique=True, name='schema_object_pk'
            )
        ]

    model_config = ConfigDict(extra='forbid')
    name: str = Field(alias='name', min_length=5, max_length=64)
    description: str = Field(alias='description')
    createdAt: datetime = Field(alias='created_at')
    schemaName: str = Field(alias='schema_name')

    @field_validator("description", mode='before')
    def description_validation(cls, description: str) -> str:
        if len(description) < 10:
            raise ValueError('Description must be longer than 10 characters')

        return description

    def __str__(self):
        return f'name: {self.name} description: {self.description} createdAt: {self.createdAt}'
