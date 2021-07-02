'''
cs1114

Submission: hw07

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Hit && Match game

'''

import random

MIN_MAX = (1, 12)

def getUserHand( ):
	'''gets the hand from the player and returns it'''
	hand = []
	left = int( raw_input( "Enter number for left position: " ) )
	while not MIN_MAX[0] <= left <= MIN_MAX[1]:
		print "Sorry, must be between %d and %d" % (MIN_MAX[0], MIN_MAX[1])
		left = int( raw_input( "Enter number for left position: " ) )
	hand.append( left )
	mid = int( raw_input( "Enter number for middle position: " ) )
	while mid in hand or not MIN_MAX[0] <= mid <= MIN_MAX[1]:
		print "Sorry, no duplicates and must be between %d and %d" % (MIN_MAX[0], MIN_MAX[1])
		mid = int( raw_input( "Enter number for middle position: " ) )
	hand.append( mid )
	right = int( raw_input( "Enter number for right position: " ) )
	while right in hand or not MIN_MAX[0] <= right <= MIN_MAX[1]:
		print "Sorry, no duplicates and must be between %d and %d" % (MIN_MAX[0], MIN_MAX[1])
		right = int( raw_input( "Enter number for right position: " ) )
	hand.append( right )
	return hand

def generateHouseHand():
	'''randomly generates a hand'''
	hand = []
	hand.append( random.randint( MIN_MAX[0], MIN_MAX[1] ) )
	mid = random.randint( MIN_MAX[0], MIN_MAX[1] )
	while mid in hand:
		mid = random.randint( MIN_MAX[0], MIN_MAX[1] )
	hand.append( mid )
	right = random.randint( MIN_MAX[0], MIN_MAX[1] )
	while right in hand:
		right = random.randint( MIN_MAX[0], MIN_MAX[1] )
	hand.append( right )
	return hand

def calcNumHitAndMatch( playerHand, houseHand ):
	'''calculates the number of hits and matches out of the two hands
	Input: PlayerHand (list), HouseHand (list)
	Ouput: numHits (list), numMatches (list)'''
	numHits = 0
	numMatches = 0
	for card in playerHand:
		if card in houseHand:
			if houseHand.index( card ) == playerHand.index( card ):
				numHits += 1
			else:
				numMatches += 1
	return numHits, numMatches

def displayResults( playerHand, houseHand, numHits, numMatches ):
	'''displays outcome of game'''
	print
	print "---House:"
	print "    left: " + str( houseHand[0] )
	print "  middle: " + str( houseHand[1] )
	print "   right: " + str( houseHand[2] )
	print
	print "----You:"
	print "   left: " + str( playerHand[0] )
	print " middle: " + str( playerHand[1] )
	print "  right: " + str( playerHand[2] )
	print
	print "   Hits: " + str( numHits )
	print "Matches: " + str( numMatches )
	print

def displayBonusTriangle( triangleWord ):
	'''generates bonus triangle'''
	print "Congratulations!!!"
	triHeight = random.randint( 7, 11 )
	for n in range( triHeight ):
		print (triangleWord + " ") * n
	for n in range( triHeight, -1, -1):
		print (triangleWord + " ") * n

def playHitAndMatch():
	'''play the hit and match game'''
	playerHand = getUserHand()
	houseHand = generateHouseHand()
	#houseHand = [2,3,12]
	numHits, numMatches = calcNumHitAndMatch( playerHand, houseHand )

	displayResults( playerHand, houseHand, numHits, numMatches )

	if numHits == 3:
		displayBonusTriangle("Bonus")


def main():
	while True:
		playHitAndMatch()

if __name__ == '__main__':
	main()
