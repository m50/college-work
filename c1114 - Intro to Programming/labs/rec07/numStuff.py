
CANT_DIVIDE_BY_ZERO = "Nope! Can't divide by zero!"

def canNumberByDividedBy( num1, num2 ):
	'''returns true if num1 is evenly divisible by num2, else returns false.
	if num2 is 0, it will error out.
	doesn't catch if num1 or num2 aren't numerical
	'''
	if num2 == 0:
		return CANT_DIVIDE_BY_ZERO
	elif num1 % num2 == 0:
		return True
	else:
		return False
