from starter import Base
from sqlalchemy import String, PrimaryKeyConstraint, ForeignKey, DateTime, ForeignKeyConstraint, CheckConstraint
from sqlalchemy.orm import Mapped, mapped_column, validates, relationship
from datetime import datetime
from schema import Schema


class SchemaObject(Base):
    __tablename__ = 'schema_objects'

    schema: Mapped[Schema] = relationship(back_populates='schemaObjects')
    schemaName: Mapped[str] = mapped_column(
        String(64), ForeignKey('schemas.name'), nullable=False)

    name: Mapped[str] = mapped_column(
        'name',
        String(64),
        CheckConstraint("LENGTH(name) > 5", name='schema_object_name_min_length'),
        nullable=False
    )
    description: Mapped[str] = mapped_column('description', String(128), nullable=False)
    createdAt: Mapped[datetime] = mapped_column('created_at', DateTime, nullable=False)

    PrimaryKeyConstraint(schemaName, name, name="schema_objects_pk_01")

    __table_args__ = (
        ForeignKeyConstraint([schemaName], [Schema.name], name='schema_name_fk_01'),
    )

    def __init__(self, schemaName: str, name: str, description: str, createdAt: datetime, **kwargs):
        super().__init__(**kwargs)
        self.schemaName = schemaName
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
