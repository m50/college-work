/*

Developer:	 	Marisa Clardy (mclard01)
Title:			hw01 - Warriors
Description:	Reads commands from a warriors.txt file, and issues them. Makes warriors fight each other.

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Warrior
{
	string name;
	int strength;
};

void fight(Warrior& war1, Warrior& war2)
{
	cout << war1.name << " battles " << war2.name << endl;
	if (war1.strength == war2.strength) //If they are equal
	{
		if(war1.strength == 0 && war2.strength == 0) //Check if they are dead already
		{
			cout << "Oh, NO! They're both dead! Yuck!\n";
		}
		else
		{
			cout << "Mutual Annihilation: " << war1.name << " and " << war2.name << " die at each other's hands.\n";
		}
		war1.strength = war2.strength = 0;
	}
	else if (war1.strength > war2.strength) //If warrior 1 wins
	{
		if (war2.strength == 0) //kills warrior 2
		{
			cout << "He's dead " << war1.name << endl;
		}
		else
		{
			war1.strength = war1.strength - war2.strength;
			war2.strength -= war1.strength;
			cout << war1.name << " defeats " << war2.name << endl;
			if (war2.strength <= 0) {
				war2.strength = 0;
			}
		}
	}
	else if (war1.strength < war2.strength) //If warrior 2 wins
	{
		war1.strength -= war2.strength;
		cout << war2.name << " defeats " << war1.name << endl;
		if (war1.strength <= 0)
		{
			war1.strength = 0;
		}
	}
}

size_t findWarrior(const vector<Warrior>& warriors, const string& warriorName)
{
	for (size_t i = 0; i < warriors.size(); ++i)
	{
		if (warriors[i].name == warriorName)
			return i;
	}

	return warriors.size();
}

int main()
{
	ifstream warFile("warriors.txt");

	if(!warFile)
	{
		cerr << "The file could not be read.";
		exit(1);
	}

	vector<Warrior> warriors;

	//process commands
	string cmd;

	while (warFile >> cmd)
	{
		if (cmd == "Warrior")
		{
			//create temporary warrior to fill out the info to add to the vector.
			Warrior war;
			warFile >> war.name >> war.strength;
			warriors.push_back(war);
		}
		else if (cmd == "Status")
		{
			cout << "There are: " << warriors.size() << " warriors\n";
			for (Warrior w : warriors)
			{
				cout << "Warrior: " << w.name << ", strength: " << w.strength << endl;
			}
		}
		else if (cmd == "Battle")
		{
			string cont1Name, cont2Name;
			warFile >> cont1Name >> cont2Name;

			size_t cont1 = findWarrior(warriors, cont1Name);
			size_t cont2 = findWarrior(warriors, cont2Name);

			if(cont1 != warriors.size() && cont2 != warriors.size())
				fight(warriors[cont1], warriors[cont2]);
		}
	}

	warFile.close();
}
