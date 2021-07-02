'''
cs1114

Submission: hw06

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
sorts out what elements are shared between two lists

'''

def getCommonElements( list1, list2 ):
	'''takes the common elements between list1 and list2 and returns it as a new list'''
	list3 = []
	for n in list1:
		if n in list2 and n not in list3:
			list3.append(n)
	return list3


def main():
	print getCommonElements( [ 2, 'S', 3.13, 3.13, "Python" ], [ 3.13, "Pythy", 2, 12, "hello", 2, 2 ] )

if __name__ == '__main__':
	main()
