'''
cs1114

Submission: rec13

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:

'''

from point import Point
from quadrant import Quadrant
from lineseg import LineSegment

def getOnePt(fl):
	ss = fl.readline().split()
	return Point(float(ss[0]), float(ss[1]))

def segments(fl):
	pts = []
	for n in fl:
		ss = n.split()
		pts.append(Point(float(ss[0]), float(ss[1])))
	lnSegs = []
	for a in pts:
		for n in pts:
			if n.X() == a.X() and n.Y() != a.Y():
					lnSegs.append(LineSegment(n, a))
	return lnSegs

def produceLnSegFile(flName, segments):
	fl = open(flName, 'w')

	for n in segments:
		fl.write(str(n) + '\n')

	fl.close()

def createQuadrants(fl):
	q1 = Quadrant('I')
	q2 = Quadrant('II')
	q3 = Quadrant('III')
	q4 = Quadrant('IV')
	for n in fl:
		ss = n.split()
		q1 + Point(float(ss[0]), float(ss[1]))
		q2 + Point(float(ss[0]), float(ss[1]))
		q3 + Point(float(ss[0]), float(ss[1]))
		q4 + Point(float(ss[0]), float(ss[1]))
	return q1, q2, q3, q4

def main():
	pt = Point(3,5)
	pt2 = Point(9,5)
	pt3 = pt + pt2
	pt4 = pt * 3
	print pt
	print pt2
	print pt3
	print pt4

	pts = open("pts000.pts", 'r')
	pt5 = getOnePt(pts)
	pts.close()
	#print pt5

	pts = open("pts003.pts", 'r')
	q1, q2, q3, q4 = createQuadrants(pts)
	pts.close()
	pts = open("pts003.pts", 'r')
	lns = segments(pts)
	pts.close()
	produceLnSegFile("linesegs.lise", lns)
	print q1
	print q2
	print q3
	print q4


if __name__ == '__main__':
	main()
