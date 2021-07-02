#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <ostream>

namespace hw08 {
	class Polynomial {
	public:
		Polynomial(int deg, double coefficients[]);
		Polynomial(const Polynomial&);
		~Polynomial();

		double get_highest_degrees_coefficient() const;
		double get_coefficient_at(int) const;

		double evaluate(double x) const;

		Polynomial& operator+=(const Polynomial&);
		Polynomial operator=(const Polynomial&);
		
		friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
		friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	private:
		//Private internal struct
		struct Degree {
			Degree(double coeff, Degree* next = nullptr);
			Degree* next;
			double coefficient;
		} *head;
		int degree;
		
		//Private Functions
		void push_back(double);
		void push_front(double);
		void delete_back();
		void delete_front();
		void delete_at(int degree);
		Degree* duplicate() const;
		void clear();
		Degree* back() const;
		Degree* at(int pos) const;
	};

	Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
}

#endif