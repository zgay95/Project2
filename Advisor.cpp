//
//  Advisor.cpp
//  
//
//  Created by Jose Monge on 3/29/19.
//
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Advisor.h"
#include "Student.h"

using namespace std;
const char separator = ' ';
const int nameWidth = 16;
const int numWidth = 10;

template<typename T>
void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(separator) << t;
}
string Advisor::GetID() {
	return User::GetuserID();
}
string Advisor::GetPassword() {
	return User::Getpassword();
}
string Advisor::GetFirstName() {
	return this->fName;
}
string Advisor::GetLastName() {
	return this->lName;
}
string Advisor::GetRoom() {
	return this->room;
}
string Advisor::GetPhoneNum() {
	return this->phone_num;
}
string Advisor::GetAdvisees() {
	string temp;

	for (size_t i = 0; i < this->advisees.size(); i++)
	{
		temp += this->advisees[i].GetID();
		temp += ",";
	}
	if (temp != "")
	{
		temp.pop_back();
	}
	return temp;
}
vector<Student> Advisor::GetallAdvisees() {
	return advisees;
}
/*
 *  Search for student in advisee list, if foudn return true.
 *	This function is called from teh student menu to display advisor details
*/
bool Advisor::SearchStudent(string StudentID) {

	for (size_t i = 0; i < advisees.size(); i++)
	{
		if ((StudentID).compare(advisees[i].GetID()) == 0)
		{
			return true;
		}
	}
	return false;
}
/*
 *  Displays the advisor menu.
 *  Does not handle input
 */
void Advisor::printMenu() {

	cout << "========== Menu ==========\n\n";
	cout << " [1] Show all Advisees\n";
	cout << " [2] Search\n";
	cout << " [3] Notes\n";
	cout << " [4] Add Advisee\n";
	cout << " [5] Remove Advisee\n";
	cout << " [6] Move Advisees\n";
	cout << " [7] Search Non-Advisees\n";
	cout << " [8] Show all Advisors\n";
	cout << " [9] Show by Major\n";
	cout << " [0] Quit\n\n";
	cout << "==========================\n\n";
}
/*
 *  Displays detail list of students in given vector
 */
void Advisor::printAdviseeList(vector<Student> students) {

	if (students.size() == 0) {

		cout << "\nNo Advisees to show.\n";
		return;
	}

	cout << left << setw(8) << "ID";
	cout << left << setw(nameWidth + 4) << "Name";
	cout << left << setw(6) << "Major";
	cout << left << setw(11) << "Total Hours\n";

	for (Student a : students) {
		string fullname = a.GetFirstName() + " " + a.GetLastName();
		cout << left << setw(8) << a.GetID();
		cout << left << setw(nameWidth + 4) << fullname;
		cout << left << setw(6) << a.GetMajor();
		cout << right << setw(7) << a.GetTotalHours() << "\n";
	}

	cout << "\n";
}
/*Displays destail list of all students*/
void Advisor::printAdviseeList() {

	cout << "\n========== Advisees ==========\n\n";
	cout << " [1] Sort by ID\n";
	cout << " [2] Sort by Major\n";
	cout << " [3] Sort by Number of Hours\n";
	cout << " [0] Back\n\n";
	cout << "================================\n\n";

	bool selectionIsValid;
	int selection;
	//Loop until user enters a valid selction
	do {
		cout << "Enter selection: ";
		cin >> selection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (selection >= 0 && selection <= 3) {
			selectionIsValid = true;
		}
		else {
			selectionIsValid = false;
			cout << "Invalid entry! Try again...\n";
		}
	} while (!selectionIsValid);

	if ((GetallAdvisees()).size() == 0) {
		cout << "There is no advisees! " << endl;
		return;
	}

	switch (selection) {

	case 1:
		sort(advisees.begin(), advisees.begin() + advisees.size(), sortByID);
		break;
	case 2:
		sort(advisees.begin(), advisees.begin() + advisees.size(), sortByMajor);
		break;
	case 3:
		sort(advisees.begin(), advisees.begin() + advisees.size(), sortByHours);
		break;
	case 0:
		return;
	default:
		return;
	}

	printAdviseeList(advisees);
}

