class LineSegment:
	def __init__(self, pt1, pt2):
		self.__pt1 = pt1
		self.__pt2 = pt2

	def __str__(self):
		return "(%.5f, %.5f) -> (%.5f, %.5f)" \
			% (self.__pt1.X(), self.__pt1.Y(), self.__pt2.X(), self.__pt2.Y())