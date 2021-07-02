'''
cs1114

Submission: rec12

Programmer: Marisa Clardy

Use this as the starting point for rec11

menu driven program

code is set up to handle the
the four menu choice from rec11

there are stubs for the functions you must write

you will complete:

for Part ONE
	startUpFillWordList( )
	saveWords( )
for Part TWO
	makeHTMLfile( )
for Part THREE
	you will rewrite startUpFillWordList( ) to allow
	a user to choose the name of the file to be read
	from initially.
	you will also complete getValidStartupFilename()
	to be used in your rewrite which takes only the two
	allowed extensions: .clrs and .cpssv
'''

import random

STARTUP_FILE_NAME = "wordsWordsWords.txt"

COLORS = ("Light Slate Gray","Cadet Blue4","Dark Slate Gray4","Thistle4","Medium Slate Blue","Medium Purple4","Midnight Blue","Dark Slate Blue","Dark Slate Gray","Dim Gray","Cornflower Blue","Royal Blue4","Slate Blue4","Royal Blue","Royal Blue1","Royal Blue2","Royal Blue3","Deep Sky Blue","Deep Sky Blue2","Slate Blue","Deep Sky Blue3","Deep Sky Blue4","Dodger Blue","Dodger Blue2","Dodger Blue3","Dodger Blue4","Steel Blue4","Steel Blue","Slate Blue2","Violet","Medium Purple3","Medium Purple","Medium Purple2","Medium Purple1","Light Steel Blue","Steel Blue3","Steel Blue2","Steel Blue1","Sky Blue3","Sky Blue4","Slate Blue","Slate Blue","Slate Gray3","Violet Red","Violet Red1","Violet Red2","Deep Pink","Deep Pink2","Deep Pink3","Deep Pink4","Medium Violet Red","Violet Red3","Firebrick","Violet Red4","Maroon4","Maroon","Maroon3","Maroon2","Maroon1","Magenta","Magenta1","Magenta2","Magenta3","Medium Orchid","Medium Orchid1","Medium Orchid2","Medium Orchid3","Medium Orchid4","Purple","Purple1","Purple2","Purple3","Purple4","Dark Orchid4","Dark Orchid","Dark Violet","Dark Orchid3","Dark Orchid2","Dark Orchid1","Plum4","Pale Violet Red","Pale Violet Red1","Pale Violet Red2","Pale Violet Red3","Pale Violet Red4","Plum","Plum1","Plum2","Plum3","Thistle","Thistle3","Lavender Blush2","Lavender Blush3","Thistle2","Thistle1","Lavender","Lavender Blush","Light Steel Blue1","Light Blue","Light Blue1","Light Cyan","Slate Gray1","Slate Gray2","Light Steel Blue2","Turquoise1","Cyan","Cyan1","Cyan2","Turquoise2","Medium Turquoise","Turquoise","Dark Slate Gray1","Dark Slate Gray2","Dark Slate Gray3","Cyan3","Turquoise3","Cadet Blue3","Pale Turquoise3","Light Blue2","Dark Turquoise","Cyan4","Light Sea Green","Light Sky Blue","Light Sky Blue2","Light Sky Blue3","Sky Blue","Sky Blue2","Light Sky Blue4","Sky Blue","Light Slate Blue","Light Cyan2","Light Cyan3","Light Cyan4","Light Blue3","Light Blue4","Pale Turquoise4","Dark Sea Green4","Medium Aquamarine","Medium Sea Green","Sea Green","Dark Green","Sea Green4","Forest Green","Medium Forest Green","Spring Green4","Dark Olive Green4","Chartreuse4","Green4","Medium Spring Green","Spring Green","Lime Green","Spring Green","Dark Sea Green","Dark Sea Green3","Green3","Chartreuse3","Yellow Green","Spring Green3","Sea Green3","Spring Green2","Spring Green1","Sea Green2","Sea Green1","Dark Sea Green2","Dark Sea Green1","Green","Lawn Green","Green1","Green2","Chartreuse2","Chartreuse","Green Yellow","Dark Olive Green1","Dark Olive Green2","Dark Olive Green3","Yellow","Yellow1","Khaki1","Khaki2","Goldenrod","Gold2","Gold1","Goldenrod1","Goldenrod2","Gold","Gold3","Goldenrod3","Dark Goldenrod","Khaki","Khaki3","Khaki4","Dark Goldenrod1","Dark Goldenrod2","Dark Goldenrod3","Sienna1","Sienna2","Dark Orange","Dark Orange1","Dark Orange2","Dark Orange3","Sienna3","Sienna","Sienna4","Indian Red4","Dark Orange3","Salmon4","Dark Goldenrod4","Gold4","Goldenrod4","Light Salmon4","Chocolate","Coral3","Coral2","Coral","Dark Salmon","Salmon1","Salmon2","Salmon3","Light Salmon3","Light Salmon2","Light Salmon","Sandy Brown","Hot Pink","Hot Pink1","Hot Pink2","Hot Pink3","Hot Pink4","Light Coral","Indian Red1","Indian Red2","Indian Red3","Red","Red1","Red2","Firebrick1","Firebrick2","Firebrick3","Pink","Rosy Brown1","Rosy Brown2","Pink2","Light Pink","Light Pink1","Light Pink2","Pink3","Rosy Brown3","Rosy Brown","Light Pink3","Rosy Brown4","Light Pink4","Pink4","Lavender Blush4","Light Goldenrod4","Lemon Chiffon4","Lemon Chiffon3","Light Goldenrod3","Light Golden2","Light Goldenrod","Light Goldenrod1","Lemon Chiffon2","Lemon Chiffon","Light Goldenrod Yellow")
FORMATTING = ('b', 'i', 'u', 'bi', 'bu', 'biu')

