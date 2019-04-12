//
//  Advisor.hpp
//  
//
//  Created by Jose Monge on 3/29/19.
//
#ifndef Advisor_hpp
#define Advisor_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Advisor : public User {
private:
	string ID;
	string fName;
	string lName;
	string room;
	string phone_num;
	vector<Student> advisees;
public:
	Advisor(string ID, string fname, string lname, string room, string phone, vector<Student> ad);
	void printMenu();
	void handleMenuSelection(int selection);
	void printAdviseeList();
	void search();
	void printNotesMenu();
	void showNotes();
	void addNote();
	void addAdvisee();
	void removeAdvisee();
	void moveAdvisees();
	void searchNonAdvisee(vector<Student> allStudents);
	void printAdvisorList();
	void showMajorDetails();
};
#endif /* Advisor_h */
