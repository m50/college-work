/*
Name: rec02 - Hydrocarbons
Author: Marisa Clardy (0486223)
Date: 2/8/13
Description: read, store, sort, and display hydrocarbons
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Hydrocarbon
{
	Hydrocarbon (int carbon, int hydrogen) : carbons(carbon), hydrogens(hydrogen) {} // constructor
	void add_name (const string& name) { // adds names to the names vector
		names.push_back(name);
	}
	void display () const {
		cout << "C" << carbons << "H" << hydrogens << endl << "\t";
		for (size_t index = 0; index < names.size(); ++index) {
			cout << names[index];
			if (index != names.size() - 1) // puts semicolon and a space between each name
				cout << "\n\t";
			else
				cout << endl;
		}
	}
	int get_hydrogens() const { return hydrogens; }
	int get_carbons() const { return carbons; }
private: // private because proper programming practice
	vector<string> names;
	int carbons, hydrogens;
};

//findHydrocarbon is overloaded to take both a hydrogen and a carbon or just a carbon
//	this is needed so for the sort
size_t findHydrocarbon(const vector<Hydrocarbon>& hydrocarbons, int hydr, int carb){
	for (size_t i = 0; i < hydrocarbons.size(); ++i) {
		if (hydrocarbons[i].get_hydrogens() == hydr &&
			hydrocarbons[i].get_carbons() == carb)
			return i;
	}

	return hydrocarbons.size();
}
size_t findHydrocarbon(const vector<Hydrocarbon>& hydrocarbons, int carb){
	for (size_t i = 0; i < hydrocarbons.size(); ++i) {
		if (hydrocarbons[i].get_carbons() == carb)
			return i;
	}

	return hydrocarbons.size();
}

vector<Hydrocarbon> sortHydrocarbonsByCarbon(const vector<Hydrocarbon>& hcs) {
	int largestCarb = 0;
	for (Hydrocarbon hc : hcs) { // find the largest number of carbons to count to
		if (hc.get_carbons() > largestCarb)
			largestCarb = hc.get_carbons();
	}

	vector<Hydrocarbon> newList;

	for (int i = 1; i <= largestCarb; ++i) { // sort through number of carbons
		size_t pos = findHydrocarbon(hcs, i);
		if(pos != hcs.size()) { // only if there is a hydrocarbon at carbon
			newList.push_back(hcs[pos]);
		}
	}

	return newList;
}

int main() {
	ifstream ifs("hydrocarbons.txt");
	if (!ifs) {
		cerr << "Did not open file";
		exit(1);
	}

	vector<Hydrocarbon> hydrocarbons;

	string name;
	char junk;
	int hydr, carb;
	while (ifs >> name >> junk >> hydr >> junk >> carb) { // separate the C#H# into hydrogens and carbons
		size_t hydrcarbPos = findHydrocarbon(hydrocarbons, hydr, carb);
		if (hydrcarbPos != hydrocarbons.size()) { // hydrocarbon with formula exists
			hydrocarbons[hydrcarbPos].add_name(name);
		}
		else { // hydrocarbon doesn't already exist
			Hydrocarbon tempHc(hydr, carb);
			tempHc.add_name(name);
			hydrocarbons.push_back(tempHc);
		}
	}

	vector<Hydrocarbon> sortedHcs = sortHydrocarbonsByCarbon(hydrocarbons);

	for (const Hydrocarbon& hc : sortedHcs) {
		hc.display();
	}

	ifs.close();
}
