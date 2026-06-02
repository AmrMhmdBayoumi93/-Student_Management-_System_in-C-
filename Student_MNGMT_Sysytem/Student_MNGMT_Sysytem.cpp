#include <iostream>
#include "Helper.h"
using namespace std;

int main() {


    Helper h;
    int choice;
    string filename = "students.txt";

    h.loadFromFile(filename); // load existing data

    do {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Display All\n";
        cout << "5. Enroll Student in Course\n6. Show Student Courses\n7. Sort by GPA\n0. Exit\n";
        cout << "Choice: "; cin >> choice; cin.ignore();

        if (choice == 1) h.addStudent();
        else if (choice == 2) { int id; cout << "ID? "; cin >> id; h.removeStudent(id); }
        else if (choice == 3) {
            int id; cout << "ID? "; cin >> id;
            Student* s = h.searchStudent(id);
            if (s) s->displayStudentInfo(); else cout << "Student not found.\n";
        }
        else if (choice == 4) h.displayAllStudents();
        else if (choice == 5) {

            int id;
            string course;
            cout << "ID? ";
            cin >> id;
            cin.ignore();
            cout << "Course name? "; getline(cin, course);
            h.enrollStudentInCourse(id, course);
        }
        else if (choice == 6) { int id; cout << "ID? "; cin >> id; h.showCoursesOfStudent(id); }
        else if (choice == 7) h.sortStudentsByGPA();
        else if (choice == 0) break;
        else cout << "Invalid option.\n";

    } while (true);

    h.saveToFile(filename); // save all data
    return 0;
}


