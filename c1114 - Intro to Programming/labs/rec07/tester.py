import colourStuff
import tshirtContest
import numStuff
import english101
import rotator

def main( ):
    #colourStuff
    print colourStuff.pickRandomColour()
    print colourStuff.pickRandomColour()
    print colourStuff.pickRandomColour()
    
    #tshirtContest
    var1 = int( raw_input( "dollars: " ) )
    var2 = int( raw_input( "quarters: " ) )
    var3 = int( raw_input( "dimes: " ) )
    var4 = int( raw_input( "pennies: " ) )
    print tshirtContest.definePrize(var1, var2, var3, var4)
    
    #numStuff
    var1 = int( raw_input( "Num1: " ) )
    var2 = int( raw_input( "Num2: " ) )
    print numStuff.canNumberByDividedBy( var1, var2 )
    
    #english101
    english101.decidePartOfSpeech( )
    english101.decidePartOfSpeech( )
    english101.decidePartOfSpeech( )
    english101.decidePartOfSpeech( )
    
    #rotator
    var1 = 34
    var2 = -12
    var3 = 44444
    print "BEFORE"
    print var1, var2, var3
    var1, var2, var3 = rotator.rotateThese( var1, var2, var3, rotator.CLOCKWISE )
    print "AFTER clockwise rotate"
    print var1, var2, var3
    var1 = 34
    var2 = -12
    var3 = 44444
    print "again, BEFORE, this time with counterclockwise rotation"
    print var1, var2, var3
    var1, var2, var3 = rotator.rotateThese( var1, var2, var3, rotator.COUNTERCLOCKWISE )
    print "AFTER"
    print var1, var2, var3
    print "again, using the default parameter value for direction"
    var1 = 34
    var2 = -12
    var3 = 44444
    print "BEFORE"
    print var1, var2, var3
    var1, var2, var3 = rotator.rotateThese( var1, var2, var3 )
    print "AFTER"
    print var1, var2, var3
	
    #freeze it!
    raw_input( " ")
    
if __name__ == "__main__":
    main()