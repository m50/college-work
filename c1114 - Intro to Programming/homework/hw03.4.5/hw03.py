'''
cs1114

Submission: hw03

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
To Calculate the tuition cost for a student at Builtin Research Institute of NYU (BRINY-U).
'''

ONE_TIME_FEE = 100
CRED_FEE = 30
FULL_TIME_TUITION = 14000
FULL_TIME_CREDITS = 12
EXTRA_COST_CREDITS = 20
EXTRA_COST = 800
PART_TIME_COST = 900
REMEDIAL_COST = 3000

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

def main( ):
	displayLogo()
	firstName, lastName, idNum, gender = promptPersonalInfo( )
	remedCourses, numCredits = promptCreditInfo( )
	displayLogo()
	tuition, fee, totalOwe = calculateCost( remedCourses, numCredits )
	displayCost( firstName, lastName, idNum, gender, tuition, fee, totalOwe )
	raw_input( "Press the Enter key to continue..." )

if __name__ == "__main__":
    main()