/* Functions for sorting */
bool Advisor::sortByID(Student left, Student right) {

	return (left.GetID().compare(right.GetID()) < 0);
}
bool Advisor::sortByMajor(Student left, Student right) {

	return (left.GetMajor().compare(right.GetMajor()) < 0);
}
bool Advisor::sortByHours(Student left, Student right) {

	return (left.GetTotalHours().compare(right.GetTotalHours()) < 0);
}


/*
 *  Prompts and conducts search.
 *  Should use printAdviseeList() to show results
 */
void Advisor::search() {

	vector<Student> searchResults;
	string queue;
	int min, max, totalHours;
	int selection;

	cout << "\n========== Search ==========\n\n";
	cout << " [1] Search by ID\n";
	cout << " [2] Search by Major\n";
	cout << " [3] Search by Range of Hours\n";
	cout << " [4] Search by Major and Range of Hours\n";
	cout << " [0] Back\n\n";
	cout << "==============================\n\n";


	bool selectionIsValid;
	//Loop until user enters a valid selction
	do {
		cout << "Enter selection: ";
		cin >> selection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (selection >= 0 && selection <= 4) {
			selectionIsValid = true;
		}
		else {
			selectionIsValid = false;
			cout << "Invalid entry! Try again...\n";
		}
	} while (!selectionIsValid);
	int o = 0;
	switch (selection) {

	case 1:
		cout << "Enter ID: ";
		cin >> queue;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (size_t i = 0; i < advisees.size(); i++) {
			if (advisees[i].GetID().compare(queue) == 0) {
				searchResults.push_back(advisees[i]);
				o = 1;
			}
		}
		if (o == 0)
			cout << "No student was found!" << endl;
		break;
	case 2:
		cout << "Enter Major: ";
		cin >> queue;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (size_t i = 0; i < advisees.size(); i++) {
			if (advisees[i].GetMajor().compare(queue) == 0) {
				searchResults.push_back(advisees[i]);
				o = 1;
			}
		}
		if (o == 0)
			cout << "No student was found!" << endl;
		break;
	case 3:
		cout << "Enter min hours: ";
		cin >> min;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter max hours: ";
		cin >> max;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (size_t i = 0; i < advisees.size(); i++) {
			totalHours = stoi(advisees[i].GetTotalHours());
			if (min <= totalHours && max >= totalHours) {
				searchResults.push_back(advisees[i]);
				o = 1;
			}
		}
		if (o == 0)
			cout << "No student was found!" << endl;
		break;
	case 4:
		cout << "Enter Major: ";
		cin >> queue;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter min hours: ";
		cin >> min;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter max hours: ";
		cin >> max;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (size_t i = 0; i < advisees.size(); i++) {
			totalHours = stoi(advisees[i].GetTotalHours());
			if (min <= totalHours && max >= totalHours && advisees[i].GetMajor().compare(queue) == 0) {
				searchResults.push_back(advisees[i]);
				o = 1;
			}
		}
		if (o == 0)
			cout << "No student was found!" << endl;
		break;
	case 0:
		return;
	default:
		return;
	}

	printAdviseeList(searchResults);
}
/*
 *  Handles input
 */
void Advisor::printNotesMenu() {

	cout << "\n========== Notes ==========\n\n";
	cout << " [1] View Notes\n";
	cout << " [2] New Note\n";
	cout << " [0] Back\n\n";
	cout << "===========================\n\n";

	int selection = 0;
	while (selection < 3) {
		cout << "Enter Selection: ";
		cin >> selection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (selection) {
		case 1:
			showNotes();
			break;
		case 2:
			addNote();
			break;
		case 0:
			return;
			break;
		default:
			cout << "Error: input invalid\n";
		}
	}
}

