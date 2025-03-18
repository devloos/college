# So that we can manage the list of Students in this Major
from typing import List
from orm_base import Base
from sqlalchemy import String, ForeignKey, Date
from sqlalchemy.orm import Mapped, mapped_column, relationship
from datetime import datetime
# I have to import StudentMajor because I need to create an instance of StudentMajor
# and hence I need its constructor.  But StudentMajor canNOT import Major or that
# would create a cyclic import.
from models.nurse_shift import NurseShift


class Shift(Base):
    """A distinct field of study.  Each major has a degree program that a student
    can pursue towards a college diploma.  Many universities offer specializations
    within a major to accommodate students who have a more focused set of
    objectives for their education.  Several Departments have multiple majors.
    For instance the CECS department has both a Computer Engineering as well as
    a Computer Science major."""
    __tablename__ = "shifts"

    # The major name is unique across the entire college.  The Department is
    # NOT a namespace for the majors.  --> The relationship from Department to Major is
    # NON-identifying.  Makes it easier for the many to many since this is not a composite PK.
    name: Mapped[str] = mapped_column(
        'name', String(50), nullable=False, primary_key=True)

    startHour: Mapped[Date] = mapped_column(
        'start_hour', Date, nullable=False)

    endHour: Mapped[Date] = mapped_column(
        'end_hour', Date, nullable=False)

    """We need to be able to delete the association class rows without using session.delete.
    The way that we will DISassociate a Major from a Student is to delete an instance
    of this list of StudentMajors that connects this Major to the Student that we want
    to disassociate.  But to get that to work in the database, we need to configure
    the relationship such that breaking the association at this end propagates a 
    deletion in the association table to go along with it."""
    nurses: Mapped[List["NurseShift"]] = relationship(back_populates="shift",
                                                      cascade="all, save-update, delete-orphan")

    def __init__(self, name: str, start_hour: datetime, end_hour: datetime):
        self.name = name
        self.startHour = start_hour
        self.endHour = end_hour

    def add_nurse(self, nurse):
        if nurse in self.nurses:
            return

        nurse_shift = NurseShift(nurse, self, datetime.now())

    def remove_nurse(self, nurse):
        self.nurses.remove(nurse)

    def __str__(self):
        return f"Shift Name: {self.name}"
