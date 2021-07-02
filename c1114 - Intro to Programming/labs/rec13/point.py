class Point:
	def __init__(self, x=0, y=0):
		'''
		x - the x position; default = 0
		y - the y position; default = 0
		'''
		if type(x) != float and type(x) != int:
			raise TypeError("X not of appropriate type, must be float or int")
		elif type(y) != float and type(y) != int:
			raise TypeError("Y not of appropriate type, must be float or int")
		elif (type(y) != float and type(y) != int) and (type(x) != float and type(x) != int):
			raise TypeError("X and Y not of appropriate types, must be float or int")
		else:
			self.__x = x
			self.__y = y

	def get(self):
		'''Returns a Tuple containing the x and y position'''
		return (self.__x, self.__y)

	def X(self):
		return self.__x

	def Y(self):
		return self.__y

	def __str__(self):
		'''returns the position in string form'''
		return "(%.5f, %.5f)" % (self.__x, self.__y)

	def __add__(self, other):
		return Point(self.__x + other.__x, self.__y + other.__y)

	def __mul__(self, other):
		if isinstance(other, self.__class__):
			return Point(self.__x * other.__x, self.__y * other.__y)
		elif isinstance(other, float):
			return Point(self.__x * other, self.__y * other)
		elif isinstance(other, int):
			return Point(self.__x * other, self.__y * other)
		elif isinstance(other, long):
			return Point(self.__x * other, self.__y * other)
		else:
			raise TypeError("unsupported operant type(s)")

	def __sub__(self, other):
		return Point(self.__x - other.__x, self.__y - other.__y)

	def __div__(self, other):
		return Point(float(self.__x) / other.__x, float(self.__y) / other.__y)

	def __eq__(self, other):
		return self.__x == other.__x and self.__y == self.__y