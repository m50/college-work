'''
cs1114

Submission: rec04

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Deals with money
Just a module, does not run
'''

PESO_TO_DOLLAR_CONVERSION_RATE = 0.078
DOLLAR = 100
QUARTER = 25
DIME = 10
NICKEL = 5
PENNY = 1

def printAsUSDollars( amountUSD, pref ):
	'''
PARAMETERS:
		amountUSD 			-> Float
		pref				-> String
RETURNS:
		none
DESCRIPTION:
		displays a value of US currency on the screen. Takes in a
		preface of what symbol to use
	'''
	print( pref + "%.2f" % round( amountUSD, 2 ) )

def convertPesosToUSDollars( amountPESO ):
	'''
PARAMETERS:
		amountPESO 			-> Float
RETURNS:
		dollarAmount 		-> Float
DESCRIPTION:
		Converts a peso amount to US Dollars
	'''
	dollarAmount = amountPESO * PESO_TO_DOLLAR_CONVERSION_RATE
	return dollarAmount

def calculateCoins( amountUSD ):
	'''
PARAMETERS:
		amountUSD 			-> Float
RETURNS:
		numPenny 			-> Int
		numNickel			-> Int
		numDime	 			-> Int
		numQuarter	 		-> Int
		numDollarCoin 			-> Int
DESCRIPTION:
		Calculates how many of each coin
	'''
	curUSD = amountUSD * DOLLAR
	numDollarCoin = int( curUSD / DOLLAR )
	curUSD -= numDollarCoin * DOLLAR
	numQuarter = int( curUSD / QUARTER )
	curUSD -= numQuarter * QUARTER
	numDime = int( curUSD / DIME )
	curUSD -= numDime * DIME
	numNickel = int( curUSD / NICKEL )
	curUSD -= numNickel * NICKEL
	numPenny = int( curUSD / PENNY )
	return numPenny, numNickel, numDime, numQuarter, numDollarCoin

def printAsCoins( penny, nickel, dime, quarter, dollarCoin ):
	'''
PARAMETERS:
		penny	 			-> Int
		nickel	 			-> Int
		dime	 			-> Int
		quarter	 			-> Int
		dollarCoin 			-> Int
RETURNS:
		none
DESCRIPTION:
		Displays the number of each coin
	'''
	print( "%d Dollar Coin(s)\n%d quarter(s)\n%d dime(s)\n%d nickel(s)\n%d penny(ies)" % ( dollarCoin, quarter, dime, nickel, penny ) )

def quantityCoins( amountUSD ):
	'''
PARAMETERS:
		amountUSD                       ->
RETURNS:
		none
DESCRIPTION:
		Displays the total number of coins required
	'''
	penny, nickel, dime, quarter, dollarCoin = calculateCoins( amountUSD )
        return penny + nickel + dime + quarter + dollarCoin

