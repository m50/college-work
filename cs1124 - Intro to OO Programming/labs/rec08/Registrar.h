#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <string>
#include <vector>
#include <ostream>

namespace BrooklynPoly {
	class Course;
	class Student;

	class Registrar {
		friend std::ostream& operator<< (std::ostream& stream, const Registrar& reg);
	public:
		Registrar();
		~Registrar();
		void print_report() const;
		void add_student(const std::string& studentName);
		void enroll_student_in_course(const std::string& studentName, const std::string& courseName);
		void add_course(const std::string& courseName);
		void cancel_course(const std::string& courseName);
		void change_student_name(const std::string& student, const std::string& newName);
		void drop_student_from_course(const std::string& student, const std::string& course);
		void remove_student(const std::string& student);
		void purge();
	private:
		Course* find_course(const std::string& courseName, bool rmv = false);
		Student* find_student(const std::string& studentName, bool rmv = false);
		std::vector<Course*> courses;
		std::vector<Student*> students;
	};
}

#endif