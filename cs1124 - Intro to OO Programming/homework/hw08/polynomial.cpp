#include "polynomial.h"
#include <string>
#include <math.h>

using namespace std;

namespace hw08 {
	//--------------------------\\
	// Constructors/Destructors \\
	//--------------------------\\
	
	Polynomial::Degree::Degree(double coeff, Degree* next) : coefficient(coeff), next(next) {} // Constructor for our internal "Degree" Struct

	Polynomial::Polynomial(int deg, double coefficients[]) : degree(deg) {
		// passed in as highest->lowest, stored as lowest->highest in degree
		head = new Degree(coefficients[deg]);
		for(int i = deg; i >= 0; --i) {
			push_front(coefficients[i]);
		}
	}
	Polynomial::Polynomial(const Polynomial& poly) {
		head = poly.duplicate(); 	// copy from the one we are copying (boy, that was weird english)
		degree = poly.degree;
	}
	Polynomial::~Polynomial() {
		clear(); 					// in a destructor, delete all heap memory allocated, this is what clear does as well.
	}

	//------------------\\
	// Public Functions \\
	//------------------\\
	
	double Polynomial::get_highest_degrees_coefficient() const {
		return back()->coefficient; // gets the last one's coefficient
	}
	double Polynomial::get_coefficient_at(int loc) const {
		Degree* curDeg = head;
		for(size_t i = 0; i < loc; ++i) {
			if(curDeg->next != NULL) curDeg = curDeg->next; else break;
		}
		return curDeg->coefficient;
	}
	double Polynomial::evaluate(double x) const {
		double value = 0;
		Degree* cur = head;
		for(size_t i = 0; i <= degree; ++i) {
			value += pow(x, i) * cur->coefficient;
			cur = cur->next;
		}
		return value;
	}

	//-------------------\\
	// Private Functions \\
	//-------------------\\
	
	void 	Polynomial::push_back(double coeff) {
		back()->next = new Degree(coeff);		// Add a new one right on the end
	}
	void 	Polynomial::push_front(double coeff) {
		head = new Degree(coeff, head);			// Add a new Head, easy peasy
	}
	void 	Polynomial::delete_back() {
		Degree* delete_pos = back();
		delete delete_pos;						// Delete back
		back()->next = nullptr;					// Fix the new back's next field
	}
	void 	Polynomial::delete_front() {
		Degree* delete_pos = head;
		head = head->next;
		delete delete_pos;
	}
	void 	Polynomial::delete_at(int degree) {
		Degree* delete_pos = head;
		Degree* pos_before = nullptr;
		for(int i = 0; i < degree; ++i) {
			if(i == degree - 2) {
				pos_before = delete_pos;
			}			
			delete_pos = delete_pos->next;
		}
		pos_before->next = delete_pos->next;
		delete delete_pos;
	}
	Polynomial::Degree* Polynomial::duplicate() const {
		Degree* step = head->next;
		Degree* last = new Degree(head->coefficient);
		Degree* result = last;

		while(step != nullptr) {
			last->next = new Degree(step->coefficient);
			step = step->next;
			last = last->next;
		}

		return result;
	}
	void	Polynomial::clear() {
		Degree* delete_pos = head;
		Degree* next = delete_pos->next;
		while(next != nullptr) {
			delete delete_pos;
			delete_pos = next;
			next = next->next;
		}
	}
	Polynomial::Degree* Polynomial::back() const {
		Degree* end = head;
		while(end->next != nullptr) {
			end = end->next;
		}
		return end;
	}
	Polynomial::Degree* Polynomial::at(int pos) const {
		Degree* degAt = head;
		for(int i = 0; i < pos; ++i) {
			degAt = degAt->next;
		}
		return degAt;
	}

	//-----------\\
	// Operators \\
	//-----------\\
	
	ostream& operator<<(ostream& os, const Polynomial& poly) {
		for(int i = poly.degree; i >= 0; --i) {
			float curCoeff = poly.at(i)->coefficient;
			if(curCoeff == 0) continue;

			if(curCoeff != 1)
				os << curCoeff;
			if(i > 0) {
				os << "x";
				if(i > 1) os << "^" << i;
			}
			if(i != 0) os << "+";
		}
		return os;
	}
	Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
		Degree* curDeg = head;
		Degree* rhsDeg = rhs.head;
		for(size_t i = 0; i < rhs.degree; ++i) {
			if(curDeg->next == nullptr && rhsDeg->next != nullptr)
				curDeg->next = new Degree(rhsDeg->coefficient);
			else
				curDeg->coefficient += rhsDeg->coefficient;

			curDeg = curDeg->next;
			rhsDeg = rhsDeg->next;
		}
		return *this;
	}
	Polynomial Polynomial::operator=(const Polynomial& poly) {
		if(this == &poly) return *this;
		clear(); 					// delete everything already allocated
		head = poly.duplicate(); 	// copy from the one we are copying (boy, that was weird english)
		degree = poly.degree;
		return *this;
	}

	Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
		Polynomial ans(lhs);
		ans += rhs;
		return ans;
	}
	bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		if(lhs.degree != rhs.degree) return false;

		for(size_t i = 0; i < lhs.degree; ++i) {
			if(lhs.get_coefficient_at(i) != rhs.get_coefficient_at(i))
				return false;
		}

		return true;
	}
	bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
		return !(lhs == rhs);
	}
}