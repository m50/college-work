#include "Student.h"
#include "Course.h"

#include <iostream>

using namespace std;

namespace BrooklynPoly {
	Student::Student(const string& name) : name(name) {}
	string Student::get_name() const { return name; }
	void Student::join_course(Course* course) {
		course->add_student(this);
		courses.push_back(course);
	}
	void Student::leave_course(Course* course){
		for(size_t i = 0; i < courses.size(); ++i){
			Course* crs = courses[i];
			if (crs->get_name() == course->get_name()) {
				Course* crs2 = courses.back();
				courses[courses.size() - 1] = course;
				courses[i] = crs2;
				break;
			}
		}
		if(courses.back() == course) courses.pop_back();
	}
	void Student::set_name(const std::string& newName) {
		name = newName;
	}
	vector<Course*>& Student::get_courses() { return courses; }

	//OPERATORS
	ostream& operator<< (ostream& stream, const Student& stud){
		stream << "Student: " << stud.name << " is enrolled in:";
		for(Course* crs : stud.courses){
			stream << "\n\t - " << crs->get_name();
		}
		return stream;
	}
}