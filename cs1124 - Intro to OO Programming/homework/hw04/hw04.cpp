/*

Developer:	 	Marisa Clardy (mclard01)
Title:			hw04 - A Game of Nobles and Men
Description:	Nobles hire warriors, fight each other using the warriors strength.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Noble;

class Warrior{
public:
	Warrior(string name, int strength) : name(name), strength(strength) {}
	string get_name() const { return name; }
	int get_strength() const { return strength; }
	void set_strength(int str) { strength = str; }
	void display() const {
		cout << name << ": " << strength << endl;
	}
	bool get_employed () const { return employed; }
	void set_employed (bool employed) { this->employed = employed; }
private:
	string name;
	int strength;
	bool employed = false;
};

class Noble{
public:
	Noble(string name) : name(name), dead(false){}

	string get_name() const { return name; }

	void display() const {
		cout << name << " has an army of size " << warriors.size() << "\n";
		for(size_t i = 0; i < warriors.size(); ++i) {
			cout << "\t"; //tab it in for neater readability :D
			warriors[i]->display();
		}
	}
	void battle(Noble& eNoble) {
		cout << name << " battles " << eNoble.name << endl;
		if (eNoble.dead) {
			if(dead) {
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
				return;
			}
			cout << "He's dead " << name << endl;
			return;
		}
		else if (dead) {
			cout << name << " is already dead." << endl;
			return;
		}
		if (get_army_strength() == eNoble.get_army_strength()) {
			cout << "Mutual Annihilation: " << name << " and " << eNoble.name << " die at each other's hands." << endl;
			modify_strength(eNoble);
			eNoble.modify_strength(*this);
		}
		else if (get_army_strength() < eNoble.get_army_strength()) {
			modify_strength(eNoble);
			cout << eNoble.name << " defeats " << name << endl;
		}
		else if(get_army_strength() > eNoble.get_army_strength()) {
			eNoble.modify_strength(*this);
			cout << name << " defeats " << eNoble.name << endl;
		}
	}
	void modify_strength(Noble& opp) {
		if(opp.get_army_strength() > get_army_strength())
			opp.modify_strength(*this);
		if(opp.warriors.size() == 1 && warriors.size() == 1) {
			warriors[0]->set_strength(warriors[0]->get_strength() - opp.warriors[0]->get_strength());
			if(warriors[0]->get_strength() <= 0) {
				warriors[0]->set_strength(0);
			}
			return;
		}

		double mod = (double)get_army_strength() / opp.get_army_strength();
		for(Warrior* wPtr : warriors) {
			wPtr->set_strength(wPtr->get_strength() -(int)( wPtr->get_strength() * mod));
			if(wPtr->get_strength() <= 0) {
				wPtr->set_strength(0);
			}
		}
		if(get_army_strength() == 0) {
			die();
		}
	}
	int get_army_strength() const {
		int str = 0;
		for(Warrior* wPtr : warriors) {
			str += wPtr->get_strength();
		}
		return str; //str is the summation of the strength of all the warriors in an army.
	}
	void die() {
		dead = true;
	}
	void hire(Warrior& warrior) {
		if(dead) return; //don't hire if dead
		if(warrior.get_employed()) {
			cerr << warrior.get_name() << " is already employed" << endl;
			return;
		}
		warrior.set_employed(true);
		warriors.push_back(&warrior);
	}
	void fire(Warrior& warrior) {
		cout << "You don't work for me anymore " << warrior.get_name() << "!  -- " << name << ".\n";
		vector<Warrior*> newWarriors; 						//create a new warrior* vector, find all the ones that are not fired, reset the warriors vector to the new one.
		for(Warrior* wPtr : warriors){ 						//	This is necessary because removal of an object at a position in a vector hasn't been taught yet.
			if(wPtr->get_name() != warrior.get_name()) {
				newWarriors.push_back(wPtr);
			}
			else {
				wPtr->set_employed(false);
			}
		}
		warriors = newWarriors;
	}
private:
	string name;
	vector<Warrior*> warriors;
	bool dead;
};

Noble* findNoble(const vector<Noble*>& nobles, const string& name) {
	for(Noble* n : nobles) {
		if (name == n->get_name()) {
			return n;
		}
	}
	return NULL;
}

Warrior* findWarrior(const vector<Warrior*>& warriors, const string& name) {
	for(Warrior* w : warriors) {
		if (name == w->get_name()) {
			return w;
		}
	}
	return NULL;
}

void status(const vector<Noble*>& nobles, const vector<Warrior*>& warriors) {
	cout << "STATUS\n======\nNobles:" << endl;
	if(nobles.size() > 0) {
		for (Noble* n : nobles)  {
			n->display();
		}
	}
	else {
		cout << "NONE" << endl;
	}
	cout << "Unemployed Warriors:" << endl;
	if(warriors.size() > 0) {
		for (Warrior* w : warriors)  {
			if(!w->get_employed()) {
				w->display();
			}
		}
	}
	else {
		cout << "NONE" << endl;
	}
}

void clear(vector<Warrior*>& warriors, vector<Noble*>& nobles) {
	for(Warrior* w : warriors) {
		delete w;
	}
	warriors.clear();
	for(Noble* n : nobles) {
		delete n;
	}
	nobles.clear();
}

int main () {
	ifstream fsin("nobleWarriors.txt");
	if(!fsin) {
		cerr << "Unable to read file" << endl;
		return 1;
	}

	string cmd;
	vector<Noble*> nobles;
	vector<Warrior*> warriors;

	while(fsin >> cmd) {
		if(cmd == "Noble") {
			string name;
			fsin >> name;
			if(findNoble(nobles, name) != NULL)
				nobles.push_back(new Noble(name));
			else
				cerr << "Noble with name " << name << " already exists." << endl;
		}
		else if(cmd == "Warrior"){
			string name;
			int strength;
			fsin >> name >> strength;
			if(findWarrior(warriors, name) != NULL)
				warriors.push_back(new Warrior(name, strength));
			else
				cerr << "Noble with name " << name << " already exists." << endl;
		}
		else if(cmd == "Status"){
			status(nobles, warriors);
		}
		else if (cmd == "Battle") {
			string nob1, nob2;
			fsin >> nob1 >> nob2;
			findNoble(nobles, nob1)->battle(*findNoble(nobles, nob2));
		}
		else if (cmd == "Hire") {
			string nobleName, warName;
			fsin >> nobleName >> warName;
			if(!findWarrior(warriors, warName)->get_employed())
				findNoble(nobles, nobleName)->hire(*findWarrior(warriors, warName));
			else
				cerr << warName << " is already employed" << endl;
		}
		else if (cmd == "Fire") {
			string nobleName, warName;
			fsin >> nobleName >> warName;
			findNoble(nobles, nobleName)->fire(*findWarrior(warriors, warName));
		}
		else if (cmd == "Clear") {
			clear(warriors, nobles);
		}
	}
}
