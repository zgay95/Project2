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
	/* Creates advisor instances, 
	*  loads data passed into 
	*  private fields to use in other functions
	*/
	Advisor::Advisor(string ID, string pw, string fname, string lname, string room, string phone, vector<Student> ad) {
		this->ID = ID;
		this->password = pw;
		this->fName = fname;
		this->lName = lname;
		this->room = room;
		this->phone_num = phone;
		this->advisees = ad;
	}
	string Advisor::GetID() {
		return this->ID;
	}
	string Advisor::GetPassword() {
		return this->password;
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
		if (temp!= "")
		{
			temp.pop_back();
		}
		return temp;
	}
	/*
	 *  Search for student in advisee list, if foudn return true.
	 *	This function is called from teh student menu to display advisor details
	*/
	bool Advisor::SearchStudent(string StudentID) {

		for (size_t i = 0; i < advisees.size(); i++)
		{
			if ((StudentID).compare(advisees[i].GetID())==0)
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
	 *  Displays detail list of students in given vector.
	 *  Should be called by main.cpp to view all advisees
	 *  and search() to only show search results
	 */
	void Advisor::printAdviseeList() {

		//code will go here
	}

	/*
	 *  Prompts and conducts search.
	 *  Should use printAdviseeList() to show results
	 */
	void Advisor::search() {

		//code will go here
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
		getline(cin,StudentID);

		for (size_t i = 0; i < advisees.size(); i++)
		{
			if ( (advisees[i].GetID()).compare(StudentID)==0 )
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
			if ((advisees[i].GetID()).compare(StudentID)==0)
			{
				//Below code gets the current date on the system
				time_t now = time(0);
				tm *ltm = localtime(&now);
				int Year = (1970 + ltm->tm_year);
				int Month =(1 + ltm->tm_mon);
				int Day= (ltm->tm_mday);
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
	void Advisor::addAdvisee() {
	string id;
	char c;
	int i = 0;
	while (i == 0) {
		cout << "Plase enter student ID: ";
		cin >> id;
		try {
			for (Student a : /*Check if the student exists*/) {
				if (id.compare(a.GetID()) == 0) {
					i = 1;
					if (/*The student already have an advisor*/)
					{
						i = 2;
					}
					else {
						cout << "Add " << a.GetID << " " << a.GetFirstName << " " << a.GetLastName << "(y/n) ?";
						cin >> c;
						if (c == 'y' || c == 'Y')
							advisees.push_back(a);
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
	int i = 0,k=0;
	string id;
	char c;
	while (i == 0) {
		cout << "Plase enter student ID: ";
		cin >> id;
		try {
			for (Student a:advisees) {
				if (id.compare(a.GetID) == 0) {
					cout << "Remove " << a.GetID << " " << a.GetFirstName << " " << a.GetLastName << "(y/n) ? ";
					cin >> c;
					i = 1;
					if (c == 'y' || c == 'Y') {
						advisees.erase(advisees.begin() + k);
						cout << "Removed " << a.GetID << " " << a.GetFirstName << " " << a.GetLastName << endl;
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
	void Advisor::moveAdvisees() {

		//code will go here
	}

	/*
	 *  Search student by ID that is not on Advisee list.
	 *  Should only display name, ID and Advisor
	 *  Do not use printAdviseeList()
	 */
	void Advisor::searchNonAdvisee(vector<Student> allStudents) {

		//code will go here
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
				if (major.compare(this->advisees[i].GetMajor())==0)
				{
					totalGPA += stod(advisees[i].GetGPA());
					count++;
				}
			}
			AveGPA = (totalGPA/count);

			if (count != 0)
			{
				cout << "Total count of Advisees with " << major << " : " << count << endl;
				cout << "Average GPA: " << AveGPA;
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
