/*

Developer:      Marisa Clardy (mclard01)
Title:          Warrior.cpp
Description:    Implementation of Warrior.h

*/
#include "Warrior.h"
#include "Noble.h"
#include <iostream>

using namespace std;

namespace WarriorCraft {
	void Warrior::display(ostream& stream) const {
		stream << name << ": " << strength;
	}

	Warrior::Warrior(const string& name, int strength) : name(name), strength(strength), employer(nullptr) {}

	string Warrior::get_name() const { return name; }									//-------------------//
	int Warrior::get_strength() const { return strength; }								//					 //
	void Warrior::set_employer (Noble* employer) { this->employer = employer; }			//  Lots of getters  //
	Noble* Warrior::get_employer () const { return employer; }							//					 //
	bool Warrior::get_employed () const { return employer != nullptr; }	//not null		//-------------------//

	void Warrior::set_strength(int str) { strength = str; }

	void Warrior::runaway() {
		cout << name << " flees in terror, abandoning his lord, " << employer->get_name() << endl;
		for (size_t i = 0; i < employer->get_warriors().size(); ++i)
		{
			if(employer->get_warriors()[i]->get_name() == name && i < employer->get_warriors().size() - 1) {
				employer->get_warriors()[i] = employer->get_warriors()[i+1];									//Almost exactly like the fire function
				employer->get_warriors()[i+1] = this;
			}
		}
		employer->get_warriors().pop_back();
		set_employer(nullptr); // set employer to a nullptr, so that it has no employer
	}
	ostream& operator<<(ostream& stream, const Warrior& war) {
		war.display(stream);
		return stream;
	}
}
