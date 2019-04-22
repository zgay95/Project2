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
		vector <string> Notes ;
		//search if student has notes
		for (size_t i = 0; i < StudNotes.size(); i++)
		{
			if ((StudNotes[i]).compare(ID) == 0)
			{
				string allnotes;
				while ( i+1 < StudNotes.size())
				{
					if (StudNotes[i + 1][0] != 'S' &&
						StudNotes[i + 1][17] == ID[0] &&
						StudNotes[i + 1][18] == ID[1] && 
						StudNotes[i + 1][19] == ID[2] && 
						StudNotes[i + 1][20] == ID[3])
					{
						allnotes += StudNotes[i + 1] + "\n";
					}
					i++;
				}
				Notes.push_back(allnotes);
				break;
			}
		}
		Student Student(fName, password, lName, major, TotalHours, GPA, ID, Notes);
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
			if ((visorAdvisee[g]).compare(ID) == 0)
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

		Advisor Advisor(ID, password, fName, lName, room, phone_num, advisees);
		Advisors.push_back(Advisor);
	}

	bool ProgramExit = false;

	//Main loop 
	while (ProgramExit == false)
	{
		int LoggedIn = 0;
		int selection = 0;
		unsigned int index = 0;

		/*Login loop*/
		while (LoggedIn == 0)
		{	//display top level menu
			cout << "========== Menu ==========\n\n";
			cout << " [1] Advisor Login\n";
			cout << " [2] Student Login\n";
			cout << " [0] Quit\n\n";
			cout << "==========================\n\n";

			bool selectionIsValid;
			//Loop until user enters a valid selction
			do {
				cout << "Enter selection: ";
				cin >> selection;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (selection >= 0 && selection <= 2) {
					selectionIsValid = true;
				}
				else {
					selectionIsValid = false;
					cout << "Invalid entry! Try again...\n";
				}
			} while (!selectionIsValid);

			string userID, password;
			bool userFound = false;

			switch (selection) {
			case 1:
				while (!userFound) {
					cout << "\nUser ID: ";
					getline(cin, userID);

					for (index = 0; index < Advisors.size(); index++) {

						if ((Advisors[index].GetID()).compare(userID) == 0) {
							break;
						}
					}

					if (index < Advisors.size()) {
						userFound = true;
					}
					else {
						cout << "User not found, please try again...\n";
					}
				}

				cout << "Password: ";
				getline(cin, password);

				if ((Advisors[index].GetPassword()).compare(password) != 0)
				{
					cout << "Incorrect password, please try again...\n\n";
				}
				else
				{
					cout << "Login Successful.\n\n";
					LoggedIn = 1;
				}

				break;
			case 2:
				while (!userFound) {
					userFound = false;
					cout << "\nUser ID: ";
					getline(cin, userID);

					for (index = 0; index < Students.size(); index++) {

						if ((Students[index].GetID()).compare(userID) == 0) {
							break;
						}
					}

					if (index < Students.size()) {
						userFound = true;
					}
					else {
						cout << "User not found, please try again...\n";
					}
				}

				cout << "Password: ";
				getline(cin, password);

				if ((Students[index].GetPassword()).compare(password) != 0)
				{
					cout << "Incorrect password, please try again...\n\n";
				}
				else
				{
					cout << "Login Successful.\n";
					LoggedIn = 1;
				}

				break;
			case 0:
				LoggedIn = 2;
				break;
			default:
				cout << "Error: Input invalid\n";
			}
		}
		/*the actual program */

		int AdvisormenuSelection = 0;
		int StudentmenuSelection = 0;
		int ExitFlag = 0;

		while (ExitFlag == 0) {

			if (selection == 1) {
				Advisors[index].printMenu();
				cout << "Enter selection: ";
				cin >> AdvisormenuSelection;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (AdvisormenuSelection) {
				case 1:
					Advisors[index].printAdviseeList();
					break;
				case 2:
					Advisors[index].search();
					break;
				case 3:
					Advisors[index].printNotesMenu(&Students);
					break;
				case 4:
					Advisors[index].addAdvisee(Advisors, Students);
					break;
				case 5:
					Advisors[index].removeAdvisee();
					break;
				case 6:
					Advisors[index].moveAdvisees(&Advisors, &Students);
					break;
				case 7:
					Advisors[index].searchNonAdvisee(Students, Advisors);
					break;
				case 8:
					Advisors[index].printAdvisorList(Advisors);
					break;
				case 9:
					Advisors[index].showMajorDetails();
					break;
				case 0:
					ExitFlag = 1;
					break;
				default:
					cout << "Error: Input invalid\n";
				}
			}
			else if (selection == 2) {
				Students[index].menu();
				cout << "Enter selection: ";
				cin >> StudentmenuSelection;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (StudentmenuSelection) {
				case 0: //View advisor data
					for (Advisor ad : Advisors)
					{
						for (Student st : ad.GetallAdvisees()) {
							if (((st.GetID()).compare(Students[index].GetID())) == 0)
							{
								cout << "Advisor Infomation: " << endl;
								cout << "ID: " << ad.GetID() << endl;
								cout << "Name: " << ad.GetFirstName() << " " << ad.GetLastName() << endl;
								cout << "Room#: " << ad.GetRoom() << endl;
								cout << "Phone#: " << ad.GetPhoneNum() << endl;
							}
						}
					}
					break;
				case 1: Students[index].view();
					break;
				case 2: Students[index].update();
					break;
				case 3:
					ExitFlag = 1;
					break;
				default: cout << "Invalid option" << endl;
				}
			}
			else
			{
				ExitFlag = 1;
				ProgramExit = true;
				cout << "\nProgram Exiting...\n\n";
			}
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

		vector <string> Notes = Students[i].GetNotes();

		for (size_t i = 0; i < Notes.size(); i++)
		{
			CD += Notes[i];
			CD += "\n";
		}

		if (Notes.size() != 0)
		{
			writeStudNotes.push_back(CD);
		}

		writeStudData.push_back(AB);
	}

	vector <string> writevisorData;
	vector <string> writevisorAdvisee;

	for (size_t i = 0; i < Advisors.size(); i++)
	{	//Asiign values from object into vector
		string AB, CD = "";

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
