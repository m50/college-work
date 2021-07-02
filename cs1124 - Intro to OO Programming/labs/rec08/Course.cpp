#include "Course.h"
#include "Student.h"
#include <iostream>
using namespace std;

namespace BrooklynPoly {
	Course::Course(const string& name) : name(name) {}
	string Course::get_name() const { return name; }
	void Course::add_student(Student* student) {
		students.push_back(student);
	}
	void Course::remove_student(Student* student){		
		for(size_t i = 0; i < students.size(); ++i){
			Student* stud = students[i];
			if (stud->get_name() == student->get_name()) {
				cout << stud;
				Student* stud2 = students.back();
				students[students.size() - 1] = stud;
				students[i] = stud2;
				break;
			}
		}
		if(students.back() == student) students.pop_back();
	}
	vector<Student*>& Course::get_students() { return students; }

	//OPERATORS
	ostream& operator<< (ostream& stream, const Course& crs){
		stream << "Course: " << crs.get_name() << " has students:";
		for(Student* stud : crs.students){
			stream << "\n\t - " << stud->get_name();
		}
		return stream;
	}
}