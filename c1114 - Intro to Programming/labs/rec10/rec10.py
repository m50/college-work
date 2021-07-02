'''
cs1114

Submission: rec10

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
list functions
'''

import random

def getUserListSOZ():
	'''gets a list of words from the user, however stops when inputed "ZEBRA"'''
	lst = []
	print "Give me a list of words, use ZEBRA to stop inputing"
	while True:
		inp = raw_input()
		if inp == "ZEBRA":
			return lst
		lst.append(inp)

def prettyPrintList(lst):
	lst2 = []
	for n in lst:
		lst2.append(n)
	nLst.sort()
	for n in range(len(nLst)):
		s = str(n) + " : " + str(nLst[n])
		print s
		print "-" * len(s)

def remCopies(removeList, removeFrom):
	for n in removeList:
		if n in removeFrom:
			removeFrom.remove(n)

def randomCombineLists(list1, list2):
	if list1 == [] or list2 == []:
		return None
	item = list1[random.randint(0,len(list1)-1)]
	list2.insert(item, random.randint(0,len(list2)-1))

def palindromeList(lst):
	lst2 = []
	for n in lst:
		lst2.append(n)
	lst2.reverse()
	if lst2 == lst:
		return True
	return False

def almostPalindromicArray(floatArray, closenessFactor = 1.2):
	value = floatArray[0] / floatArray[len(floatArray) - 1]
	if 1/closenessFactor <= value <= closenessFactor:
		return True
	return False

def reduceListByN(lst, n):
	for x in range(n):
		lst.pop()
