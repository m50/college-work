/**
 * homework 08
 * Developed by: Marisa Clardy 0486223
 * Date: 5/1/13
 * Description: Polynomial Class using linked lists
 */

#include "polynomial.h"
#include <iostream>

using namespace hw08;
using namespace std;

int main () {
	double p1val [5] = {5,2.5,0,5,1};
	double p2val [2] = {2,3};
	Polynomial p1(5, p1val);
	Polynomial p2(2, p2val);
	Polynomial p3 = p1;

	cout << "p1(x) = " << p1 << endl
			<< "p2(x) = " << p2 << endl
			<< "p3(x) = " << p3 << endl;
	cout << "(p1 == p3) = " << (p1 == p3) << endl
			<< "(p1 != p2) = " << (p1 != p2) << endl
			<< "(p1 == p2) = " << (p1 == p2) << endl;
	p1 += p2;
	cout << "p1(x) = " << p1 << endl;
	cout << "p3(2) = " << p3.evaluate(2) << endl;
	cout << "p1(3.8) = " << p1.evaluate(3.8) << endl;

	Polynomial p4 = (p1 + p2);
	cout << "p4(x) = (p1(x) + p2(x)) = " << p4 << endl;
}
