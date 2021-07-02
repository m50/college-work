
#include "wheel.h"

using namespace std;

namespace PolyAuto {
	Wheel::Wheel(const string& maker, int rad) : maker(maker), radius(rad) { }
	
	ostream& operator<<(ostream& out, const Wheel& wheel){
		out << wheel.maker << "; Radius: " << wheel.radius << "u";
		return out;
	}
}