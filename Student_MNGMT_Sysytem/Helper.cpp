#include "Helper.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void Helper::addStudent() {



    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    for (Student& s : students)
        if (s.getID() == id) { cout << "Error: Student ID already exists!\n"; return; }

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter GPA (0.0 - 4.0): "; cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) { cout << "Invalid GPA!\n"; return; }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}




void Helper::removeStudent(int id) {

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getID() == id) {
            students.erase(students.begin() + i);
            cout << "Student removed successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";

}




Student* Helper::searchStudent(int id) {

    for (Student& s : students) if (s.getID() == id) return &s;
    return nullptr;
}




void Helper::displayAllStudents() {

    if (students.empty()) { cout << "No students to display.\n"; return; }
    for (Student& s : students) s.displayStudentInfo();
}





void Helper::enrollStudentInCourse(int id, const string& courseName) {

    Student* s = searchStudent(id);
    if (s) s->addCourse(courseName);
    else cout << "Student not found.\n";
}




void Helper::showCoursesOfStudent(int id) {

    Student* s = searchStudent(id);
    if (s) s->showCourses();
    else cout << "Student not found.\n";
}




void Helper::sortStudentsByGPA() {

    sort(students.begin(), students.end(), [](Student& a, Student& b) { return a.getGPA() > b.getGPA(); });
    cout << "Students sorted by GPA.\n";
    displayAllStudents();
}








void Helper::saveToFile(const string& filename) {
    ofstream out(filename);
    for (Student& s : students) s.saveToFile(out);
    cout << "Saved to file.\n";
}





void Helper::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) { cout << "File not found.\n"; return; }
    students.clear();
    while (in.peek() != EOF) {
        Student s;
        s.loadFromFile(in);
        students.push_back(s);
    }
    cout << "Loaded from file.\n";

}