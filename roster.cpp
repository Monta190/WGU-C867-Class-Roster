//roster.h
// c867-student-roster
//Created by Amber Ruiz

#include "roster.h"


void roster::parse(string studentdata)/*parse each row*/
{
	int rhs = studentdata.find(",");
	string sID = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string sfirstName = studentdata.substr(lhs, rhs - lhs);/*firstName*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string slastName = studentdata.substr(lhs, rhs - lhs);/*lastName*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string semailAddress = studentdata.substr(lhs, rhs - lhs);/*emailAddress*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int sAge = stod(studentdata.substr(lhs, rhs - lhs));/*Age*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d0 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d1 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d2 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);

	DegreeType dt = SOFTWARE;/*default value*/

	if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dt = SECURITY;
	else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == '0') dt = SOFTWARE;
	else if (studentdata.at(lhs) == 'N') dt = NETWORK;

	add(sID, sfirstName, slastName, semailAddress, sAge, d0, d1, d2, dt);

}
/*add method combines strings and creates objects in roster*/
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int d0, int d1, int d2, DegreeType dt)
{
	int darr[3] = { d0,d1,d2 };/*days back into an array for constructor*/

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, dt);

}
/*displays all student using tab delimited output*/
void roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getstudentID(); cout << '\t';
		cout << classRosterArray[i]->getfirstName(); cout << '\t';
		cout << classRosterArray[i]->getlastName(); cout << '\t';
		cout << classRosterArray[i]->getemailAddress(); cout << '\t';
		cout << classRosterArray[i]->getage(); cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[2]; cout << '\t';
		cout << degreeTypeStrings[classRosterArray[i]->getDegreeType()] << std::endl;
	}
}
/*displays only students that match the degree type*/
void roster::printByDegreeType(DegreeType dt)
{
	Student::printHeader();
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		if (roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
	}
	cout << std::endl;
}
/*each email must contain an '@' and '.' and no spaces*/
void roster::printInvalidEmails()
{
	bool any = false;
	/*assuming no invalid emails*/
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getemailAddress());
		/*create variable to shorten statement below*/
		if ((emailAddress.find('@') == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos))
		{
			any = true;
			/*any reassigned true if statment met*/
			cout << emailAddress << ":" << classRosterArray[i]->getfirstName() << std::endl;
		}
		if (!any) cout << "NONE" << std::endl;
	}

}

void roster::printAverageDays()
{
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getstudentID() << ": ";
		cout << (classRosterArray[i]->getdaysInCourse()[0]
			+ classRosterArray[i]->getdaysInCourse()[1]
			+ classRosterArray[i]->getdaysInCourse()[2]) / 3 << std::endl;
		/*divide by number of course day counts*/
	}
	cout << std::endl;
}
/*student to be removed comes in the parameter*/
void roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= roster::lastIndex; i++)
	{	
			if (classRosterArray[i]->getstudentID() == studentID)
			{
				success = true;
				if (i < studentDataTable - 1)
				{
					Student* temp = classRosterArray[i];
					classRosterArray[i] = classRosterArray[studentDataTable - 1];
					classRosterArray[studentDataTable - 1] = temp;
				}
				roster::lastIndex--;
			}
	
	}
	if (success)
	{
		cout << studentID << "removed from roster." << std::endl << std::endl;;
		this->printAll();/*displays the students -the removed one should not display*/
	}
	else cout << studentID << "not found." << std::endl << std::endl;
}

/*removes objects that are dynamically allocated; the roster creates student objects dynamically and must be used t destroy*/
roster::~roster()
{
	cout << "Destructor Called!" << std::endl << std::endl;
	for (int i = 0; i < studentDataTable; i++)
	{
		cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}
}