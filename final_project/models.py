from sqlalchemy import Column, Integer, String, Float, ForeignKey, DateTime, create_engine
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

    absences = relationship('Absence', back_populates='user')



class Absence(Base):
    __tablename__ = 'absences'

    id = Column(Integer, primary_key=True, autoincrement=True)
    date = Column(DateTime, nullable=False)
    id_person = Column(Integer, ForeignKey('users.id'), nullable=False)

    user = relationship('User', back_populates='absences')

