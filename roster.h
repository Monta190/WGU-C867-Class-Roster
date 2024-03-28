//roster.h
// c867-student-roster
//Created by Amber Ruiz

#pragma once
#include "student.h" 

class roster
{
private:
	int lastIndex = -1;
	const static int studentDataTable = 5;
	Student* classRosterArray[studentDataTable];

public:
	/*parse method parses set of comma delimited strings and extracts data*/
	void parse(string row);
	/*pulls student data and creates student object in roster*/
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int Age, 
		int daysInCourse0,
		int daysInCourse1,
		int daysInCourse2,
		DegreeType dt);
	/*once student object created, can call functions on it*/
	void printAll();/*call print() for each student*/
	void printByDegreeType(DegreeType dt);/*degree program passes in, prints degree program*/
	void printInvalidEmails();/*a valid email should include an at sign ('@') and period('.') and should not include a space(' ')*/
	void printAverageDays();/*prints average days used for each class*/
	void removeStudentByID(string studentID);/*find student and remove*/
	~roster();/*destructor*/
};
