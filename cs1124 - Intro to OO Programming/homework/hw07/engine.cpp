#include "engine.h"

using namespace std;

namespace PolyAuto {
	Engine::Engine(const string& type, int hp, Car* contCar) : type(type), horsepower(hp), containingCar(contCar) {}

	string Engine::get_type() const { return type; }
	int Engine::get_horsepower() const { return horsepower; }

	ostream& operator<<(ostream& out, const Engine& eng){
		out << eng.type << " " << eng.horsepower << "HP";
		return out;
	}

	bool operator== (const Engine& e1, const Engine& e2) {
		return e1.type == e2.type && e1.horsepower == e2.horsepower;
	}
	bool operator!= (const Engine& e1, const Engine& e2) {
		return e1.type != e2.type && e1.horsepower != e2.horsepower;
	}
}