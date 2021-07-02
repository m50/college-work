#include "car.h"
#include "engine.h"
#include "wheel.h"

using namespace std;

namespace PolyAuto {
	Car::Car (string make, string model, int year, string color, string engineType, int horsepower, int numWheels, string wheelMaker, int wheelDiam) 
			: make(make), model(model), year(year), color(color), engine(new Engine(engineType, horsepower, this)), wheels(numWheels, new Wheel(wheelMaker, wheelDiam)) { }
			// for (int i = 0; i < numWheels; ++i) {
			// 	wheels.push_back(new Wheel(wheelMaker, wheelDiam));
			// }
		}
	Car::Car(const Car& ori) {
		engine = new Engine(ori.engine->get_type(), ori.engine->get_horsepower(), this);
		for(Wheel* whl : ori.wheels) {
			wheels.push_back(new Wheel("", 0)); //FINISH THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
	Car::~Car () {
		delete engine;
		for (size_t i = 0; i < wheels.size(); ++i) {
			delete wheels[i];
		}
		wheels.clear();
	}

	Engine* Car::removeEngine() {
		if(engine) {
			Engine* retEng = engine;
			engine = nullptr;
			return retEng;
		}
		else {
			cerr << "Car has no engine to remove." << endl;
			return nullptr;
		}
	}

	Wheel* Car::removeWheel(size_t at) {
		if(at < wheels.size() && wheels[at]) {
			Wheel* retWhl = wheels[at];
			wheels[at] = nullptr;
			return retWhl;
		}
		else {
			cerr << "Car has no wheel at position " << at << " to remove." << endl;
			return nullptr;
		}
	}

	void Car::setEngine(Engine* eng) {
		if(!engine) { 
			engine = eng; 
			return;
		}
		cerr << "Car already has an engine." << endl;
	}
	void Car::setWheel(Wheel* wheel, size_t at) {
		if(at >= wheels.size()){
			cerr << at << " is outside the number of wheels that the car can hold." << endl;
			return;
		}
		if(!wheels[at]) { 
			wheels[at] = wheel; 
			return;
		}
		cerr << "Car already has a wheel at position " << at << "." << endl;
	}

	Car& Car::operator=(const Car& rhs) { {
		if(&rhs == this) return;
		return Car(rhs);
	}

	ostream& operator<< (ostream& out, const Car& car) {
		out << car.color << " " << car.year << " " << car.make << " " << car.model << " ";
		(car.engine != nullptr) ? out << "\n\tEngine: " << *car.engine : out << "\n\tEngine: None";
		out << "\n\tWheels: ";
		for(Wheel* whl : car.wheels) {
			(whl != nullptr) ? out << "\n\t - " << *whl : out << "\n\t - None";
		}
		return out;
	}

	bool operator== (const Car& c1, const Car& c2) {
		return (c1.make == c2.make && c1.year == c2.year && c1.model == c2.model &&
			c1.color == c2.color && c1.wheels.size() == c2.wheels.size() &&
			*c1.engine == *c2.engine);
	}
	bool operator!= (const Car& c1, const Car& c2) {
		return (c1.make != c2.make || c1.year != c2.year || c1.model != c2.model ||
			c1.color != c2.color || c1.wheels.size() != c2.wheels.size() ||
			*c1.engine != *c2.engine);
	}
}