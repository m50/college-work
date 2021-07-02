#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace CS1124 {
	class Rational {
	public:
		Rational(int, int);
		Rational(int = 0);

		void normalize();

		int get_numerator() const;
		int get_denominator() const;
		void set_numerator(int);

		friend std::ostream& operator<<(std::ostream& stream, const Rational& rat);
		friend std::istream& operator>>(std::istream& stream, Rational& rat);
		Rational& operator+=(const Rational& rhs);
		Rational& operator++();
		Rational operator++(int);
	private:
		int num;
		int denom;
	};

	Rational operator+(Rational& lhs, Rational& rhs);
	bool operator==(const Rational& lhs, const Rational& rhs);
	bool operator!=(const Rational& lhs, const Rational& rhs);
	Rational& operator--(Rational& rat);
	Rational operator--(Rational& rat, int);
}

#endif