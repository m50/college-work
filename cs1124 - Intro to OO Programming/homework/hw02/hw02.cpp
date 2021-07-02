/*

Developer:	 	Marisa Clardy (mclard01)
Title:			hw02 - Warriors with weapons
Description:	Reads commands from a warriors.txt file, and issues them. Makes warriors fight each other.

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Weapon {
public:
	Weapon(string name, int str) : name(name), strength(str) {}
	string get_name() const { return name; }
	int get_strength() const { return strength; }
	void set_strength(int str) { strength = str; }
private:
	string name;
	int strength;
};

class Warrior {
public:
	Warrior(string& name, Weapon& wep) : name(name), weapon(wep) {}
	Warrior(string& name, string& weaponName, int strength) : name(name), weapon(weaponName, strength) {}
	void display() const {
		cout << "Warrior: " << name << ", " << "weapon: " << weapon.get_name() << " " << weapon.get_strength() << endl;
	}
	string get_name() const { return name; }
	void set_strength(int str) { weapon.set_strength(str); }
	int get_strength() { return weapon.get_strength(); }
	void fight(Warrior& war2)
	{
		cout << name << " battles " << war2.name << endl;
		if (get_strength() == war2.get_strength()) //If they are equal
		{
			if(get_strength() == 0 && war2.get_strength() == 0) //Check if they are dead already
				cout << "Oh, NO! They're both dead! Yuck!\n";
			else
				cout << "Mutal Annihilation: " << name << " and " << war2.name << " die at each other's hands.\n";
			set_strength(0);
			war2.set_strength(0);
		}
		else if (get_strength() > war2.get_strength()) //If warrior 1 wins
		{
			set_strength(get_strength() - war2.get_strength());
			if (war2.get_strength() <= 0) //kills warrior 2
			{
				cout << "He's dead " << name << endl;
				war2.set_strength(0);
			}
			else
			{
				cout << name << " defeats " << war2.name << endl;
			}
		}
		else if (get_strength() < war2.get_strength()) //If warrior 2 wins
		{
			war2.set_strength(get_strength() - war2.get_strength());
			set_strength(war2.get_strength() - war2.get_strength());
			cout << war2.name << " defeats " << name << endl;
			if (get_strength() <= 0)
			{
				set_strength(0);
			}
		}
	}
private:
	string name;
	Weapon weapon;
};

size_t findWarrior(const vector<Warrior>& warriors, const string& warriorName) {
	for (size_t i = 0; i < warriors.size(); ++i)
		if (warriors[i].get_name() == warriorName)
			return i;
	return warriors.size();
}

int main() {
	ifstream warFile("warriors.txt");

	if(!warFile) {
		cerr << "The file could not be read.";
		exit(1);
	}

	vector<Warrior> warriors;

	//process commands
	string cmd;

	while (warFile >> cmd)  {
		if (cmd == "Warrior") {
			//create temporary warrior to fill out the info to add to the vector.
			int strength;
			string warName, wepName;
			warFile >> warName >> wepName >> strength;
			Weapon wep(wepName, strength);
			Warrior war(warName, wep);

			warriors.push_back(war);
		}
		else if (cmd == "Status") {
			cout << "There are: " << warriors.size() << " warriors\n";
			for (Warrior w : warriors) {
				w.display();
			}
		}
		else if (cmd == "Battle") {
			string cont1Name, cont2Name;
			warFile >> cont1Name >> cont2Name;

			size_t cont1 = findWarrior(warriors, cont1Name);
			size_t cont2 = findWarrior(warriors, cont2Name);

			if(cont1 != warriors.size() && cont2 != warriors.size())
				warriors[cont1].fight(warriors[cont2]);
		}
	}

	warFile.close();
}
