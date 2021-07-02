/*

Title: Rec01
Programmer: Marisa Clardy (0486223)
Description: Read a file, count words, output file to console

*/
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int readNumWords(ifstream& file) //reads a file stream and returns the number of words in it
{
	file.clear();
	file.seekg(0);
	string word;
	int numWords = 0;
	while (file >> word)
		++numWords;
	return numWords;
}

void printFile(ifstream& file) //reads a file stream and outputs it to the console
{
	file.clear();
	file.seekg(0);
	string line;
	while (getline(file, line))
		cout << line << endl;
}

string getFileNameFromUser() //gets the name of the file from the user
{
	string fileName;
	cout << "Full file path (with extension): ";
	cin >> fileName;
	cout << endl;

	return fileName;
}

int main()
{
	string cmd;
	//Explain the instructions to the user
	cout << "Type in a command and press enter to execute.\nCommand List:\n  read => runs the function to read a file and output the number of words.\n  exit => exits the program\n\n";

	//command processor
	cout << "> ";
	while (cin >> cmd)
	{
		if (cmd == "exit")
			return 0;
		else if (cmd == "read")
		{
			string fileName = getFileNameFromUser();
			ifstream file(fileName);
			if(file) //if file exists
			{
				int numWords = readNumWords(file);
				printFile(file);
				cout << "\nThere are " << numWords << " words in this file.\n";
			}
			else
				cerr << "Cannot read file" << endl; //let the user know the file couldn't be read so that they can try again.

			file.close();
		}
		cout << "\n> ";
	}
}*/
