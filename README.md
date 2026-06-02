3. README
Project Structure
SCMS/
  main.cpp        -> Entry point and menu logic
  Student.h       -> Student class declaration
  Student.cpp     -> Student class implementation
  Helper.h        -> Helper class declaration
  Helper.cpp      -> Helper class implementation
  students.txt    -> Auto-generated data file (after saving)

How to Compile & Run
Requirements: C++17 or later  |  g++ compiler

# Compile
g++ -std=c++17 -o scms main.cpp Student.cpp Helper.cpp

# Run
./scms

Menu Options
#	Option
1	Add Student
2	Remove Student
3	Search Student
4	Display All Students
5	Enroll Student in Course
6	Show Student Courses
7	Sort Students by GPA
8	Exit

STL Used
Container / Algorithm	Purpose
set<string>	Stores courses per student — prevents duplicates automatically
vector<Student>	Stores all students in the Helper class
sort()	Sorts students by GPA in descending order
find_if()	Searches for a student by ID in the vector

Validation Rules
•	Student ID must be unique
•	GPA must be between 0.0 and 4.0
•	Student name cannot be empty
•	Duplicate courses are silently ignored (handled by set<string>)

File I/O
helper.saveToFile("students.txt");   // Save all students
helper.loadFromFile("students.txt"); // Load on next run

Example Usage
Enter Student ID: 1001
Enter Name: Ali Hassan
Enter GPA: 3.5
Student added successfully.

Enter Student ID: 1001
Enter Course: Math 101
Enrolled successfully.
 
