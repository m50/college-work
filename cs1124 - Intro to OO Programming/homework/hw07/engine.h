#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <iostream>

namespace PolyAuto {
	class Car;

	class Engine {
	public:
		Engine(const std::string& type, int hp, Car* contCar = nullptr);

		std::string get_type() const;
		int get_horsepower() const;

		friend std::ostream& operator<<(std::ostream& out, const Engine& eng);
		friend bool operator== (const Engine& e1, const Engine& e2);
		friend bool operator!= (const Engine& e1, const Engine& e2);
	private:
		std::string type;
		int horsepower;
		Car* containingCar;
	};

}

#endif