#pragma once
#include <string>
#include <set>
#include <iostream>
using namespace std;



class Student {
private:
    int id;
    string name;
    double gpa;
    set<string> courses;

public:
    Student() : id(0), name(""), gpa(0.0) {} // default constructor needed for file load
    Student(int id, string name, double gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;


    }

    int getID();
    string getName();
    double getGPA();

    void addCourse(const string& courseName);
    void showCourses();
    void displayStudentInfo();

    // File handling
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
};