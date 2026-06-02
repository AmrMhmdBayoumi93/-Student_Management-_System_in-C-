#pragma once
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class Helper {

private:

    vector<Student> students;

public:
    void addStudent();
    void removeStudent(int id);
    Student* searchStudent(int id);
    void displayAllStudents();
    void enrollStudentInCourse(int id, const string& courseName);
    void showCoursesOfStudent(int id);
    void sortStudentsByGPA();

    // File handling
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);


};