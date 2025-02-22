from beanie import Document, Indexed, Link
from pydantic import Field, ConfigDict, AfterValidator, field_validator
from datetime import datetime


class Schema(Document):
    class Settings:
        name = 'schemas'

    model_config = ConfigDict(extra='forbid')
    name: str = Field(alias='name')
    description: str = Field(alias='description')
    createdAt: datetime = Field(alias='created_at')

    @field_validator("description", mode='before')
    def description_validation(cls, description: str) -> str:
        if len(description) < 10:
            raise ValueError('Description must be longer than 10 characters')

        return description

    def __str__(self):
        return f'name: {self.name} description: {self.description} createdAt: {self.createdAt}'
