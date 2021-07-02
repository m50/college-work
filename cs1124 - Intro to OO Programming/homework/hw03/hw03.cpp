/*

Developer:	 	Marisa Clardy (mclard01)
Title:			hw03 - A Game of Nobles and Men
Description:	Nobles hire warriors, fight each other using the warriors strength.

*/

#include <iostream>
#include <string>
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
				die();
			}
			return;
		}

		double mod = (double)get_army_strength() / opp.get_army_strength();
		for(Warrior* wPtr : warriors) {
			wPtr->set_strength(wPtr->get_strength() - (int)(wPtr->get_strength() * mod));
			if(wPtr->get_strength() <= 0) {
				wPtr->set_strength(0);
			}
		}
		if(get_army_strength() == 0) die();
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

int main(){
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}
