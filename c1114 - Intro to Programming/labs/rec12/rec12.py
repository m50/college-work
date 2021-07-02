'''
cs1114

Submission: rec12

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
HydroCarbon builder
'''

from HydrocarbonMolecule import HydroCarbyMolly as HCmol

def addMolsToList(mol, molList):
	'''adds a molecule (mol) to a list (molList)'''
	molList.append(mol)

def getMolFromFile(fl):
	moles = []
	for ln in fl:
		if ln == "" or ln == "\n":
			continue
		ss = ln.split()
		name = ss[0]
		formula = ss[1].split("H")
		numC = int(formula[0].strip("C"))
		numH = int(formula[1])
		m = HCmol(numH, numC, name)
		if m not in moles:
			moles.append(m)
		else:
			moles[moles.index(m)].addName(name)
	moles.sort()
	return moles

def printMol(moles):
	for n in moles:
		print n

def main():
	fh = open("hydrocarbons.txt", 'r')
	moles = getMolFromFile(fh)
	fh.close()
	printMol(moles)

if __name__ == '__main__':
	main()