void Advisor::showNotes() {
	string StudentID;
	int flag = 0;
	cout << "\nEnter a Student ID: ";
	getline(cin, StudentID);

	for (size_t i = 0; i < advisees.size(); i++)
	{
		if ((advisees[i].GetID()).compare(StudentID) == 0)
		{
			cout << advisees[i].GetNotes() << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo student found under your advisees.\n";
	}
}

void Advisor::addNote() {
	string StudentID;
	int flag = 0;
	cout << "\nEnter a Student ID: ";
	getline(cin, StudentID);

	for (size_t i = 0; i < advisees.size(); i++)
	{
		if ((advisees[i].GetID()).compare(StudentID) == 0)
		{
			//Below code gets the current date on the system
			time_t now = time(0);
			tm *ltm = localtime(&now);
			int Year = (1970 + ltm->tm_year);
			int Month = (1 + ltm->tm_mon);
			int Day = (ltm->tm_mday);
			//create header for note
			string date = to_string(Month) + "/" + to_string(Day) + "/" + to_string(Year);
			string header = "(" + this->GetID() + " " + date + ") " + advisees[i].GetID() + " ";
			string InputNote = "";
			cout << "\nEnter Note for Student: ";
			getline(cin, InputNote);

			if (InputNote == "")
			{
				cout << "\n No Note entered.\n";
			}
			else
			{
				string Note = header + InputNote;
				advisees[i].SetNote(Note);
			}
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\nNo student found under your advisees.\n";
	}
}

/*
 *  Prompt for student ID.
 *  Search for student and handle adding them
 */
void Advisor::addAdvisee(vector<Advisor> b, vector<Student> k) {
	string id;
	char c;
	int i = 0;
	while (i == 0) {
		cout << "Plase enter student ID: ";
		cin >> id;
		try {
			for (Advisor a : b) {
				for (Student d : a.GetallAdvisees()) {
					if (id.compare(d.GetID()) == 0) {
						i = 2;
					}
				}
			}
			if (i != 2) {
				for (Student j : k) {
					if ((j.GetID()).compare(id) == 0 && i != 2) {
						cout << "Add " << j.GetID() << " " << j.GetFirstName() << " " << j.GetLastName() << "(y/n) ?";
						cin >> c;
						if (c == 'y' || c == 'Y')
							advisees.push_back(j);
						i = 1;
					}

				}
			}
			if (i == 0)
				throw "<ERROR> No such student!";
			if (i == 2)
				throw "***DOUBLE ADVISING REJECTED";
		}
		catch (const char* StudentNotFound) {
			cout << StudentNotFound << endl;
		}
	}
}

/*
 *  Prompt for student ID.
 *  Search and handle removing them
 *  Don't actually delete student's data jus remove them from
 *  advisee list
 */
void Advisor::removeAdvisee() {
	int i = 0, k = 0;
	string id;
	char c;
	while (i == 0) {
		cout << "Plase enter student ID: ";
		cin >> id;
		try {
			for (Student a : advisees) {
				if (id.compare(a.GetID()) == 0) {
					cout << "Remove " << a.GetID() << " " << a.GetFirstName() << " " << a.GetLastName() << "(y/n) ? ";
					cin >> c;
					i = 1;
					if (c == 'y' || c == 'Y') {
						advisees.erase(advisees.begin() + k);
						cout << "Removed " << a.GetID() << " " << a.GetFirstName() << " " << a.GetLastName() << endl;
					}
				}
				k++;
			}
			if (i == 0)
				throw "<ERROR> No such student!";
		}
		catch (const char* InvalidID) {
			cout << InvalidID << endl;
		}
	}
}

/*
 * Moves students specified by major
 */
void Advisor::moveAdvisees(vector<Advisor>* allAdvisors) {
    
    string major, advisorID, specialCode;
    vector<Student*> studentsToMove;
    int receiverIndex;
    
    cout << "\nEnter Major (ex: EE): ";
    cin >> major;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 0; i < advisees.size(); i++) {
        
        if (advisees[i].GetMajor().compare(major) == 0) {
            studentsToMove.push_back(&(advisees[i]));
        }
    }
    
    cout << "\nEnter ID of receiving Advisor: ";
    cin >> advisorID;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (receiverIndex = 0; receiverIndex < allAdvisors->size(); receiverIndex++) {
        
        if ((*allAdvisors)[receiverIndex].GetID().compare(advisorID) == 0) {
            break;
        }
    }
    
    if (receiverIndex == allAdvisors->size()) {
        cout << "Advisor not found.\n";
        return;
    }
    
    string code;
    cout << "Enter authorization code: ";
    cin >> code;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (!(code.compare("ENB#342") == 0)) {
        cout << "Invalid code. Move canceled.\n";
        return;
    }
    
    string ID, note;
    for (int i = 0; i < studentsToMove.size(); i++) {
        
        (*allAdvisors)[receiverIndex].adviseesPushBack(studentsToMove[i]);
        
        ID = studentsToMove[i]->GetID();
        
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int Year = (1970 + ltm->tm_year);
        int Month = (1 + ltm->tm_mon);
        int Day = (ltm->tm_mday);
        //create header for note
        string date = to_string(Month) + "/" + to_string(Day) + "/" + to_string(Year);
        string header = "(" + this->GetID() + " " + date + ") " + ID + " ";
        
        note = ID + " " + header + "***ADVISOR CHANGE FROM " + this->GetID() + " TO " + (*allAdvisors)[receiverIndex].GetID() + "\n";
        
        studentsToMove[i]->SetNote(note);
        
        auto iter = find_if(advisees.begin(), advisees.end(), [ID](Student student) {
            return (student.GetID().compare(ID) == 0);
        });
        advisees.erase(iter);
    }
    
    cout << "Advisees successfully moved.\n";
}

/*
 *  Adds given student to advisees list
 */
void Advisor::adviseesPushBack(Student* student) {
    
    advisees.push_back(*student);
}

/*
 *  Search student by ID that is not on Advisee list.
 *  Should only display name, ID and Advisor
 *  Do not use printAdviseeList()
 */
void Advisor::searchNonAdvisee(vector<Student> allStudents, vector<Advisor> allAdvisors) {

	string queue;
	int studentIndex, advisorIndex;

	cout << "Enter ID of student: ";
	cin >> queue;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (studentIndex = 0; studentIndex < allStudents.size(); studentIndex++) {

		if (allStudents[studentIndex].GetID().compare(queue) == 0) {
			break;
		}
	}

	if (studentIndex == allStudents.size()) {
		cout << "No student found.\n\n";
		return;
	}

	for (advisorIndex = 0; advisorIndex < allAdvisors.size(); advisorIndex++) {

		if (allAdvisors[advisorIndex].SearchStudent(allStudents[studentIndex].GetID())) {
			break;
		}
	}


	cout << "\nResult found:\n";
	cout << allStudents[studentIndex].GetID() << " ";
	cout << allStudents[studentIndex].GetFirstName() << " " << allStudents[studentIndex].GetLastName() << "\n";
	if (advisorIndex >= allAdvisors.size()) {
		cout << "No advisor found for this student.\n";
	}
	else {
		cout << "Current advisor: " << allAdvisors[advisorIndex].GetFirstName() << " " << allAdvisors[advisorIndex].GetLastName() << "\n";
	}
}


/*
 *  Prints detailed list of all advisors
 */
void Advisor::printAdvisorList(vector<Advisor> allAdvisors) {
	cout << '\n';
	for (size_t i = 0; i < allAdvisors.size(); i++)
	{
		printElement(allAdvisors[i].GetFirstName(), nameWidth);
		printElement(allAdvisors[i].GetLastName(), nameWidth);
		printElement(allAdvisors[i].GetRoom(), numWidth);
		printElement(allAdvisors[i].GetPhoneNum(), numWidth);
		cout << endl;
	}
	cout << '\n';
}

/*
 *  Prompts for major.
 *  Displays count and average GPA
 */
void Advisor::showMajorDetails() {
	string major;
	double totalGPA = 0.0, AveGPA = 0.0;
	int count = 0;
	cout << "\n Enter major (ex: CE,CS,CH,IE,EE,ME): ";
	getline(cin, major);

	if (major.length() < 3)
	{
		for (size_t i = 0; i < this->advisees.size(); i++)
		{
			if (major.compare(this->advisees[i].GetMajor()) == 0)
			{
				totalGPA += stod(advisees[i].GetGPA());
				count++;
			}
		}
		AveGPA = (totalGPA / count);

		if (count != 0)
		{
			cout << "Total count of Advisees with " << major << " : " << count << endl;
			cout << "Average GPA: " << AveGPA << endl;
		}
		else
		{
			cout << "No Advisees with " << major << " major.\n";
		}
	}
	else
	{
		cout << "Please enter a valid major.\n";
	}
}
