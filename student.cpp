//Student.cpp
// c867-student-roster
//Created by Amber Ruiz

#include "student.h"

Student::Student()/*parameters for constructor sets to default values*/
{
	this->studentID = "";/*an empty string is not null*/
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] =0;/*loops over array and sets default to 0*/
	this-> degreeType = DegreeType::SOFTWARE;/*sets default degree type to software using value created in degree.h*/
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeType degreeType)/*full construtor*/
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++)this->daysInCourse[i] = daysInCourse[i];/*loop*/
	this-> degreeType = degreeType;

}

Student::~Student() {}/*destuctor */

	/*getters */
	string Student::getstudentID() { return this->studentID; }
	string Student::getfirstName() { return this->firstName; }
	string Student::getlastName() { return this->lastName; }
	string Student::getemailAddress() { return this->emailAddress; }
	int Student::getage() { return this->age; }
	int* Student::getdaysInCourse() { return this->daysInCourse; }/*array name is a pointer*/
	DegreeType Student::getDegreeType() { return this->degreeType; }

	/*setters*/
	void Student::setstudentID(string studentID) { this->studentID = studentID; }
	void Student::setfirstName(string firstName) { this->firstName = firstName; }
	void Student::setlastName(string lastName) {this->lastName = lastName;}
	void Student::setemailAddress(string emailAddress) {this->emailAddress = emailAddress;}
	void Student::setage(int age) {this->age = age;}
	void Student::setdaysInCourse(int days[])/*sets each number of days*/
	{
		for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = days[i];
	}
	void Student::setDegreeType(DegreeType dt) {this->degreeType = dt;}

	void Student::printHeader()

	{
		cout << "Output format: ID| First| Last| Email Address| Age|Days to Complete| Degree Program \n";
	}

	void Student::print()
	{
		cout << this->getstudentID() << '\t';
		cout << this->getfirstName() << '\t';
		cout << this->getlastName() << '\t';
		cout << this->getemailAddress() << '\t';
		cout << this->getdaysInCourse()[0] << ',';
		cout << this->getdaysInCourse()[1] << ',';
		cout << this->getdaysInCourse()[2] << '\t';
		cout << degreeTypeStrings[this->getDegreeType()] << '\n';/*degreeType to string, is an int but uses Degree.h for string*/

	}