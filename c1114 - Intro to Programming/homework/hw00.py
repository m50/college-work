#!C:\python27\python.exe
'''
cs1114

Submission: hw00
Programmer: Marisa Clardy

purpose of program, assumptions, constraints:
To answer questions about the class, found on the website, with python.
'''

#Get the OS module to pause
import os

#Answer all the questions
def main():
	print( "-> What is your lecture professor's name?" )
	print( "\tProf. Evan Gallagher" )
	print( "-> What are his office hours?" )
	print( "\tMondays, 2:15-2:45 (although sometimes taken by prelab meetings) Wednesdays, 1:00-2:40" )
	print( "-> Where is his office?" )
	print( "\tMTC 2 10.010" )
	print( "-> Should you always bring your laptop to the lab?" )
	print( "\tYes, and fully charged or with a charger" )
	print( "-> What is the date and time of the first and second tests?" )
	print( "\tEXAMS:\n\t\tEXAM1: Wednesday, October 17 \n\t\tEXAM2: Monday, November 12" )
	print( "-> What percentage of your final grade do these count?" )
	print( "\t25% each" )
	print( "-> If you do not take the final exam will you automatically fail the course?" )
	print( "\tYes." )
	print( "-> What is the period during which final exams are given?" )
	print( "\tEG 1 - Common Exam Period" )
	print( "-> What percentage of your final grade does your lecture attendance and \nparticipation count?" )
	print( "\t0%, however you must attend at least 21 lectures.\n\tParticipation is 10 points in the labs." )
	print( "-> How does it affect your letter grade?" )
	print( "\tYou can fail without showing up to enough lectures, \n\tand you can fail if your Lab grade drops below 83.33%" )
	print( "-> What percentage of your final grade do the labs count?" )
	print( "\t0%, you need at least an 83.33% on your lab grade to pass" )
	print( "-> How does it affect your letter grade?" )
	print( "\tYou can fail if it drops too low, no letter grade difference." )
	print( "-> What is the minimum number of lectures you must attend to pass this course?")
	print( "\t21" )
	print( "-> If you do not meet that minimum number what grade will you get for the course?" )
	print( "\tYou will fail." )
	print( "-> What is the minimum score in the labs you must attain to pass this course?" )
	print( "\t83.33%" )
	print( "-> If you do not meet that minimum score what grade will you get for the course?" )
	print( "\tYou will fail" )

#Call the main function, and then pause so that the answers are readable.
if __name__ == '__main__':
	main()
	os.system("pause")
