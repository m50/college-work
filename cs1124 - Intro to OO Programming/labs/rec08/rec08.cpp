#include "Registrar.h"
using namespace BrooklynPoly;

int main() {

   Registrar r;

   // PrintReport
   r.print_report(); // or cout << r << endl;
     
   // add_course CS101.001
   r.add_course("CS101.001");

   // print_report
   r.print_report(); // or cout << r << endl;
   // add_student FritzTheCat
   r.add_student("FritzTheCat");

   // print_report
   r.print_report(); // or cout << r << endl;
   // AddCourse CS102.001
   r.add_course("CS102.001");

   // print_report
   r.print_report(); // or cout << r << endl;
   // EnrollStudentInCourse FritzTheCat CS102.001
   r.enroll_student_in_course("FritzTheCat", "CS102.001");

   // print_report
   r.print_report(); // or cout << r << endl;
   // enroll_student_in_course Bullwinkle CS101.001
   r.enroll_student_in_course("Bullwinkle", "CS101.001");

   // print_report
   r.print_report(); // or cout << r << endl;
   // cancel_course CS102.001
   r.cancel_course("CS102.001");

   // print_report
   r.print_report(); // or cout << r << endl;

   // ChangeStudentName FritzTheCat MightyMouse
   r.change_student_name("FritzTheCat", "MightyMouse");

   // PrintReport
   r.print_report(); // or cout << r << endl;

   // DropStudentFromCourse MightyMouse CS101.001
   r.drop_student_from_course("MightyMouse", "CS101.001");
   // print_report
   r.print_report(); // or cout << r << endl;

   // RemoveStudent FritzTheCat
   r.remove_student("FritzTheCat");
   // print_report
   r.print_report(); // or cout << r << endl;

   // Purge for start of next semester
   r.purge();
   // print_report
   r.print_report();
}