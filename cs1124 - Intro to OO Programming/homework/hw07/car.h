#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include <iostream>

namespace PolyAuto {
	class Wheel;
	class Engine;

	class Car {
	public:
		Car (std::string make, std::string model, int year, std::string color, std::string engineType, 
				int horsepower, int numWheels, std::string wheelMaker, int wheelDiam);
		Car (Car ori);
		~Car ();

		Engine* removeEngine();
		Wheel* removeWheel(size_t at);
		void setEngine(Engine* eng);
		void setWheel(Wheel* wheel, size_t at);

		Car& operator=(const Car& rhs);
		friend std::ostream& operator<< (std::ostream& out, const Car& car);
		friend bool operator== (const Car& c1, const Car& c2);
		friend bool operator!= (const Car& c1, const Car& c2);
	private:
		std::string make;
		std::string model;
		int year;
		std::string color;

		Engine* engine;
		std::vector<Wheel*> wheels;
	};
}

#endif