'''
cs1114

Submission: rec09

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Menu version of creating shopping lists
'''

import dealWithLists

MENU_ITEMS = ["Add a food item to the shopping list.", "Set disallowed food items.", "Quit and print shopping list."]
MENU_COMMANDS = ["add", "disallowed","shop" ]

def menuHandler( shoppingList ):
	'''handles the commands'''
	print "Choose a menu item numericly."
	for n in range(len(MENU_ITEMS)):
		print str(n) + ") " + MENU_ITEMS[n]
	menuItem = int( raw_input( "> ") )
	while True:
		if menuItem == MENU_COMMANDS.index("shop"):
			break
		elif menuItem == MENU_COMMANDS.index("disallowed"):
			removeLoop( shoppingList )
		elif menuItem == MENU_COMMANDS.index('add'):
			addFoodItems( shoppingList )
		menuItem = int( raw_input('> ') )

def addFoodItems( shoppingList ):
	'''Adds items to the shopping list'''
	dealWithLists.addToList( shoppingList, raw_input("What Item would you like to add? ") )

def removeLoop( shoppingList ):
	'''removes items from the shoppinglist in a loop fashion'''
	whatToDelete = raw_input("What would you like to delete? (Type DONE when finished)\n")
	while not whatToDelete == "DONE":
		dealWithLists.deleteFromlist( shoppingList, whatToDelete )
		whatToDelete = raw_input("What would you like to delete? (Type DONE when finished)\n")

def main( ):
	shoppingList = []
	menuHandler( shoppingList )
	dealWithLists.displayList( shoppingList )

if __name__ == '__main__':
	main()
