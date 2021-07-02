def deleteFromlist( lst, item ):
	'''deltes an item from a list'''
	lst.remove(item)

def addToList( lst, item ):
	'''adds and item to a list'''
	lst += [item]

def displayList( lst ):
	'''displays items in list'''
	for n in lst:
		print n