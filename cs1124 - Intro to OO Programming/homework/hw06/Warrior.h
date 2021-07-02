/*

Developer:      Marisa Clardy (mclard01)
Title:          Warrior.h
Description:    Definition for the Warrior class.

*/
#ifndef WARRIOR_H
#define WARRIOR_H

#include <vector>
#include <string>
#include <ostream>

namespace WarriorCraft {
	class Noble; //errors will return because no such class exists yet, otherwise.

	class Warrior{
	public:
		Warrior(const std::string& name, int strength);
		std::string get_name() const;
		int get_strength() const;
		void set_strength(int str);
		void display(std::ostream& stream) const;
		bool get_employed () const;
		Noble* get_employer () const;
		void set_employer (Noble* employer);
		void runaway();
	private:
		std::string name;
		int strength;
		Noble* employer;
	};

	std::ostream& operator<<(std::ostream& os, const Warrior& n);
}

#endif
