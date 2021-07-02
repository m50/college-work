/*
Name: rec06 - Inheritance
Author: Marisa Clardy (0486223)
Date: 2/15/13
Description:
*/

#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned nop) : numberOfPages(nop) {}
	virtual void displayNumPages() const { cout << numberOfPages << endl; }
protected:
private:
	unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned nop) : PrintedMaterial(nop) {}
	void displayNumPages() const {
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned nop) : PrintedMaterial(nop) {}
	void displayNumPages() const {
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned nop, unsigned noip) : Book(nop), numOfIndexPages(noip) {}
	void displayNumPages() const {
		//cout << numberOfPages; //WRONG!
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index Pages: ";
		cout << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned nop) : Book(nop) {}
	void displayNumPages() const {
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

void displayNumberOfPages (const PrintedMaterial& pm) {
	pm.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(5430, 23);
	Novel n(213);
	Magazine m(6);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
	cout << "Now with the virtual mechanism involved\n";
      // should work now that the virtual mechanism is being invoked
	PrintedMaterial* pmPtr;
	pmPtr = &t; // like putting t into a vector but
	            // we are actually putting the address of t
	            // into a vector pointers of pointers to
	            // PrintedMaterials. We'll "say" we are putting
	pmPtr->displayNumPages();

	// print some stuff by calling a generic function
	cout << "\nUse a generic functino for printing\n";
	displayNumberOfPages(m);
	displayNumberOfPages(n);
	displayNumberOfPages(t);
}
