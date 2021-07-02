

def printRandomStringLine( fillCharacter = '<' ):
	'''prints a line with random characters, 30 characters long'''
	randString = str(chr(random.randint( 97, 122 ))) * random.randint( 4, 6 )
	randString += str(chr(random.randint( 97, 122 ))) * random.randint( 4, 6 )
	randString += str(chr(random.randint( 97, 122 ))) * random.randint( 4, 6 )
	randString += str(chr(random.randint( 97, 122 ))) * random.randint( 4, 6 )
	randString += str(chr(random.randint( 97, 122 ))) * random.randint( 4, 6 ) * random.randint( 0, 1 )
	randString += fillCharacter * (30-len(randString))
	print randString