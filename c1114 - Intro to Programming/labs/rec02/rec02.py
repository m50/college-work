#!C:\Python27\python.exe
'''
cs1114

Submission: rec02

Programmer: Marisa Clardy

Purpose of program, assumptions, constraints:
Print a box of X's with joe in it.
'''

import os

def lineOfXs( ):
    '''Prints 9 X's in a row'''
    print( "x" * 9 )

def print2Xs( ):
    '''Prints 2 Xs with 7 spaces in between'''
    print( "X" + ' ' * 7 + 'X' )

def printName( ):
    '''Prints the name, "Joe" surrounded by X's'''
    print( "X  Joe  X" )

def main( ):
    lineOfXs()
    print2Xs()
    printName()
    print2Xs()
    lineOfXs()

if __name__ == "__main__":
    main()
    os.system("pause")
