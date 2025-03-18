from orm_base import Base
from sqlalchemy import UniqueConstraint, ForeignKey, Date
from sqlalchemy.orm import Mapped, mapped_column, relationship
from datetime import datetime


class NurseShift(Base):
    __tablename__ = "nurse_shifts"

    shift: Mapped["Shift"] = relationship(back_populates="nurses")

    shiftName: Mapped[str] = mapped_column(
        'shift_name', ForeignKey("shifts.name"), primary_key=True)

    nurse: Mapped["Nurse"] = relationship(back_populates="shifts")

    employeeId: Mapped[int] = mapped_column(
        'employee_id', ForeignKey("nurses.employee_id"), primary_key=True)

    shiftDate: Mapped[Date] = mapped_column(
        'shift_date', Date, nullable=False)

    def __init__(self, nurse, shift, shift_date: datetime):
        self.nurse = nurse
        self.shift = shift
        self.employeeId = nurse.employeeId
        self.shiftName = shift.name
        self.shiftDate = shift_date

    def __str__(self):
        return f"Nurse shift - nurse: {self.nurse} shift: {self.shift}"
