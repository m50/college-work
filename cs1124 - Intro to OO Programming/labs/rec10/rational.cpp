#include "rational.h"

using namespace std;

namespace CS1124 {
	//Accessors
	int Rational::get_numerator() const { return num; }
	int Rational::get_denominator() const { return denom; }
	void Rational::set_numerator(int nu) { num = nu; }

	//helpers
	int gcd(int n, int d) {
		while (d != 0) {
			int temp = n % d;
			n = d;
			d = temp;
		}
		return n;
	}
	void Rational::normalize() {
		if((num < 0 && denom < 0) || (num > 0 && denom < 0)) {
			num *= -1;
			denom *= -1;	
		}
	}

	//A few constructors
	Rational::Rational(int nu) : num(nu), denom(1) {}
	Rational::Rational(int nu, int de) {
		int g = gcd(nu, de);
		num = nu / g;
		denom = de / g;
		normalize();
	}

	//Member Operators
	Rational& Rational::operator+=(const Rational& rhs) {
		if(rhs.denom == denom) {
			num += rhs.num;
			return *this;	
		}

		num *= rhs.denom;
		num += rhs.num * denom;
		denom *= rhs.denom;
		normalize();
		int g = gcd(num, denom);

		num /= g;
		denom /= g;

		normalize();

		return *this;
	}
	Rational& Rational::operator++() {
		num += denom;
		return *this;
	}
	Rational& operator--(Rational& rat) {
		rat.set_numerator(rat.get_numerator() - rat.get_denominator());
		return rat;
	}
	Rational Rational::operator++(int) {
		Rational cpy = *this;
		num += denom;
		return cpy;
	}
	Rational operator--(Rational& rat, int) {
		Rational cpy = rat;
		rat.set_numerator(rat.get_numerator() - rat.get_denominator());
		return cpy;
	}

	//Non Member Operators
	Rational operator+(Rational& lhs, Rational& rhs) {
		return lhs += rhs;
	}
	bool operator==(const Rational& lhs, const Rational& rhs) {
		return lhs.get_numerator() == rhs.get_numerator() && lhs.get_denominator() == rhs.get_denominator();
	}
	bool operator!=(const Rational& lhs, const Rational& rhs) {
		return lhs.get_numerator() != rhs.get_numerator() && lhs.get_denominator() != rhs.get_denominator();
	}
	ostream& operator<<(ostream& stream, const Rational& rat) {
		if(rat.num % rat.denom == 0) return stream << rat.num / rat.denom;

		stream << rat.num;
		if(rat.denom != 1) stream << "/" << rat.denom;
		return stream;
	}
	istream& operator>>(istream& stream, Rational& rat) {
		char garbage;
		stream >> rat.num >> garbage >> rat.denom;
		rat.normalize();
		int g = gcd(rat.num, rat.denom);
		rat.num /= g;
		rat.denom /= g;
		return stream;
	}
}