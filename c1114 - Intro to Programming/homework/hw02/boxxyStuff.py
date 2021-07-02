
'''
cs1114

Submission: hw02
Programmer: Marisa Clardy
'''

import lineOcharStuff

def drawBox( word, surroundingSymbol = 'X', padding = 2, fillSymbol = ' ' ):
	'''
PARAMETERS:
		word					-> string
		surroundingSymbol		-> string; default: 'X'
		padding					-> int; default: 2
		fillSymbol				-> string; default: ' '
RETURNS:
		none
DESCRIPTION:
		Displays the word in a box to the screen, using the strings given
'''
	widthOfBox = 2 + len( word ) + padding * 2
	lineOcharStuff.drawLine( widthOfBox, surroundingSymbol )
	lineOcharStuff.drawLineWithEndpoints( widthOfBox, fillSymbol, surroundingSymbol )
	lineOcharStuff.drawLineWithCenteredText( word, surroundingSymbol, padding, fillSymbol )
	lineOcharStuff.drawLineWithEndpoints( widthOfBox, fillSymbol, surroundingSymbol )
	lineOcharStuff.drawLine( widthOfBox, surroundingSymbol )

def drawSolidBox( symbol = "Z", width = 6, height = 4 ):
	'''
PARAMETERS:
		symbol					-> string; default: 'Z'
		width					-> int; default: 6
		height					-> int; default: 4
RETURNS:
		none
DESCRIPTION:
		Displays a solid box with given height, width made out of a symbol
'''
	print (symbol * width + "\n") * height
