import random

def pickRandomColour(  ):
	'''
PARAMETERS:
		none
RETURNS:
		string
DESCRIPTION:
		Picks a random color from colours.
'''
	rand = random.randint( 0, 7 )
	if rand == 0:
		return "red"
	elif rand == 1:
		return "orange"
	elif rand == 2:
		return "yellow"
	elif rand == 3:
		return "green"
	elif rand == 4:
		return "blue"
	elif rand == 5:
		return "indigo"
	elif rand == 6:
		return "violet"
	elif rand == 7:
		return "black"
	
	