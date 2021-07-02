
'''
cs1114

Submission: rec05

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Making a coffee and donut shop that has an awesome bill
'''

import screenyStuff
import donutShop

def main( ):
	numCupCoffee, numDoughnuts = donutShop.getOrder( )
	totalCost, coffeeCost, donutCost, tax, realAmountOwed = donutShop.calcAmountsSale( numCupCoffee, numDoughnuts )
	donutShop.displayBillSale( numCupCoffee, numDoughnuts, totalCost, realAmountOwed, coffeeCost, donutCost, tax )
	donutShop.displayRandomCode( )
	screenyStuff.pause( )

if __name__ == "__main__":
	main()
