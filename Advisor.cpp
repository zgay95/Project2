//
//  Advisor.cpp
//  
//
//  Created by Jose Monge on 3/29/19.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
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

		cout << "========== Notes ==========\n\n";
		cout << " [1] View Notes\n";
		cout << " [2] New Note\n";
		cout << " [0] Back/n/n";
		cout << "===========================/n/n";

		int selection = 0;
		//I plan to make a method somewhere (maybe in User) that can
		//get user input and validate based on a given range
		//selection = getMenuInput(0, 2);

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
			"Error: input invalid\n";
		}
	}

	void Advisor::showNotes() {

		//code will go here
	}

	void Advisor::addNote() {

		//code will go here
	}

	/*
	 *  Prompt for student ID.
	 *  Search for student and handle adding them
	 */
	void Advisor::addAdvisee() {

		//code will go here
	}

	/*
	 *  Prompt for student ID.
	 *  Search and handle removing them
	 *  Don't actually delete student's data jus remove them from
	 *  advisee list
	 */
	void Advisor::removeAdvisee() {

		//code wil go here
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
			printElement(allAdvisors[i].GetFirstName, nameWidth);
			printElement(allAdvisors[i].GetLastName, nameWidth);
			printElement(allAdvisors[i].GetRoom, numWidth);
			printElement(allAdvisors[i].GetPhoneNum, numWidth);
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
				if (major == this->advisees[i].GetMajor())
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
