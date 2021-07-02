#ifndef WHEEL_H
#define WHEEL_H

#include <string>
#include <iostream>

namespace PolyAuto {
	class Wheel {
	public:
		Wheel(const std::string& maker, int rad);
		Wheel(Wheel oth);

		friend std::ostream& operator<<(std::ostream& out, const Wheel& eng);
	private:
		std::string maker;
		int radius;
	};
}

#endif