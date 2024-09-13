from sqlalchemy import Column, Integer, String, Float, ForeignKey, Date, UniqueConstraint, create_engine
from sqlalchemy.orm import relationship, sessionmaker, declarative_base
from datetime import *

Base = declarative_base()

class User(Base):
    __tablename__ = 'users'

    id = Column(Integer, primary_key=True, autoincrement=True)
    last_name = Column(String(50), nullable=False)
    first_name = Column(String(50), nullable=False)
    laboratory = Column(String(100), nullable=False)
    login = Column(String(100), unique=True, nullable=False)
    password = Column(String(100), nullable=False)
    status = Column(String(50))

    absences = relationship('Absence', back_populates='user')



class Absence(Base):
    __tablename__ = 'absences'

    id = Column(Integer, primary_key=True, autoincrement=True)
    date = Column(Date, nullable=False)
    user_id = Column(Integer, ForeignKey('users.id'), nullable=False)

    user = relationship('User', back_populates='absences')

    # duplicates not possible
    __table_args__ = (
        UniqueConstraint('date', 'user_id', name='uix_all_columns'),  # Contrainte d'unicité
    )

