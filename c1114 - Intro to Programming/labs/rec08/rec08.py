'''
cs1114

Submission: rec08

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Stamp machine
'''

STAMP_ONE = 74
STAMP_TWO = 32
STAMP_THREE = 06

import tshirtContest
import Money

def printSplashScreen():
	'''prints a splash screen'''
	print ''' --------------------------------------------
|	  Welcome to the snakeStamp Machine!	 |
| We dispense only %d, %d and %d cent stamps. |
| We give only coins in change - (no bills). |
 --------------------------------------------''' % (STAMP_ONE, STAMP_TWO, STAMP_THREE)

def getPersonalInformation():
	'''gets the users name'''
	firstName = raw_input( "What is your first name? " )
	lastName = raw_input( "What is your last name? " )
	return firstName, lastName

def getCustomerRequests():
	'''gets the customer information'''
	nStmp1 = int(raw_input( "How many %d cent stamps would you like? " % STAMP_ONE))
	nStmp2 = int(raw_input( "How many %d cent stamps would you like? " % STAMP_TWO))
	nStmp3 = int(raw_input( "How many %d cent stamps would you like? " % STAMP_THREE))
	return nStmp1, nStmp2, nStmp3

def dealWithCustomer( fName, lName, nCoins, nStmps ):
	nStmp1, nStmp2, nStmp3 = getCustomerRequests()
	if nStmps < nStmp1 + nStmp2 + nStmp3:
		print "Sorry, no more stamps"
		return 0, 0
	totalCost = nStmp1 * STAMP_ONE / 100.0 + nStmp2 * STAMP_TWO / 100.0 + nStmp3 * STAMP_THREE / 100.0
	print "The price of your %d stamps is $%.2f" % (nStmp1 + nStmp2 + nStmp3, totalCost)
	totalRecieved = int( raw_input( "How many dollars will you be giving us? " ) )
	while totalRecieved < totalCost:
		print "Not acceptable"
		totalRecieved = int( raw_input( "How many dollars will you be giving us? " ) )
	nPen, nNic, nDim, nQua, nDol = Money.calculateCoins( totalRecieved - totalCost )
	if nPen + nNic + nDim + nQua + nDol > nCoins:
		print "Sorry, no more coins"
		return 0, 0
	print "Thank you, Just a moment please..."
	print "Thanks " + fName + " " + lName + ", your change is:"
	if nDol > 0: print "%d dollar coin(s)" % nDol
	if nQua > 0: print "%d quarter(s)" % nQua
	if nDim > 0: print "%d dime(s)" % nDim
	if nNic > 0: print "%d nickel(s)" % nNic
	if nPen > 0: print "%d Penny(ies)" % nPen
	print '''-======================================-
- Thank you for using our stamp machine -
-=======================================-'''
	print "You have been selected to win a prize!"
	print tshirtContest.definePrize(nDol, nQua, nDim, nPen)
	return nDol + nQua + nDim + nPen + nNic, nStmp1 + nStmp2 + nStmp3

def showCurrentCoins( nCoins ):
	print "Number of coins: " + str(nCoins)

def addStampsAndCoins( ):
	nCoins = int( raw_input( "How many coins do you want to add? " ) )
	nStamps = int( raw_input( "How many stamps do you want to add? " ) )
	return nCoins, nStamps

def main():
	nCoins = 100
	nStamps = 100

	printSplashScreen()
	while True:
		fName, lName = getPersonalInformation()
		if fName.upper() == "MANAGER":
			inp = raw_input( "Do you want to end the program?(y/n) " ).upper()
			if inp == "Y":
				break
			else:
				showCurrentCoins( nCoins )
				aCoins, aStamps = addStampsAndCoins( )
				nCoins += aCoins
				nStamps += aStamps
		else:
			sCoins, sStamps = dealWithCustomer( fName, lName, nCoins, nStamps )
			nCoins -= sCoins
			nStamps -= sStamps
		raw_input( "Press <ENTER> to end..." )



if __name__ == '__main__':
	main()
