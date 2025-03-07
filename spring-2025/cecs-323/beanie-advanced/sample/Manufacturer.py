from typing import Optional, List

from beanie import Document, BackLink
from pydantic import Field, ConfigDict

class Manufacturer(Document):
    """
    A corporation dedicated to providing the public with automobiles for getting
    around town safely.
    """
    # Make sure that we cannot add any other fields to this class
    model_config = ConfigDict(extra='forbid')
    name: str = Field(alias="name", min_length=4, max_length=80)
    address: str = Field(alias="address", min_length=20, max_length=80)
    # carModels: Optional[List[BackLink['CarModel']]] = Field(original_field='manufacturer')

    class Settings:
        name = 'manufacturers'

    def __str__(self):
        return f'Manufacturer: {self.name}'