def startUpFillWordList( wordList ):
	''' opens wordsWordsWords.txt and fills list with words from that file
		the words in that file are one per line
	'''
	fl = open(getValidStartupFilename(), "r")

	if fl.name.endswith('.txt') or fl.name.endswith('.clrs'):
		for n in fl:
			wordList.append(n.strip())
	elif fl.name.endswith('.csv'):
		for n in fl:
			ss = n.split(',')
			for a in ss:
				wordList.append(a.strip())
	elif fl.name.endswith('.cpstsv'):
		for n in fl:
			nn = n.replace(';',' ').replace(':', ' ').replace(',', ' ').replace('.', ' ')
			ss = nn.split()
			for a in ss:
				wordList.append(a.strip())

	fl.close()

def saveWords( wordList ):
	''' Store current word list into the file: wordsWordsWords.txt
		This will destroy the previous version of the file without
		making a backup.
	'''
	fl = open(getValidStartupFilename(), 'w')

	if fl.name.endswith('.txt') or fl.name.endswith('.clrs'):
		for n in wordList:
			fl.write(n + '\n')
	elif fl.name.endswith('.csv'):
		for n in wordList:
			fl.write(n + ',')
	elif fl.name.endswith('.cpstsv'):
		for n in wordList:
			fl.write(n + ';')

	fl.close()

def makeHTMLfile( wordList ):
	''' makes file: _________.html using words in wordList '''
	fn = raw_input("Enter the filename for the html file: ")
	if fn.endswith('.htm'):
		fn += 'l'
	elif not fn.endswith('.html'):
		fn += '.html'

	title = raw_input("Enter a title for the file: ")
	size = int(raw_input("Enter the title size (1-5): "))
	fl = open(fn, 'w')

	fl.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">\n')
	fl.write('<html xmlns="http://www.w3.org/1999/xhtml">\n')
	fl.write('<head>\n')
	fl.write('\t<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />\n')
	fl.write('\t<title>%s</title>\n' % (title))
	fl.write('</head>\n')
	fl.write('<body>\n')
	fl.write('\t<h%i>%s</h%i>\n' % (size, title, size))
	for n in wordList:
		fl.write('\t<font color="%s">' % (COLORS[random.randint(0, len(COLORS)-1)]))
		formatting = FORMATTING[random.randint(0, len(FORMATTING)-1)]
		if formatting.find('i') != -1:
			fl.write('<i>')
		if formatting.find('b') != -1:
			fl.write('<b>')
		if formatting.find('u') != -1:
			fl.write('<u>')
		fl.write(n)
		if formatting.find('i') != -1:
			fl.write('</i>')
		if formatting.find('b') != -1:
			fl.write('</b>')
		if formatting.find('u') != -1:
			fl.write('</u>')
		fl.write('</font>')
		fl.write('<br />\n')
	fl.write('</body>\n')
	fl.write('</html>\n')

	fl.close()



def getValidStartupFilename( ):
	''' returns the user's choice of filename
		filename must .clrs, .csv or .cpstsv extension
	'''
	fn = raw_input("Enter the name for the file to be opened: ")
	if not fn.endswith('.txt') and not fn.endswith('.clrs') and not fn.endswith('.csv') and not fn.endswith('.cpstsv'):
		fn = raw_input("Invalid extension, must be '.txt', '.clrs', '.csv', or '.cpstsv'. Please try again: ")
	return fn


