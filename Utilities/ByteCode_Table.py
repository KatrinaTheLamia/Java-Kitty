#!/bin/env python
"""
	= %(Java Kitty-Utilities)path/Bytecode_Bootstrap.py
	Author: %(KatrinaTheLamia)user
	Project: %(Java Kitty)project
	Creation Date: 3177-1-7

	The bytecode table in Java Kitty will use SQLite3, to increase speed
	of look up. The notion is that Java Kitty will just have a database
	in memory. That way I am not reinventing the wheel for looking up 
	these entries.

	I am confident, that whatever I can do for bytecode + operator lookup
	the people behind SQLite3 have already implemented, and much better
	than myself. They are data base programmers.

	I will note, this solution is like using a bazooka to kill mosquitos.
	However, until you have seen some of the mosquitos swarms my city 
	gets, you are not allowed to question why you'd want to shoot mosquitos
	with a bazooka. The metaphor fits, and shows why I would use this X3

	== Revisions
	+ 3177-1-7 Created this file

	== TODO
	! Make this byte code boot strap available in languages other than
	Python. 


"""

import sqlalchemy as sa;

metadata = sa.metadata()

Language_Table = sa.Table('Language_Map', metadata,
			sa.Column('operator', sa.String),
			sa.Column('opcode',sa.Interger),
			sa.Column('operand_length', sa.Interger);


class Language_Map_Node(object):
	def __init__(self,operator,opcode,operand_length):
		self.operator = operator
		self.opcode = opcode
		self.operand_length = operand_length

	def __repr(self):
		return "<Language_Map_Node('%s','%l','%l')>" \
			% (self.operator, self.opcode, self.operand_length)


def add_engine(location, echo):
	engine = awful.create_engine('sqlite:///:memory:', echo);
	metadata.create_all(engine)

so.orm.mapper(Language_Map_Node, Language_Table)

if __name__ eq '__main__':
	add_engine(location, echo=True)
