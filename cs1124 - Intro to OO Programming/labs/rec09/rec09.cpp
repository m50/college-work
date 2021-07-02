/*
  Recitation 09
  CS1124
  Marisa Clardy (0486223)
  4/5/2013

  Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>

#include "Directory.h"
#include "Entry.h"
#include "Position.h"

using namespace std;
using namespace rec09;

int main() {

	// Model as if there are these four kinds
	// of position in the problem:
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	//
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	d.add("Boo", 0, 4444, peon);
	d.add("blah", 15, 21234, pointyHair);
	Directory d2 = d;			// copy constructor gets called here
	d2.add("Gallagher", 111, 2222, techie);
	Directory d3;
	d3 = d2; //assignment operator gets called here

	cout << d3["Gallagher"] << endl;		//
	cout << d2["Boo"] << endl;			// Testing the [] operator
	cout << d["Marilyn"] << endl;			//
}

