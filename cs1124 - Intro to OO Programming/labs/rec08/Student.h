#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <ostream>

namespace BrooklynPoly {
	class Course;

	class Student {
		friend std::ostream& operator<< (std::ostream& stream, const Student& stud);
	public:
		Student(const std::string& name);
		std::string get_name() const;
		void set_name(const std::string& newName);
		void join_course(Course* course);
		void leave_course(Course* course);
		std::vector<Course*>& get_courses();
	private:
		std::string name;
		std::vector<Course*> courses;
	};
}

#endif