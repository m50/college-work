
class HydroCarbyMolly:
	def __init__(self, nH, nC, name):
		'''initializes'''
		self._numH = nH
		self._numC = nC
		self._names = [name]

	def addName(self, name):
		'''Adds a name to the list of names'''
		self._names.append(name)

	def getName(self):
		'''returns the names'''
		return self._names

	def getNumHydrogens(self):
		'''returns the number of hydrogens'''
		return self._numH

	def getNumCarbons(self):
		'''returns the number of carbons'''
		return self._numC

	def __str__(self):
		'''casts to a string'''
		return ("C%iH%i - " % (self._numC, self._numH)) + str(self._names)

	def __eq__(self, obj):
		'''checks if two are equal'''
		return self._numH == obj._numH and self._numC == obj._numC

	def __cmp__(s, o):
		if s._numC > o._numC:
			return 1
		elif s._numC < o._numC:
			return -1
		elif s._numC == o._numC:
			if s._numH > o._numH:
				return 1
			else:
				return -1
		return 0