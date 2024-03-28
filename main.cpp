//main.cpp
// c867-student-roster
//Created by Amber Ruiz

#include<iostream>
#include "roster.h"
using namespace std;

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Amber,Ruiz,ruiz.amber0307@gmail.com,30,20,35,40,SOFTWARE"
	};
	/*long string to parase*/
	
	const int studentDataTable = 5;
	roster roster;
	/* creates roster using default parameters constructor*/
	
	for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
	cout << "Displaying all students:" << std::endl;
	roster.printAll();
	cout << std::endl;
	/*displays all students*/

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree Type:" << std::endl;
		roster.printByDegreeType((DegreeType)i);
	}
	/*displays all students in the software degree program*/

	cout << "Displaying Invalid Email Address:" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;
	/*display all students with an incorrectly formatted email address*/

	cout << "Displaying average days per class:" << std::endl;
	roster.printAverageDays();
	/*displays the average number of days each student spends in 3 classes*/

	cout << "Remove Student A3." << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;
	/*remove student A3 and print all remaining students*/

	cout << "Remove Student A3." << std::endl;
	roster.removeStudentByID("A3");
	cout << std::endl;
    /*throw and error when A3 is not found*/
	
	system("pause");
	return 0;
	
}

