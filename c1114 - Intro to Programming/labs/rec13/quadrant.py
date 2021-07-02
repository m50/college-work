from point import Point

class Quadrant:
	
	def __init__(self, quadrant):
		'''creates a list of points for a specific quadrant'''
		self.__pts = []
		self.__quad = quadrant

	def getQuadrant(self):
		return self.__quad

	def get(self):
		return (self.__quad, self.__pts)

	def getPts(self):
		return self.__pts

	def __add__(self, other):
		if isinstance(other, self.__class__):
			for n in other.__pts:
				self.__pts.append(n)
		elif isinstance(other, Point):
			if other.X() >= 0 and other.Y() >= 0:
				quadrant = 'I'
			elif other.X() < 0 and other.Y() >= 0:
				quadrant = 'II'
			elif other.X() < 0 and other.Y() < 0:
				quadrant = 'III'
			elif other.X() >= 0 and other.Y() < 0:
				quadrant = 'IV'
			if quadrant == self.__quad:
				self.__pts.append(other)
				return True

	def __str__(self):
		s = "Quadrant " + self.__quad + '\n'
		for n in self.__pts:
			s += "\t" + str(n) + '\n'
		return s