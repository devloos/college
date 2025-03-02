from typing import List
from starter import Base
from sqlalchemy import String, PrimaryKeyConstraint, DateTime, CheckConstraint
from sqlalchemy.orm import Mapped, mapped_column, validates, relationship
from datetime import datetime


class Schema(Base):
    __tablename__ = 'schemas'

    name: Mapped[str] = mapped_column(
        'name', String(64), CheckConstraint("LENGTH(name) > 5", name='schema_name_min_length'), nullable=False
    )
    description: Mapped[str] = mapped_column('description', String(128), nullable=False)
    createdAt: Mapped[datetime] = mapped_column('created_at', DateTime, nullable=False)

    schemaObjects: Mapped[List['SchemaObject']] = relationship(  # type: ignore
        back_populates='schema', passive_deletes='all'
    )

    PrimaryKeyConstraint(name, name="schemas_pk_01")

    def __init__(self, name: str, description: str, createdAt: datetime, **kwargs):
        super().__init__(**kwargs)
        self.name = name
        self.description = description
        self.createdAt = createdAt

    @validates("description")
    def validate_description(self, key, description: str):
        if len(description) < 10:
            raise ValueError('Description must be longer than 10 characters')

        return description

    def __str__(self):
        return f'name: {self.name} description: {self.description} createdAt: {self.createdAt}'
