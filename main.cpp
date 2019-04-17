/*Porject 2 - Application for Students and advisors to manage their data*/
#include <iostream>
#include <string>
#include <algorithm>
#include "FileIO.h"
#include "Student.h"
#include "Advisor.h"

using namespace std;
											// Below is how the data is organized in the related file.
#define StudentData  "StudentData.txt"		// StudentID, Password, FirstName, LastName, Major, GPA, HoursEarned
#define StudentNotes "StudentNotesData.txt" // StudentID, Notes
#define AdvisorData  "AdvisorData.txt"		// AdvisorID, Password, FirstName, LastName, Phone#, Room#
#define AdviseeData  "AdviseeData.txt"		// AdvisorID, StudentID, StudentID, StudentID, ..., ..., ...

/*
*  Displays the top level menu
*/
void printLoginMenu() {

	cout << "========== Menu ==========\n\n";
	cout << " [1] Advisor Login\n";
	cout << " [2] Student Login\n";
	cout << " [0] Quit\n\n";
	cout << "==========================\n\n";
}

/*
* Returns index of user
*/
int login(vector<User>* users) {

	string userID, password;
	bool userFound;
	int index;

	do {
		userFound = false;
		cout << "\nUser ID: ";
		cin >> userID;

		for (index = 0; index < users.size(); index++) {

			if (userID.compare((*users)[index].GetID() == 0) {
				break;
			}
		}

		if (index < users.size()) {
			userFound = true;
		}
		else {
			cout << "User not found, please try again...\n";
		}
	} while (!userFound);

	cout << "Password: ";
	cin >> password;

	while (password.compare((*users)[index].getPassword() != 0) {
		cout << "Incorrect password, please try again...\n\n";
	}
	return index;
}

/*
* Input validation for numbered menu options
* returns int in range 0 to upperLimit (inclusive)
*/
int getIntSelection(int upperLimit) {

	int selection;
	bool selectionIsValid;

	do {
		cout << "Enter selection: ";
		cin >> selection;
		if (selection < 0 || selection > upperLimit) {
			selectionIsValid = false;
			cout << "Invalid entry! Try again...\n";
		}
		else {
			selectionIsValid = true;
		}
	} while (!selectionIsValid);

	return selection;
}



int main() {
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
	visorData[0] = "AD00";
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
		Student Student(fName,password,lName, major, TotalHours, GPA, ID, Notes);
		Students.push_back(Student);
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

		//search advisees from student vector
		for (size_t g = 0; g < visorAdvisee.size(); g++)
		{
			if (visorAdvisee[g] == ID)
			{
				while (ID[0] == 'A')
				{	
					if (g >= (visorAdvisee.size() - 1))
					{
						break;
					}

					string nextdata = visorAdvisee[++g];

					if (nextdata[0] == 'A')
					{
						break;
					}
					auto it = find_if(Students.begin(), Students.end(), [&nextdata](Student& obj) {return obj.GetID() == nextdata; });
					auto index = distance(Students.begin(), it);
					advisees.push_back(Students[index]);
				}
			}
		}

		Advisor Advisor(ID,password,fName,lName,room,phone_num, advisees);
		Advisors.push_back(Advisor);
	}


	/*Ask for user id and password here*/


	/*log in*/

	printLoginMenu();
	int userSelection = getIntSelection(2);

	int userIndex;

	switch (userSelection) {
	case 1:
		userIndex = login(Advisors);
		break;
	case 2:
		userIndex = login(Students);
		break;
	case 0:
		return 0;
	default:
		return 1;
	}

	/*the actual program */

	int menuSelection = 1;

	while (menuSelection != 0) {

		if (userSelection == 1) {
			Advisor.printMenu();
			menuSelection = getIntSelection(9);
			switch (menuSelection) {
			case 1:
				Advisors[userIndex].printAdviseeList();
				break;
			case 2:
				Advisors[userIndex].search();
				break;
			case 3:
				Advisors[userIndex].printNotesMenu();
				break;
			case 4:
				Advisors[userIndex].addAdvisee();
				break;
			case 5:
				Advisors[userIndex].removeAdvisee();
				break;
			case 6:
				Advisors[userIndex].moveAdvisees();
				break;
			case 7:
				Advisors[userIndex].searchNonAdvisee(Students);
				break;
			case 8:
				Advisors[userIndex].printAdviseeList();
				break;
			case 9:
				Advisors[userIndex].showMajorDetails();
				break;
			case 0:
				return;
				break;
			default:
				cout << "Error: Input invalid\n";
			}
		}
		else {
			Student.printMenu();
			menuSelection = getIntSelection(2);
			Students[userIndex].menu();
		}
	}


	/* Format data into vetors to write back to files*/

	vector <string> writeStudData;
	vector <string> writeStudNotes;

	for (size_t i = 0; i < Students.size(); i++)
	{	//Asiign values from object into vector
		string AB, CD = "";

		string ID = Students[i].GetID();		
		AB += ID;
		CD += ID;
		AB += ",";
		CD += ",";

		string password = Students[i].GetPassword();
		AB += password;
		AB += ",";

		string fName = Students[i].GetFirstName();
		AB += fName;
		AB += ",";

		string lName = Students[i].GetLastName();
		AB += lName;
		AB += ",";

		string major = Students[i].GetMajor();
		AB += major;
		AB += ",";

		string GPA = Students[i].GetGPA();
		AB += GPA;
		AB += ",";

		string TotalHours = Students[i].GetTotalHours();
		AB += TotalHours;

		string Notes = Students[i].GetNotes();
		CD += Notes;

		if (Notes != "")
		{
			writeStudNotes.push_back(CD);
		}

		writeStudData.push_back(AB);
	}

	vector <string> writevisorData;
	vector <string> writevisorAdvisee;

	for (size_t i = 0; i < Advisors.size(); i++)
	{	//Asiign values from object into vector
		string AB, CD ="";

		string ID = Advisors[i].GetID();
		AB += ID;
		CD += ID;
		AB += ",";
		CD += ",";

		string password = Advisors[i].GetPassword();
		AB += password;
		AB += ",";

		string fName = Advisors[i].GetFirstName();
		AB += fName;
		AB += ",";

		string lName = Advisors[i].GetLastName();
		AB += lName;
		AB += ",";

		string phone = Advisors[i].GetPhoneNum();
		AB += phone;
		AB += ",";

		string room = Advisors[i].GetRoom();
		AB += room;

		string advisees = Advisors[i].GetAdvisees();
		//advisees.pop_back();
		CD += advisees;

		writevisorData.push_back(AB);
		writevisorAdvisee.push_back(CD);

	}


	/* Write data abck to files formatted correctly */
	stData.writeFile(writeStudData);
	stNotes.writeFile(writeStudNotes);
	adData.writeFile(writevisorData);
	adST.writeFile(writevisorAdvisee);

	return 0;
}
