'''
cs1114

Submission: hw05

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
To Calculate the tuition cost for students at Builtin Research Institute of NYU (BRINY-U).
'''

ONE_TIME_FEE = 100
CRED_FEE = 30
FULL_TIME_TUITION = 14000
FULL_TIME_CREDITS = 12
EXTRA_COST_CREDITS = 20
EXTRA_COST = 800
PART_TIME_COST = 900
REMEDIAL_COST = 3000
QUIT = "END OF PROCESSING"

def promptPersonalInfo( ):
	'''
PARAMETERS:
		none
RETURNS:
		firstName 		-> string
		lastName 		-> string
		idNum 			-> int
		gender			-> string
DESCRIPTION:
		Requests the user to input the personal information about the student
'''
	lastName = raw_input( "Enter your Last Name: " )
	firstName = raw_input( "Enter your First Name: " )
	if firstName.upper() == QUIT:
		return firstName, lastName, 0, "M"
	idNum = int( raw_input( "Enter your ID number: " ) )
	gender = raw_input( "Enter your gender ('M' = male; 'F' = female): " )
	return firstName, lastName, idNum, gender

def promptCreditInfo( ):
	'''
PARAMETERS:
		none
RETURNS:
		numRemCourses	-> int
		numCredits		-> int
DESCRIPTION:
		Requests the user to input the information about his/her credit hours
'''
	strRemCour = raw_input( "Are you taking any remedial courses? ('Y' = Yes; 'N' = No) " )
	numRemCourses = 0
	if strRemCour == 'Y':
		numRemCourses = int( raw_input( "Enter the number of remedial courses that you are taking: " ) )
	numCredits = int( raw_input( "Enter the number of regular credits you are taking: " ) )
	while numCredits >= 30 or numCredits < 0:
		print "Sorry, try again."
		numCredits = int( raw_input( "Enter the number of regular credits you are taking: " ) )
	return numRemCourses, numCredits

def calculateCost( numRemCourses, numCredits ):
	'''
PARAMETERS:
		numRemCourses	-> int
		numCredits		-> int
RETURNS:
		tuition 		-> int
		fee				-> int
		totalOwe		-> int
DESCRIPTION:
		Calculates the cost of tuition and the total owed by the student
'''
	fee = ONE_TIME_FEE + CRED_FEE * (numRemCourses + numCredits)
	tuition = 0
	if numCredits >= FULL_TIME_CREDITS:
		tuition = FULL_TIME_TUITION
		if numCredits > EXTRA_COST_CREDITS:
			tuition += (numCredits - EXTRA_COST_CREDITS) * EXTRA_COST
	else:
		tuition = numCredits * PART_TIME_COST
	tuition += REMEDIAL_COST * numRemCourses
	totalOwe = tuition + fee
	return tuition, fee, totalOwe

def displayCost( firstName, lastName, idNum, gender, tuition, fee, totalOwe ):
	'''
PARAMETERS:
		tuition 		-> int
		fee				-> int
		totalOwe		-> int
RETURNS:
		none
DESCRIPTION:
		Displays the cost to the user
'''
	name = "Mr. "
	if gender == 'F':
		name = "Ms. "
	name += firstName + " " + lastName + " (%d)" % idNum
	print( name )
	print( "Your tuition is: $%d" % tuition )
	print( "Your fee is: $%d" % fee )
	print( "You owe: $%d" % totalOwe )

def displayLogo( ):
	'''
PARAMETERS:
		none
RETURNS:
		none
DESCRIPTION:
		Prints out the BRINY-U logo:
			BRBRBR-------------BRBRBR
			BRBRBR   BRINY-U   BRBRBR
			BRBRBR-------------BRBRBR
'''
	br3 = "BR" * 3
	print( "\n" )
	print( br3 + "-" * 13 + br3 )
	print( br3 + "   " + "BRINY-U" + "   " + br3 )
	print( br3 + "-" * 13 + br3 )
	print( "\n" )

def displayInstructions( ):
	'''gives instructions on how to end'''
	print "Enter the phrase: " + QUIT + " as the first name to stop processing."

def average ( total, num ):
	'''gets an average using the total amount and the number counted'''
	if num == 0:
		return 0
	return total / num

def printStats( numProcessed, totalEarned, largestOwed, percentageMale ):
	'''Prints out the statistics of the number of people'''
	averageOwed = average( totalEarned, numProcessed )
	print str(numProcessed) + " students are registered meaning we'll be getting " + str(totalEarned)
	print "The average amount owed is " + str(averageOwed)
	print "The largest amount owed by any student is " + str(largestOwed)
	print "There were %.00000f males and %.00000f females." % (percentageMale, 100 - percentageMale)

def main( ):
	numProcessed = 0
	totalEarned = 0
	largestOwed = 0
	numberMale = 0
	numberFemale = 0
	while True:
		displayLogo( )
		displayInstructions( )
		firstName, lastName, idNum, gender = promptPersonalInfo( )
		if firstName.upper() == QUIT:
			printStats( numProcessed, totalEarned, largestOwed, float( numberMale )/numProcessed * 100 )
			break
		remedCourses, numCredits = promptCreditInfo( )
		displayLogo()
		tuition, fee, totalOwe = calculateCost( remedCourses, numCredits )
		displayCost( firstName, lastName, idNum, gender, tuition, fee, totalOwe )
		numProcessed += 1
		totalEarned += totalOwe
		if totalOwe > largestOwed:
			largestOwed = totalOwe
		if gender == "M":
			numberMale += 1
		else:
			numberFemale += 1
		print "\n\n"
	raw_input( "Press the Enter key to continue..." )

if __name__ == "__main__":
    main()
