#include "Position.h"

using namespace std;

namespace rec09 {
	Position::Position(const string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}
	string Position::getTitle() const {return title;}
	double Position::getSalary() const {return salary;}
	void Position::changeSalaryTo(double d) {salary = d;}
}