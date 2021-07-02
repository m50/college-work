/*

Developer:      Marisa Clardy (mclard01)
Title:          Noble.cpp
Description:    Implementation of Noble.h

*/
#include "Noble.h"
#include "Warrior.h"
#include <iostream>

using namespace std;

namespace WarriorCraft {
	Noble::Noble(const string& name)  : name(name), dead(false) {}
	string Noble::get_name() const { return name; }
	vector<Warrior*>& Noble::get_warriors() { return warriors; }
	int Noble::get_army_strength() const {
		int str = 0;
		for(Warrior* wPtr : warriors) {
			str += wPtr->get_strength();
		}
		return str; //str is the summation of the strength of all the warriors in an army.
	}

	void Noble::display(ostream& stream) const {
		stream << name << " has an army of size " << warriors.size();
		for(size_t i = 0; i < warriors.size(); ++i) {
			stream << "\n\t" << *warriors[i];
		}
	}

	void Noble::battle(Noble& eNoble) {
		cout << name << " battles " << eNoble.name << endl;
		if (eNoble.dead) { //check if the enemy is dead
			if(dead) { //if both are dead
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
				return;
			}
			cout << "He's dead, " << name << endl;
			return;
		}
		else if (dead) { //if you are dead
			cout << name << " is already dead." << endl;
			return;
		}
		if (get_army_strength() == eNoble.get_army_strength()) { // equal strengths
			cout << "Mutual Annihilation: " << name << " and " << eNoble.name << " die at each other's hands." << endl;
			modify_strength(eNoble);
			eNoble.modify_strength(*this);
		}
		else if (get_army_strength() < eNoble.get_army_strength()) { // enemy is stronger
			modify_strength(eNoble);
			cout << eNoble.name << " defeats " << name << endl;
		}
		else if(get_army_strength() > eNoble.get_army_strength()) { //you are stronger
			eNoble.modify_strength(*this);
			cout << name << " defeats " << eNoble.name << endl;
		}
	}

	void Noble::modify_strength(Noble& opp) {
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

	void Noble::die() { // a bit unnecessary of a function, but useful if you want a meteor to land on a Noble.
		dead = true;
	}

	void Noble::hire(Warrior& warrior) {
		if(dead) return; //don't hire if dead
		if(warrior.get_employed()) {
			cerr << warrior.get_name() << " is already employed" << endl;
			return;
		}
		warrior.set_employer(this);
		warriors.push_back(&warrior);
	}

	void Noble::fire(Warrior& warrior) {
		cout << "You don't work for me anymore " << warrior.get_name() << "!  -- " << name << ".\n";
		for (size_t i = 0; i < warriors.size(); ++i)
		{
			if(warriors[i]->get_name() == warrior.get_name() && i < warriors.size() - 1) {
				warriors[i] = warriors[i+1];														//Is this a better a way to do it?
				warriors[i+1] = &warrior;
			}
		}
		warriors.pop_back();
		warrior.set_employer(nullptr);
	}


	ostream& operator<<(ostream& stream, const Noble& noble) {
		noble.display(stream);
		return stream;
	}
}
