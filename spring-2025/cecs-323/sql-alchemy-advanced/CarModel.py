import datetime
from decimal import Decimal

from orm_base import Base
from sqlalchemy import String, Integer, DECIMAL, PrimaryKeyConstraint, ForeignKeyConstraint, CheckConstraint
from sqlalchemy.orm import Mapped, mapped_column, validates, relationship
from Manufacturer import Manufacturer


class CarModel(Base):
    """A CarModel is a product that is offered for sale by a manufacturer.  An instance
    of a CarModel can be driven by one person at a time, on roads on land, and can convey
    a small number of passengers and a small quantity of luggage.  A CarModel cannot,
    by itself, actually DO anything.  It is just an item in a manufacturer's catalog."""
    __tablename__ = 'car_models'    # Defaults to the same name as the class.  Use naming standards.
    manufacturer: Mapped[Manufacturer] = relationship(back_populates='carModels')
    manufacturerName: Mapped[str] = mapped_column('manufacturer_name', String(16),
                                                  nullable=False)
    modelName: Mapped[str] = mapped_column('model_name', String(20),
                                           CheckConstraint("LENGTH(model_name) >3",
                                                           name='car_model_name_min_length'),
                                           nullable=False)
    modelYear: Mapped[int] = mapped_column('model_year', Integer, nullable=False)
    fuelEconomyCity: Mapped[int] = mapped_column('fuel_economy_city', Integer, nullable=False)
    fuelEconomyHwy: Mapped[int] = mapped_column('fuel_economy_hwy', Integer, nullable=False)
    # This could be validated using a migrated foreign key, or an enumeration.
    transmissionType: Mapped[str] = mapped_column('transmission_type', String(10), nullable=False)
    climateControlZones: Mapped[int] = mapped_column('climate_control_zones', Integer,
                                                     nullable=False)
    rangeGasoline: Mapped[int] = mapped_column('range_gasoline', Integer, nullable=False)
    rangeElectric: Mapped[int] = mapped_column('range_electric', Integer, nullable=False)
    MSRP: Mapped[float] = mapped_column('manufacturers_suggested_retail_price',
                                        DECIMAL(precision=10, scale=2), nullable=False)
    PrimaryKeyConstraint(manufacturerName, modelName, modelYear, name="car_model_pk")

    """
    The CheckConstraint here is somewhat gratuitous just because I could have done it using 
    an inline constraint just like the car_model_name_min_length check constraint above.
    ANY check constraint can be added to __table_args__.  But only a check constraint 
    that only references ONE column in the table can be specified as an inline constraint."""
    __table_args__ = (
        ForeignKeyConstraint([manufacturerName],[Manufacturer.name],
                             name='car_model_manufacturer_fk_01'),
        CheckConstraint("manufacturers_suggested_retail_price > 10000",
                        name='car_model_MSRP_minimum'),
    )
    """
    Using a validator is better than trying to catch this sort of error in the __init__
    method since its possible to construct an instance of the CarModel class without 
    ever using the __init__ method.  You gotta love Python."""
    @validates("modelYear")
    def validate_modelYear(self, key, modelYear: int):
        """
        As the name implies, validate the modelYear field.
        :param key: This is supplied when the validator is called.  It is the name of
        the field being validated.  We essentially ignore this value in the validator
        method itself.
        :param modelYear: The value being validated.
        :return: In this case, the return value = the original value, even if it is wrong.
        One strategy, for instance, would be if the modelYear is too high, just make it
        the current year + 1 and quietly "fix" the error.  The liability there is that
        the user will have no idea that's what happened to their data.
        """
        if modelYear > datetime.datetime.now().year + 1:
            raise ValueError('Model year too far into the future')
        elif modelYear < 1914:
            raise ValueError('Model year predates Henry Ford')
        # The validator could mutate the value to make it valid, so the validator
        # MUST return the original value if the validator does not update it.
        return modelYear

    def __init__(self, manufacturer: Manufacturer, modelName: str, modelYear: int,
                 fuelEconomyCity: int, fuelEconomyHwy: int, transmissionType: str,
                 climateControlZones: int, rangeGasoline: int, rangeElectric: int,
                 MSRP: Decimal, **kwargs):
        super().__init__(**kwargs)
        self.manufacturer = manufacturer
        self.manufacturerName = manufacturer.name
        self.modelName = modelName
        self.modelYear = modelYear
        self.fuelEconomyCity = fuelEconomyCity
        self.fuelEconomyHwy = fuelEconomyHwy
        self.transmissionType = transmissionType
        self.climateControlZones = climateControlZones
        self.rangeGasoline = rangeGasoline
        self.rangeElectric = rangeElectric
        self.MSRP = MSRP

    def __str__(self):
        return f'Automobile model name:{self.modelName} model year: {self.modelYear} manufacturer: {self.manufacturerName}'
