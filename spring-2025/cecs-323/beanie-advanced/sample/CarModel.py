import datetime

import pymongo
from beanie import Document, Indexed, Link, WriteRules
from pydantic import Field, ConfigDict, AfterValidator, validator, field_validator
from pymongo import IndexModel
from enum import Enum

from Manufacturer import Manufacturer


class TransmissionType(str, Enum):
    """
    Just a quick demonstration of how we can constrain a field to a small number of
    possible values in Beanie.
    """
    MANUAL = "manual"
    AUTOMATIC = "automatic"
    CV = 'continuously variable'
    DC = 'dual clutch'


class CarModel(Document):
    """A CarModel is a product that is offered for sale by a manufacturer.  An instance
    of a CarModel can be driven by one person at a time, on roads on land, and can convey
    a small number of passengers and a small quantity of luggage.  A CarModel cannot,
    by itself, actually DO anything.  It is just an item in a manufacturer's catalog."""
    model_config = ConfigDict(extra='forbid')
    manufacturer: Link[Manufacturer]
    manufacturerName: str = Field(alias='manufacturer_name')
    modelName: str = Field(alias='model_name', min_length=5, max_length=20)
    modelYear: int = Field(alias='model_year', ge=1914)
    fuelEconomyCity: int = Field(alias='fuel_economy_city')
    fuelEconomyHwy: int = Field(alias='fuel_economy_highway')
    # This could be validated using a migrated foreign key, or an enumeration.
    transmissionType: TransmissionType = Field(alias='transmission_type')
    climateControlZones: int = Field(alias='climate_control_zones', ge=1, le=4)
    rangeGasoline: int = Field(alias='range_gasoline')
    rangeElectric: int = Field(..., alias='range_electric')
    MSRP: float = Field(alias='manufacturers_suggested_retail_price')

    class Settings:
        # stipulate the name of the collection for this class.
        name = 'car_models'
        indexes = [
            IndexModel(
                [('manufacturer_name', pymongo.ASCENDING),
                 ('model_name', pymongo.ASCENDING),
                 ('model_year', pymongo.ASCENDING)
                 ], unique=True, name='car_models_pk')
        ]
        write_rules = {"parent": WriteRules.DO_NOTHING}

    @field_validator("modelYear", mode='before')
    def model_year_validation(cls, modelYear: int) -> int:
        """
        As the name implies, validate the modelYear field.
        :param modelYear: The value being validated.
        :return: In this case, the return value = the original value, even if it is wrong.
        One strategy, for instance, would be if the modelYear is too high, just make it
        the current year + 1 and quietly "fix" the error.  The liability there is that
        the user will have no idea that's what happened to their data.

        I intentionally REMOVED the check on the modelYear MINIMUM and put that into
        the Field specification for ModelYear.
        """
        if modelYear > datetime.datetime.now().year + 1:
            raise ValueError('Model year too far into the future')
        # The validator COULD mutate the value to make it valid, so the validator
        # MUST return the original value if the validator does not update it.
        return modelYear

    def __str__(self):
        return f'Automobile model name:{self.modelName} model year: {self.modelYear} manufacturer: {self.manufacturerName}'
