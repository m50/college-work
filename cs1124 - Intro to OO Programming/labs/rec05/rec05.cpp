/*
Name: rec05 -
Author: Marisa Clardy (0486223)
Date: 2/15/13
Description:
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TimeSlot {
public:
	TimeSlot(string day, int hour) : day(day), hour(hour) {}
	void display() const {
		cout << day;
		int tempHour(hour);
		string ampm = "am";
		if(hour > 12) {
			tempHour -= 12;
			ampm = "pm";
		}
		cout << " " << tempHour << ":00" << ampm << endl;
	}
private:
	string day;
	int hour;
};

class Student {
public:
	Student(string name) : name(name), grades(13,-1) {}

	string get_name() const { return name; }

	void add_grade (size_t loc, int grade) { grades[loc-1] = grade; }
	void display() const {
		cout << "Student: " << name << "; Grades:  ";
		for(int gr : grades) {
			cout << gr << "  ";
		}
		cout << endl;
	}
	int get_grade(size_t gradeNum) { return grades[gradeNum]; }
private:
	string name;
	vector<int> grades;
};

class Section {
public:
	Section(string n, string day, int hour) : name(n), timeSlot(day, hour) {}
	void display () const {
		cout << "Section: " << name << "; ";
		timeSlot.display();
		for(Student* s : students) {
			s->display();
		}
		cout << endl;
	}
	void reset();
	void add_student(string name) { students.push_back(new Student(name)); }
	void add_grade(string stuName, size_t loc, int grade) {
		for(Student* stu : students){
			if(stu->get_name() == stuName) {
				stu->add_grade(loc, grade);
			}
		}
	}
	string get_name() const { return name; }
	vector<Student*> get_students() const { return students; }
private:
	string name;
	TimeSlot timeSlot;
	vector<Student*> students;
};

void Section::reset() {
	for(Student* s : students) {
		delete s;
	}
	students.clear();
}

class LabWorker {
public:
	LabWorker(string name) : name(name), section(nullptr) {}
	void assign_section (Section& sect) {section = &sect; }
	void add_grade (string stuName, int grade, size_t loc) { section->add_grade(stuName, loc, grade); }
	void add_section(Section& sect) { section = &sect; }
	void display_grades() const {
		cout << name << " has ";
		section->display();
	}
	void display_average_for_week(int week) const {
		cout << "Average for section " << section->get_name() << " for week " << week << " is: ";
		double totalGrade = 0;
		for(Student* student : section->get_students()) {
			totalGrade += student->get_grade(week - 1);
		}
		double avg = totalGrade / (double)(section->get_students().size());
		cout << avg << endl;
	}
private:
	string name;
	Section* section;
};

int main() {
   // lab workers
   LabWorker moe( "Moe" );
   LabWorker jane( "Jane" );

   // sections and setup and testing
   Section secA2( "A2", "Tuesday", 16 );
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.add_student("John");
   secA2.add_student("George");
   secA2.add_student("Paul");
   secA2.add_student("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.add_section( secA2 );
   moe.display_grades();       // here the modeler-programmer checks that adding the Section worked

   Section secB3( "B3", "Thursday", 11 );
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.add_student("Thorin");
   secB3.add_student("Dwalin");
   secB3.add_student("Balin");
   secB3.add_student("Kili");
   secB3.add_student("Fili");
   secB3.add_student("Dori");
   secB3.add_student("Nori");
   secB3.add_student("Ori");
   secB3.add_student("Oin");
   secB3.add_student("Gloin");
   secB3.add_student("Bifur");
   secB3.add_student("Bofur");
   secB3.add_student("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.add_section( secB3 );
   jane.display_grades();      // here the modeler-programmer checks that adding Instructor worked


   // setup is complete, now a real world scenario can be written in the code
   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

   // week one activities
   cout << "\nModeling week: 1\n";
   moe.add_grade( "John", 7, 1 );
   moe.add_grade( "Paul", 9, 1 );
   moe.add_grade( "George", 7, 1 );
   moe.add_grade( "Ringo", 7, 1 );
   cout << "End of week one\n";
   moe.display_grades();

   // week two activities
   cout << "\nModeling week: 2\n";
   moe.add_grade( "John", 5, 2 );
   moe.add_grade( "Paul", 10, 2 );
   moe.add_grade( "Ringo", 0, 2 );
   cout << "End of week two\n";
   moe.display_grades();
   moe.display_average_for_week(2);

   //test that reset works  // NOTE: can we check that the heap data was dealt with?
   cout << "\ntesting reset()\n";
   secA2.reset();
   secA2.display();
   moe.display_grades();
} // main
