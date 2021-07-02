import colourStuff

def definePrize( numDollars, numQuarters, numDimes, numPennies ):
	'''defines the prize based on how many coins
	numDollars, numQuarters, numDimes and numPennies are all int'''
	if numDollars == 1 and numDimes == 1 and numPennies == 3 and numQuarters == 0:
		return "You win $4,200,447.28"
	elif (numDollars == 2 and numQuarters == 2 and numPennies == 4 and numDimes == 0)\
		or (numDollars == 3 and numQuarters == 1 and numPennies == 2 and numDimes == 0):
		return "You win a " + colourStuff.pickRandomColour( ) + " t-shirt!"
	elif (numQuarters == 1 and numPennies == 1 and numDollars == 0 and numDimes == 0) \
			or (3 <= numDimes <= 7 and numDollars == 0 and numPennies == 0 and numQuarters == 0):
		return "You win $10"
	else:
		return "You win $0.02"