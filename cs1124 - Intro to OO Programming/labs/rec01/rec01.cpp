/*
Title: rec01
Author: Marisa Clardy 0486223
Course: CS1124
Description: read the cpp file, output to console, and display the number of words
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream ifs("rec01.cpp"); // open the source file for this recitation

	if(!ifs) //checking that rec01.cpp can be read
	{
		cerr << "Could no open the file" << endl;
		exit(1); //exiting from the application with an error
 	}

	string line;
	while (getline(ifs, line))
	{
		cout << line << endl;
	}

	ifs.clear();
	ifs.seekg(0); // reset the location to the zeroth position in the file

	string word;
	int numWords = 0;
	while(ifs >> word)
	{
		numWords++;
	}
	cout << "There are " << numWords << " words in the file.\n";

	ifs.close();

	getline(cin, word);
}
