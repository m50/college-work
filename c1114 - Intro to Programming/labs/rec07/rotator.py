CLOCKWISE = 1
COUNTERCLOCKWISE = -1

def rotateThese( var1, var2, var3, direction = 1 ):
	'''rotates variables'''
	if direction == 1:
		return var3, var1, var2
	elif direction == -1:
		return var2, var3, var1
	else:
		print "not a proper direction"
		return 0, 0, 0