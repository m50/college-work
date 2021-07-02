
'''
cs1114

Submission: hw02
Programmer: Marisa Clardy
'''

def drawLineWithEndpoints( length, symbol, endPointSymbol ):
	'''
PARAMETERS:
		length 				-> int
		symbol		 		-> string
		endPointSymbol		-> string
RETURNS:
		none
DESCRIPTION:
		Draws a line with symbols.
	'''
	print( endPointSymbol + symbol * (length - 2) + endPointSymbol )



def drawLine( length, symbol ):
	'''
PARAMETERS:
		length 				-> int
		symbol		 		-> string
RETURNS:
		none
DESCRIPTION:
		Draws a line with symbols with no special endpoint symbol
	'''
	drawLineWithEndpoints( length, symbol, symbol )



def drawLineWithCenteredText( text, endPointSymbol, padding = 2, paddingSymbol = ' ' ):
	'''
PARAMETERS:
		text 				-> string
		endPointSymbol		-> string
		padding				-> int; default: 2
		paddingSymbol		-> string; default: ' '
RETURNS:
		none
DESCRIPTION:
		Draws a symbol line with text centered inside of it.
	'''
	print( endPointSymbol + paddingSymbol * padding + text + paddingSymbol * padding + endPointSymbol )
