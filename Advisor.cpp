//
//  Advisor.cpp
//  
//
//  Created by Jose Monge on 3/29/19.
//

#include "Advisor.hpp"

class Advisor {

private:
	string ID;
	string fName;
	string lName;
	string room;
	string phone_num;
	vector<Student> advisees;


public:
	/* Creates advisor instances, 
	*  loads data passed into 
	*  private fields to use in other functions
	*/
	Advisor(string ID, string fname, string lname, string room, string phone, vector<Student> ad) {
		this->ID = ID;
		this->fName = fname;
		this->lName = lname;
		this->room = room;
		this->phone_num = phone;
		this->advisees = ad;
	}
	/*
	 *  Displays the advisor menu.
	 *  Does not handle input
	 */
	static void printMenu() {

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
	static void printAdviseeList() {

		//code will go here
	}

	/*
	 *  Prompts and conducts search.
	 *  Should use printAdviseeList() to show results
	 */
	void search() {

		//code will go here
	}

	/*
	 *  Handles input
	 */
	void printNotesMenu() {

		cout << "========== Notes ==========\n\n";
		cout << " [1] View Notes\n";
		cout << " [2] New Note\n";
		cout << " [0] Back/n/n";
		cout << "===========================/n/n";

		int selection;
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

	void showNotes() {

		//code will go here
	}

	void addNote() {

		//code will go here
	}

	/*
	 *  Prompt for student ID.
	 *  Search for student and handle adding them
	 */
	void addAdvisee() {

		//code will go here
	}

	/*
	 *  Prompt for student ID.
	 *  Search and handle removing them
	 *  Don't actually delete student's data jus remove them from
	 *  advisee list
	 */
	void removeAdvisee() {

		//code wil go here
	}

	/*
	 * Moves students specified by major
	 */
	void moveAdvisees() {

		//code will go here
	}

	/*
	 *  Search student by ID that is not on Advisee list.
	 *  Should only display name, ID and Advisor
	 *  Do not use printAdviseeList()
	 */
	void searchNonAdvisee(vector<Student> allStudents) {

		//code will go here
	}

	/*
	 *  Prints detailed list of all advisors
	 */
	static void printAdvisorList() {

		//code will go here
	}

	/*
	 *  Prompts for major.
	 *  Displays count and average GPA
	 */
	void showMajorDetails() {

		//code will go here
	}
};
