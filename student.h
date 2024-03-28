//Student.hpp
// c867-student-roster
//Created by Amber Ruiz

#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std;;endl;

class Student
{
public:
	const static int daysInCourseArray = 3;/*the size of an array must be constant; each student has 3 course t/lengths in days*/

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArray];
	DegreeType degreeType;

public:
	Student();/*parameterless construtor-sets to default values*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeType degreeType);/* Full construction */
	~Student();/*destructor*/

	/*getters aka accessors*/
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getdaysInCourse();
	DegreeType getDegreeType();

	/*setters aka mutators*/
	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdaysInCourse(int daysInCourse[]);
	void setDegreeType(DegreeType dt);

	static void printHeader();/*displays a header for the data to follow*/

	void print();/*displays 'this' student's data*/

};