# -----------------------------------------------------------------------
# given code
# read and understand first
# -----------------------------------------------------------------------

def getOneWord( prompt ):
	''' prompts user with passed in prompt then enforces
		that the user types only
		one word on the line
		and returns that one word
	'''
	word = raw_input( prompt )
	while len( word.split() ) != 1:
		word = raw_input( "Just one word! Try again: " )
	return word

def addWord( wordList ):
	''' adds user's input word to wordList '''
	word = getOneWord( "Enter word to add: " )
	if word not in wordList:
		wordList.append( word.strip() )
	else:
		print "%s rejected - already in list" % word

	# teachy note:
	#        if not not wordList:
	# directly tests for empty string


def removeWord( wordList ):
	''' removes user's choice of word from list if it is there '''
	if not wordList:
		print "currently no words, can't remove"
		return
	wordToChunk = getOneWord( "Which word to remove? " )
	try:
		wordList.remove( wordToChunk )
	except ValueError:
		print wordToChunk + " is not in current list of words"
	except:
		print "Serious error has occured. Program is bailing out!"
		exit( -1 )


def showWords( wordList ):
	''' display each word in current set, one per line '''
	if not wordList:
		print "currently no words"
		return
	print "Your words are:"
	for word in wordList:
		print word

MENU_CHOICE_VALUE_POSTITION = 0
MENU_CHOICE_TEXT_POSTITION = 1
SHOW_CUR_WORDS = ( 1, "1. Display current words" )
ADD_WORD       = ( 2, "2. Add word to current list (will not allow duplicates)" )
REMOVE_WORD    = ( 3, "3. Remove word form current list" )
MAKE_HTML_FILE = ( 4, "4. Print an HTML version of words in current list (under construction)" )
SAVE_AND_EXIT  = ( 5, "5. Save current list and exit" )
MENU = ( SHOW_CUR_WORDS, ADD_WORD, REMOVE_WORD, MAKE_HTML_FILE, SAVE_AND_EXIT )
VALID_MENU_VALUE_CHOICES = ( SHOW_CUR_WORDS[ MENU_CHOICE_VALUE_POSTITION ], \
							 ADD_WORD[ MENU_CHOICE_VALUE_POSTITION ], \
							 REMOVE_WORD[ MENU_CHOICE_VALUE_POSTITION ], \
							 MAKE_HTML_FILE[ MENU_CHOICE_VALUE_POSTITION ], \
							 SAVE_AND_EXIT[ MENU_CHOICE_VALUE_POSTITION ] )
QUIT_CHOICE = SAVE_AND_EXIT[ MENU_CHOICE_VALUE_POSTITION ] - 1

def displayMenu():
	''' prints menu on screen '''
	print "\n\nrec11 MENU\nPlease choose from the following:\n"
	for menuLine in MENU:
		print menuLine[ MENU_CHOICE_TEXT_POSTITION ]

def getValidMenuChoice():
	''' returns a valid menu choice '''
	displayMenu()
	choice = raw_input( "Enter menu choice (just the number, please): " )
	while not choice.isdigit() \
		  or \
		  int(choice) not in VALID_MENU_VALUE_CHOICES:
		print "Not a valid menu choice."
		displayMenu()
		choice = raw_input( "Enter menu (just the number, please): " )
	return int( choice ) - 1

def handleMenuChoice( choice, wordList ):
	''' calls function to handle a valid menu choice
		assumes ch is valid
	'''
	print

	if   MENU[ choice ] == ADD_WORD:
		addWord( wordList )

	elif MENU[ choice ] == REMOVE_WORD:
		removeWord( wordList )

	elif MENU[ choice ] == MAKE_HTML_FILE:
		makeHTMLfile( wordList )

	elif MENU[ choice ] == SHOW_CUR_WORDS:
		showWords( wordList )

	elif MENU[ choice ] == SAVE_AND_EXIT:
		saveWords( wordList )
		print "Your words are saved in file " + STARTUP_FILE_NAME
		print "Thanks for using this program"

	else: # SERIOUS PROBLEM
		print "program is exiting due to menu error"
		exit( 1 )

def getAndHandleMenuChoice( wordList ):
	''' processes wordList based on menu choice '''
	mChoice = getValidMenuChoice()
	handleMenuChoice( mChoice, wordList )
	return mChoice

def main():

	print
	print

	wordList = [ ]
	startUpFillWordList( wordList )

	menuChoice = getAndHandleMenuChoice( wordList )
	while menuChoice != QUIT_CHOICE:
		menuChoice = getAndHandleMenuChoice( wordList )

	print
	print

# are we being executed?
if __name__ == '__main__':
	main()
