#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <ostream>

namespace BrooklynPoly {
	class Student;

	class Course{
		friend std::ostream& operator<< (std::ostream& stream, const Course& crs);
	public:
		Course(const std::string& name);
		std::string get_name() const;
		void add_student(Student* student);
		void remove_student(Student* student);
		std::vector<Student*>& get_students();
	private:
		std::string name;
		std::vector<Student*> students;
	};
}

#endif