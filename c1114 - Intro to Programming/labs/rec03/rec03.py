#!C:/Python27/python.exe
'''
cs1114

Submission: rec03

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Making a coffee and donut shop
'''

import os
import Money

TAX_RATE = .0846
DONUT_COST = .64
COFFEE_COST = .77

def getOrder( ):
    '''
INPUTS:
        none
RETURNS:
        numCupCoffee -> int
        numDoughnuts -> int
DESCRIPTION:
        Takes input from the user about the number of
        cups of coffee and donuts the user wants, and returns it.
'''
    numCupCoffee = int( raw_input( "How many cups of Coffee would you like? " ) )
    numDoughnuts = int( raw_input( "How many doughnuts would you like? " ) )
    return numCupCoffee, numDoughnuts

def calcTotalAmount( numCupCoffee, numDoughnuts ):
    '''
INPUTS:
        numCupCoffee -> int
        numDoughnuts -> int
RETURNS:
        totalCost -> float
DESCRIPTION:
        Takes in the number of cups of coffee and the number of donuts, and
        returns how much it will cost, including tax.
        '''
    totalCoffeeCost = numCupCoffee * COFFEE_COST
    totalDonutCost = numDoughnuts * DONUT_COST
    totalCost = totalCoffeeCost + totalDonutCost
    totalCost += totalCost * TAX_RATE
    return totalCost

def calcAmounts( numCupCoffee, numDoughnuts ):
    '''
INPUTS:
        numCupCoffee -> int
        numDoughnuts -> int
RETURNS:
        totalCost   -> float
        coffeeCost  -> float
        donutCost   -> float
        tax         -> float
DESCRIPTION:
        Calculates all the amounts to pass into Display Bill
        '''
    totalCost = calcTotalAmount( numCupCoffee, numDoughnuts )
    coffeeCost = numCupCoffee * COFFEE_COST
    donutCost = numDoughnuts * DONUT_COST
    tax = totalCost * TAX_RATE
    return totalCost, coffeeCost, donutCost, tax

def displayBill( numCupCoffee, numDonuts, totalOwed, coffeeCost, donutCost, taxAmount ):
    '''
INPUTS:
        numCupCoffee -> int
        numDonuts    -> int
        totalOwed    -> float
RETURNS:
        none
DESCRIPTION:
        Displays the bill with the number of cups of coffee, the number of
        donuts, tax rate, and total owed
    '''
    print('\n\n')
    print( '/\\' * 15 )
    print( "THE COFFEE AND DOUGHNUT SHOPPE" )
    print( '\\/' * 15 + "\n" )
    print( "%d cups of coffee: " % ( numCupCoffee ) )
    Money.printAsUSDollars( coffeeCost, '$' )
    print( "%d doughnuts: " % ( numDonuts ) )
    Money.printAsUSDollars( donutCost, '$' )
    print( "tax: " )
    Money.printAsUSDollars( taxAmount, '$' )
    print( "Amount Owed: " )
    Money.printAsUSDollars( totalOwed, '$' )
    print( "\nTHANK YOU FOR SHOPPING LOCAL" )

def main( ):
    numCupCoffee, numDoughnuts = getOrder( )
    totalCost, coffeeCost, donutCost, tax = calcAmounts( numCupCoffee, numDoughnuts )
    displayBill( numCupCoffee, numDoughnuts, totalCost, coffeeCost, donutCost, tax )

if __name__ == "__main__":
    main()
    os.system("pause")
