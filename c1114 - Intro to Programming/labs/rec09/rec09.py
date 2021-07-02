'''
cs1114

Submission: rec09

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Creates shoppingList
'''

import dealWithLists


def commandHandler( shoppingList ):
	'''handles the commands'''
	menuItem = raw_input( "Hello, what would you like to buy? ").upper()
	while not menuItem == "SHOP":
		if menuItem.startswith( "I WON'T BUY" ):
			menuItem = menuItem.rsplit()[3]
			dealWithLists.deleteFromlist( shoppingList, menuItem )
		else:
			dealWithLists.addToList( shoppingList, menuItem )
		menuItem = raw_input( "Hello, what would you like to buy? ").upper()

def main( ):
	shoppingList = []
	commandHandler( shoppingList )
	dealWithLists.displayList( shoppingList )



if __name__ == '__main__':
	main()
