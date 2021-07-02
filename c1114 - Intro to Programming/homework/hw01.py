'''
cs1114

Submission: hw01

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
To display the name of the user in a box.
'''

import boxer
import screen

def main( ):
        	screen.clrScreen( )

	firstName, lastName = obtainUserInput( )

	boxer.drawBox( firstName )
	boxer.drawBox( firstName )

	boxer.drawBox( "By: Marisa Clardy" )

	screen.pause( )

if __name__ == "__main__":
    main()
