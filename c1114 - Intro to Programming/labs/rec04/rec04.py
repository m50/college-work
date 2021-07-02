'''
cs1114

Submission: rec03

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:

'''

import Money

def main( ):
	penny, nickel, dime, quarter, dollarCoin = Money.calculateCoins( 8.67 )
	Money.printAsCoins( penny, nickel, dime, quarter, dollarCoin )
	Money.printAsUSDollars( 5.3212, '$' )
	usd = Money.convertPesosToUSDollars( 600 )
	Money.printAsUSDollars( usd, 'USD ' )

if __name__ == "__main__":
    main()
