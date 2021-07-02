#include "Registrar.h"
#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

namespace BrooklynPoly {
	Registrar::Registrar() {}
	Registrar::~Registrar() {
		purge();
	}
	void Registrar::print_report() const {
		cout << *this << endl;
	}
	void Registrar::add_student(const string& studentName) { 
		students.push_back(new Student(studentName));
	}
	void Registrar::enroll_student_in_course(const string& studentName, const string& courseName) { 
		if(!find_student(studentName)){
			cerr << "No student with name " << studentName << endl;
			return;
		}

		find_student(studentName)->join_course(find_course(courseName));
	}
	void Registrar::add_course(const string& courseName) { 
		courses.push_back(new Course(courseName));
	}
	void Registrar::cancel_course(const string& courseName) {
		for(Student* stud : students){
			Course* crs = find_course(courseName);
			if(crs) stud->leave_course(crs);
		} 
		delete find_course(courseName, true);
	}
	void Registrar::change_student_name(const std::string& student, const std::string& newName) {
		find_student(student)->set_name(newName);
	}
	void Registrar::drop_student_from_course(const std::string& student, const std::string& course) {
		Course* crs = find_course(course);
		for(Student* stud : crs->get_students()) {
			if(stud->get_name() == student)
			{
				crs->remove_student(find_student(student));
				return;
			}
		}
		cerr << "No student in course " << course << " with name " << student << endl;

	}
	void Registrar::remove_student(const std::string& student) {
		for(Course* crs : courses){
			Student* stud = find_student(student);
			if(stud) crs->remove_student(stud);
		} 
		delete find_student(student, true);
	}
	void Registrar::purge() {
		for(Student* std : students) delete std;
		for(Course* crs : courses) delete crs;
		students.clear();
		courses.clear();
	}

	//PRIVATES
	Course*  Registrar::find_course(const string& courseName, bool rmv) { 
		Course* crs = nullptr;
		for(size_t i = 0; i < courses.size(); ++i) {
			crs = courses[i];
			if(crs->get_name() == courseName){
				if(rmv) {
					Course* crs2 = courses.back();
					courses[courses.size() - 1] = crs;
					courses[i] = crs2;
				}
				break;
			}
			crs = nullptr;
		}
		if(rmv && crs) courses.pop_back();
		return crs;
	}
	Student* Registrar::find_student(const string& studentName, bool rmv) { 
		Student* stud = nullptr;
		for(size_t i = 0; i < students.size(); ++i) {
			stud = students[i];
			if(stud->get_name() == studentName){
				if(rmv) {
					Student* stud2 = students.back();
					students[students.size() - 1] = stud;
					students[i] = stud2;
				}
				break;
			}
			stud = nullptr;
		}
		if(rmv && stud) students.pop_back();
		return stud;
	}

	//OPERATORS
	ostream& operator<< (ostream& stream, const Registrar& reg) {
		stream << reg.students.size() << " Student(s):";
		for(Student* stud : reg.students)
			stream << "\n\t" << *stud;
		stream << endl << reg.courses.size() << " Courses(s):";
		for(Course* crs : reg.courses)
			stream << "\n\t" << *crs;

		return stream;
	}
}