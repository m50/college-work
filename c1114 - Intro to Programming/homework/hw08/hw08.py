'''
cs1114

Submission: hw08
Programmer: Marisa Clardy

purpose of program, assumptions, constraints:
process UN data
'''

def createPeriods(fl):
	'''Read the file and split the information into two periods, 1970-1990 and 1990-2007'''
	fl.readline() #skip the first line
	seventyToNinety = []
	ninetyTo07 = []
	for ln in fl:
		if ln == "\n" or ln == '':
			continue
		ss = ln.strip().split(',')
		ss = ss[1].strip().split()
		if ss[0] == '1990-2007':
			ninetyTo07.append(ln)
		else:
			seventyToNinety.append(ln)
	return seventyToNinety, ninetyTo07

def processPeriod(period):
	'''mine the information out of each line in a period list'''
	total = 0
	changes = []
	for n in period:
		ss = n.strip().split(', ')
		k = ss[1].split()
		ss.pop(1)
		ss += k
		name = ss[0]
		percChange = float(ss[2].rstrip('%'))
		total += percChange
		changes.append((percChange, name))
	changes.sort()
	smallestThree = changes[:3]
	changes.reverse()
	largestThree = changes[:3]
	if len(period) != 0:
		average = float(total) / len(period)
	else:
		average = 0
	info = (average, smallestThree, largestThree)
	return info


def writeFile(fh, info):
	'''writes information to a file'''
	ss = fh.name.rstrip('.txt').split('_')
	fh.write("%s-%s Summary Report\n\n" % (ss[0], ss[1]))
	fh.write('average growth over all countries: %.3f%%\n\n' % (info[0]))
	fh.write('The three countries with largest growth:\n')
	k = 0
	for n in info[2]:
		fh.write('%s (%.2f%%), ' % (n[1], n[0]) if k < 2 else '%s (%.2f%%)' % (n[1], n[0]))
		k += 1
	fh.write('\n\n')
	fh.write('The three countries with smallest growth:\n')
	k = 0
	for n in info[1]:
		fh.write('%s (%.2f%%), ' % (n[1], n[0]) if k < 2 else '%s (%.2f%%)' % (n[1], n[0]))
		k += 1

def main():
	fh = open("UN-world-pop-change-data.txt", "r")
	seventyToNinety, ninetyTo07 = createPeriods(fh)
	stn = processPeriod(seventyToNinety)
	nt07 = processPeriod(ninetyTo07)
	fh.close()
	fh = open("1970_1990_summary.txt", 'w')
	writeFile(fh, stn)
	fh.close()
	fh = open("1990_2007_summary.txt", 'w')
	writeFile(fh, nt07)
	fh.close()

if __name__ == '__main__':
	main()

