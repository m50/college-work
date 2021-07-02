'''
cs1114

Submission: hw02

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
A fully parameterized box displaying system, with full user controllability
'''

import boxxyStuff
import screenyStuff

def obtainUserInput( ):
	'''
PARAMETERS:
		none
RETURNS:
		firstName -> string
		lastName -> string
DESCRIPTION:
		Asks the user for personal information.
'''
	firstName = raw_input( "What is your first name?\n" )
	lastName = raw_input( "What is your last name?\n" )
	return firstName, lastName

def main( ):
	firstName, lastName = obtainUserInput( )

	boxxyStuff.drawBox( firstName, "=" )
	boxxyStuff.drawBox( lastName, "-", 4, "#" )

	boxxyStuff.drawSolidBox( "X", 15, 3 )
	screenyStuff.pause( )


if __name__ == "__main__":
    main()
