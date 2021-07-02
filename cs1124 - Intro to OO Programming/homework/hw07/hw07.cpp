#include "car.h"
#include "engine.h"
#include "wheel.h"

#include <iostream>

using namespace PolyAuto;
using namespace std;

int main() {
	Car* bmw  = new Car("BMW",  "Z4", 		2006, "Black",  "V6", 140, 4, "Michelen", 18);
	Car* bmw2 = new Car("BMW",  "Z4", 		2006, "Black",  "V6", 140, 4, "Michelen", 18);
	Car* ford = new Car("Ford", "Taurus", 	2001, "Silver", "V6", 140, 4, "Michelin", 18);

	cout << "Parking lot:" << endl;
	cout << "BMWs:" << endl << *bmw << endl << *bmw2 << endl << endl << "Fords:" << endl << *ford << endl;
	cout << "bmw != ford: " << (*bmw != *ford) << endl;
	cout << "bmw != bmw2: " << (*bmw != *bmw2) << endl;
	cout << "bmw == bmw2: " << (*bmw == *bmw2) << endl << endl;

	delete bmw2->removeEngine();
	cout << *bmw2 << endl;
	bmw2->removeEngine();
	bmw2->setEngine(new Engine("V2", 20));
	cout << *bmw2 << endl;
	bmw2->setEngine(new Engine("V2", 20));

	delete ford->removeWheel(2);
	cout << *ford << endl;
	ford->removeWheel(2);
	ford->setWheel(new Wheel("Bob", 300), 2);
	cout << *ford << endl;
	ford->setWheel(new Wheel("Bob", 200), 1);

	cout << "bmw == bmw2: " << (*bmw == *bmw2) << endl;	

	delete bmw2;
	delete bmw;
	delete ford;

	cout << "Parking lot:" << endl;
	// cout << "BMWs:" << endl << *bmw << endl << *bmw2 << endl << endl << "Fords:" << endl << *ford << endl; // segmentation fault because none of the pointers actually point anywhere anymore
}