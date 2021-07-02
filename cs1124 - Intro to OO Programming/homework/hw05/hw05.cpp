/*

Developer:	 	Marisa Clardy (mclard01)
Title:			hw05 - A Game of Nobles and Men
Description:	2 Types of nobles, many types of protectors.
				Noble_1 fights himself,
				Noble_2 hires protectors to fight hisbattles

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--------------------------------------//
//			Classes				//
//--------------------------------------//
// Root Classes
class Noble {
public:
	Noble (const string& n) : name(n), dead(false) {}
	string get_name () const { return name; }
	bool is_dead () const {
		return dead;
	}
	void set_name (string n) { name = n; }

	virtual void display() const {}

	void battle(Noble& opp) {
		cout << name << " battles " << opp.name << endl;
		if(opp.is_dead()) {
			if(is_dead()) {
				cout << "Oh, NO! They're both dead! Yuck!" << endl;
				return;
			}
			cout << "He's dead, " << name << endl;
			return;
		}
		else if(is_dead()) {
			cout << "He's dead, " << opp.name << endl;
			return;
		}

		opp.battle_cry();
		battle_cry();

		if(get_strength() > opp.get_strength()) {
			opp.subtract_strength(get_strength());
			cout << name << " defeats " << opp.name << endl;
		}
		else if(get_strength() < opp.get_strength()) {
			subtract_strength(opp.get_strength());
			cout << opp.name << " defeats " << name << endl;
		}
		else if(get_strength() == opp.get_strength()) {
			cout << "Mutual Annihilation: " << name << " and " << opp.name << " die at each other's hands." << endl;
			subtract_strength(opp.get_strength());
			opp.subtract_strength(get_strength());
		}
	}
	virtual void subtract_strength(int s) {}
	virtual int get_strength() const { return 1; }
	virtual void battle_cry() const {}
protected:
	string name;
	bool dead;
};

class Protector {
public:
	Protector (const string& n, int s) : name(n), employer(nullptr), strength(s) {}

	Noble* get_employer	() const { return employer; }
	string get_name () const { return name; }
	int get_strength () const { return strength; }

	void set_employer (Noble* emp) { employer = emp; }
	void set_name (string n) { name = n; }
	void set_strength (int s) { strength = s; }

	virtual void battle_cry () const {
		cout << "Fwah! " << name << " says: Take that in the name of my lord, " << employer->get_name() << endl;
	}

	virtual void display () const {
		cout << "Protector: " << name << " is employed by " << employer->get_name() << " with strength: " << strength << endl;
	}
protected:
	Noble* employer;
	string name;
	int strength;
};

//Lords
class Knight : public Noble {
public:
	Knight(const string& n, int s) : Noble(n), strength(s) {}

	void subtract_strength(int s) {
		strength -= s;
		if(strength <= 0) {
			strength = 0;
			dead = true;
		}
	}

	void display() const {
		cout << name << " is a noble with the Strength To Fight, that strength being: " << strength << endl;
	}

	int get_strength() const { return strength; }
private:
	int strength;
};

class Lord : public Noble {
public:
	Lord(const string& n) : Noble(n) {}

	void hires(Protector& prot) {
		if(dead || prot.get_strength() <= 0 || prot.get_employer() != nullptr) return;
		army.push_back(&prot);
		prot.set_employer(this);
	}
	void fire(const Protector& prot) {
		cout << "You don't work for me anymore " << prot.get_name() << "!  -- " << name << ".\n";
		vector<Protector*> newArmy; 						//create a new Protector* vector, find all the ones that are not fired, reset the warriors vector to the new one.
		for(Protector* pPtr : army){ 						//	This is necessary because removal of an object at a position in a vector hasn't been taught yet.
			if(pPtr->get_name() != prot.get_name()) {
				newArmy.push_back(pPtr);
			}
			else {
				pPtr->set_employer(nullptr);
			}
		}
		army = newArmy;
	}
	void display() const {
		cout << name << " has an army of size " << army.size() << "\n";
		for(Protector* pPtr : army) {
			cout << "\t"; //tab it in for neater readability :D
			pPtr->display();
		}
	}
	int get_strength() const {
		int str = 0;
		for(Protector* pPtr : army) {
			str += pPtr->get_strength();
		}
		return str; //str is the summation of the strength of all the warriors in an army.
	}

	void subtract_strength(int s) {
		if(get_strength() <= 0) {
			dead = true;
			return;
		}

		if(army.size() == 1) {
			army[0]->set_strength(army[0]->get_strength() - s);
			if(army[0]->get_strength() <= 0) {
				army[0]->set_strength(0);
				cout << name << " dies " << get_strength() << endl;
				dead=true;
			}
			return;
		}
		for(Protector* p : army) {
			p->set_strength(p->get_strength() - s / army.size());
			if(p->get_strength() < 0) p->set_strength(0);
		}
		if(get_strength() <= 0) {
			dead = true;
		}
	}

	void battle_cry() const {
		for (Protector* p : army) {
			if(p->get_strength() > 0) p->battle_cry();
		}
	}
private:
	vector<Protector*> army;
};

//Protectors
class Warrior : public Protector {
public:
	Warrior(const string& name, int strength) : Protector(name, strength) {}
	virtual void battle_cry() const {
		cout << "CLINK! " <<  name << "  says: Take that in the name of my lord, " << employer->get_name() << endl;
	}
	virtual void display () const {
		cout << "Warrior: " << name << " is employed by " << employer->get_name() << " with strength: " << strength << endl;
	}
private:
};

class Archer : public Warrior {
public:
	Archer(const string& name, int strength) : Warrior(name, strength) {}
	void battle_cry() const {
		cout << "TWANG! " <<  name << "  says: Take that in the name of my lord, " << employer->get_name() << endl;
	}
	void display () const {
		cout << "Archer: " << name << " is employed by " << employer->get_name() << " with strength: " << strength << endl;
	}
private:
};

class Swordsman : public Warrior {
public:
	Swordsman(const string& name, int strength) : Warrior(name, strength) {}
	void battle_cry() const {
		cout << "CLANG! " <<  name << "  says: Take that in the name of my lord, " << employer->get_name() << endl;
	}
	void display () const {
		cout << "Swordsman: " << name << " is employed by " << employer->get_name() << " with strength: " << strength << endl;
	}
private:
};

class Wizard : public Protector {
public:
	Wizard(const string& name, int strength) : Protector(name, strength) {}
	void battle_cry() const {
		cout << "POOF" << endl;
	}
	void display () const {
		cout << "Wizard: " << name << " is employed by " << employer->get_name() << " with strength: " << strength << endl;
	}
private:
};



//Main
int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    Knight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    Knight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}
