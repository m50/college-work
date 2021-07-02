'''
cs1114

Submission: hw09
Programmer: Marisa Clardy

purpose of program, assumptions, constraints:

'''
#-------------------------------------------------------------COMPANY CLASS-------------------------------------------------------------#
class Company(object):
	def __init__(self, name, startingReportVal = 288):
		self._name = name
		self._workers = []
		self._curReport = startingReportVal
		self._maxPayAmount = float("inf")

	def hireWorker(self, name, SSN):
		wo = WorkerRec(name, SSN)._setMaxPay(self._maxPayAmount)
		if wo not in self._workers:
			self._workers.append(wo)
			return wo
		return self._workers[self._workers.index(wo) - 1]

	def findWorkerBySSN(self, SSN):
		for n in self._workers:
			if n.getSSN() == SSN:
				return n
		return "No worker to be found by that SSN"


	def setMaxPay(self, amount):
		'''sets max pay amount'''
		self._maxPayAmount = amount
		return self

	def payWorkers(self):
		ss = self._name.split()
		fileName = ''
		for s in ss:
			fileName += s
		fileName += '%3i.txt' % (self._curReport)
		self._curReport += 177
		if self._curReport >= 999:
			self._curReport -= 999
		fh = open(fileName, 'w')

		self._workers.sort()
		for w in self._workers:
			fh.write(str(w) + '\n')
			w.resetEarned()

		fh.close()


	def fireWorker(self, ssn):
		employee = self.findWorkerBySSN(ssn)
		if type(employee) == str:
			return "No worker to be found by that SSN"
		ss = employee.getName().split()
		fn = ''
		for n in ss:
			fn += n
		fn += 'FINAL.txt'
		fh = open(fn, 'w')
		fh.write(str(employee))
		fh.close()
		self._workers.remove(employee)



#-------------------------------------------------------------WORKERREC CLASS-------------------------------------------------------------#
class WorkerRec(object):

	def __init__(self, name, ssn, hourlyPay = 17.22, ):
		'''
		name 		-> string
		ssn 		-> int
		hourlyPay 	-> float
		'''
		self._ssn = ssn
		self._name = name
		self._hourlyPay = hourlyPay
		self._title = ""
		self._earned = 0
		self._maxPay = float('inf')


	def _setMaxPay(self, pay):
		self._maxPay = pay
		return self

	def giveTitle(self, title):
		'''
		title 		-> string
		'''
		self._title = title
		return self

	def addHours(self, hours):
		'''increase pay based on hours worked'''
		self._earned += hours * self._hourlyPay
		return self

	def resetEarned(self):
		'''sets earned to 0'''
		self._earned = 0
		return self

	def setHourlyPay(self, pay):
		'''set how much they are payed by the hour'''
		if pay < 0 or pay > self._maxPay:
			return "Bad pay amount"
		self._hourlyPay = pay
		return self

	def getName(self):
		'''get the name of the worker'''
		return self._name

	def getSSN(self):
		'''gets the ssn of the worker'''
		return self._ssn

	def __str__(self):
		s = str(self._ssn) + '\n'
		s += self._name
		s += ' $%.2f [%s]' % (self._earned, self._title) if self._title != '' else ' $%.2f' % (self._earned)
		return s

	def __cmp__(self, other):
		if type(other) != WorkerRec:
			return -1
		if self._earned < other._earned:
			return 1
		elif self._earned == other._earned:
			if self._ssn > other._ssn:
				return -1
			else:
				return 1
		return 0

	def __eq__(self, other):
		if type(other) != WorkerRec:
			return False
		return self._ssn == other._ssn

#-------------------------------------------------------------TEST CODE-------------------------------------------------------------#
def main():
	rpspc = Company("RockPit SnakePit and Co.", 723)
	rpspc.hireWorker("Sally Jones", 443882354).setHourlyPay(35.22)
	rpspc.hireWorker("Joe Smith", 283728992).setHourlyPay(25.34)
	rpspc.findWorkerBySSN(443882354).addHours(11)
	rpspc.findWorkerBySSN(283728992).addHours(9)
	rpspc.findWorkerBySSN(443882354).addHours(3)
	rpspc.payWorkers()
	rpspc.findWorkerBySSN(443882354).addHours(10)
	rpspc.hireWorker("Raphael", 248339271).setHourlyPay(26.39)
	rpspc.findWorkerBySSN(283728992).addHours(4)
	rpspc.findWorkerBySSN(443882354).giveTitle("Master Snake Handler")
	rpspc.findWorkerBySSN(283728992).setHourlyPay(15.15)
	rpspc.findWorkerBySSN(443882354).addHours(7)
	rpspc.payWorkers()
	rpspc.findWorkerBySSN(283728992).addHours(9)
	rpspc.findWorkerBySSN(248339271).addHours(4)
	rpspc.fireWorker(283728992)
	rpspc.findWorkerBySSN(248339271).setHourlyPay(15.15)
	rpspc.findWorkerBySSN(248339271).addHours(18)
	rpspc.hireWorker("Raphael", 248339271)
	rpspc.payWorkers()


if __name__ == '__main__':
	main()
