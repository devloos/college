from orm_base import Base
from sqlalchemy import Column, Integer, UniqueConstraint, Identity
from sqlalchemy import String
from sqlalchemy.orm import Mapped, mapped_column, relationship
from typing import List                 # Use this for the list of Majors that this student has
from models.nurse_shift import NurseShift
from datetime import datetime


class Nurse(Base):
    __tablename__ = "nurses"  # Give SQLAlchemy th name of the table.
    # Let SQLAlchemy handle the generation of student_id values for us.
    employeeId: Mapped[int] = mapped_column(
        'employee_id', Integer, Identity(start=1, cycle=True), primary_key=True)
    lastName: Mapped[str] = mapped_column(
        'last_name', String(50), nullable=False, primary_key=False)
    firstName: Mapped[str] = mapped_column(
        'first_name', String(50), nullable=False, primary_key=False)

    # A list of StudentMajor instances that connect this student to a list of majors.
    """We need to be able to delete the association class rows without using session.delete.
    The way that we will DISassociate a Major from a Student is to delete an instance
    of this list of StudentMajors that connects this Student to the Major that we want
    to disassociate.  But to get that to work in the database, we need to configure
    the relationship such that breaking the association at this end propagates a 
    deletion in the association table to go along with it."""
    shifts: Mapped[List["NurseShift"]] = relationship(back_populates="nurse",
                                                      cascade="all, save-update, delete-orphan")

    def __init__(self, lastName: str, firstName: str):
        self.lastName = lastName
        self.firstName = firstName

    def add_shift(self, shift):
        # Make sure that this nurse does not already have this shift.
        if shift in self.shifts:
            return

        nurse_shift = NurseShift(self, shift, datetime.now())

    def remove_shift(self, shift):
        self.shifts.remove(shift)

    def __str__(self):
        return f"Employee ID: {self.employeeId} name: {self.lastName}, {self.firstName}"
