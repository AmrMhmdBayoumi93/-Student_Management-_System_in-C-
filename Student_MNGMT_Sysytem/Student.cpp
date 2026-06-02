#include "Student.h"
 
#include <iostream>
#include <fstream>
using namespace std;

int Student::getID() { return id; }
string Student::getName() { return name; }
double Student::getGPA() { return gpa; }

void Student::addCourse(const string& courseName) {
    courses.insert(courseName);
}

void Student::showCourses() {
    if (courses.empty()) {
        cout << "No courses enrolled yet.\n";
        return;
    }
    cout << "Courses for " << name << ": ";
    for (const string& c : courses) cout << c << "  ";
    cout << endl;
}

void Student::displayStudentInfo() {
    cout << "ID: " << id << "\nName: " << name << "\nGPA: " << gpa << endl;
}










////////////////////////////////



// File handling
void Student::saveToFile(ofstream& out) const {
    out << id << endl;
    out << name << endl;
    out << gpa << endl;
    out << courses.size() << endl;
    for (const string& c : courses) out << c << endl;
}

void Student::loadFromFile(ifstream& in) {
    int courseCount;
    in >> id; in.ignore();
    getline(in, name);
    in >> gpa; in.ignore();
    in >> courseCount; in.ignore();
    courses.clear();
    for (int i = 0; i < courseCount; i++) {
        string c; getline(in, c);
        courses.insert(c);
    }
}