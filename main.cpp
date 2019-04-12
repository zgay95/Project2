/*Porject 2 - Application for Students and advisors to manage their data*/
#include <iostream>
#include <string>
#include <algorithm>
#include "FileIO.h"
#include "Student.h"
#include "Advisor.cpp"


using namespace std;
											// Below is how the data is organized in the related file.
#define StudentData  "StudentData.txt"		// StudentID, Password, FirstName, LastName, Major, GPA, HoursEarned
#define StudentNotes "StudentNotesData.txt" // StudentID, Notes
#define AdvisorData  "AdvisorData.txt"		// AdvisorID, Password, FirstName, LastName, Phone#, Room#
#define AdviseeData  "AdviseeData.txt"		// AdvisorID, StudentID, StudentID, StudentID, ..., ..., ...

int main() {
	//vector <User> Users;
	vector <Student> Students;
	vector <Advisor> Advisors;

	/*Create FileIO objects*/
	FileIO stData(StudentData);
	FileIO stNotes(StudentNotes);
	FileIO adData(AdvisorData);
	FileIO adST(AdviseeData);
	/*Read Data from Files before program starts*/
	stData.readFile();
	vector <string> StudData = stData.returnData();
	stNotes.readFile();
	vector <string> StudNotes = stNotes.returnData();
	adData.readFile();
	vector <string> visorData = adData.returnData();
	adST.readFile();
	vector <string> visorAdvisee = adST.returnData();
	/*Create User/Student objects*/
	for (size_t i = 0; i < StudData.size(); i++)
	{	//Asiign values from vector to student object
		string ID = StudData[i];			i++;
		string password = StudData[i];		i++;
		string fName = StudData[i];			i++;
		string lName = StudData[i];			i++;
		string major = StudData[i];			i++;
		double GPA = stod(StudData[i]);		i++;
		int TotalHours = stoi(StudData[i]);	
		string Notes = "";
		//search if student has notes
		for (size_t i = 0; i < StudNotes.size(); i++)
		{
			if (StudNotes[i] == ID)
			{
				Notes = StudNotes[i+1];
				break;
			}
		}
		Student Student(fName,lName, major, TotalHours, GPA, ID, Notes);
	//	User User(ID, password);
		Students.push_back(Student);
	//	Users.push_back(User);
	}
	/*Create User/Advisor objects*/
	for (size_t i = 0; i < visorData.size(); i++)
	{	//Asiign values from vector to advisor object
		string ID = visorData[i];			i++;
		string password = visorData[i];		i++;
		string fName = visorData[i];		i++;
		string lName = visorData[i];		i++;
		string phone_num = visorData[i];	i++;
		string room = visorData[i];	
		vector<Student> advisees;
		//This pushback is critical to avoid out of bounds in below loops
		visorAdvisee.push_back("end");
		//search advisees from student vector
		for (size_t i = 0; i < visorAdvisee.size(); i++)
		{
			if (visorAdvisee[i] == ID)
			{
				string nextdata = visorAdvisee[++i];

				while ((nextdata[0] == 'S') && (nextdata[1] == 'T'))
				{
					auto it = find_if(Students.begin(), Students.end(), [&nextdata](Student& obj) {return obj.GetID() == nextdata; });
					auto index = distance(Students.begin(), it);
					advisees.push_back(Students[index]);
					nextdata = visorAdvisee[++i];
				}

			}
		}
		Advisor Advisor(ID,fName,lName,room,phone_num, advisees);
		//	User User(ID, password);
		Advisors.push_back(Advisor);
		//	Users.push_back(User);
	}


	/*Ask for user id and password here*/

	return 0;
}
