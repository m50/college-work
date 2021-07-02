/*

Developer:      Marisa Clardy (mclard01)
Title:          Noble.h
Description:    Definition for the Noble class.

*/
#ifndef NOBLE_H
#define NOBLE_H

#include <vector>
#include <string>
#include <ostream>

namespace WarriorCraft {
	class Warrior; //errors will return because no such class exists yet, otherwise.

	class Noble{
	public:
		Noble(const std::string& name);

		std::string get_name() const;
		void display(std::ostream& stream) const;

		void battle(Noble& eNoble);
		void modify_strength(Noble& opp);
		int get_army_strength() const;
		std::vector<Warrior*>& get_warriors();

		void die();

		void hire(Warrior& warrior);
		void fire(Warrior& warrior);
	private:
		std::string name;
		std::vector<Warrior*> warriors;
		bool dead;
	};
	std::ostream& operator<<(std::ostream& os, const Noble& n);
}

#endif
