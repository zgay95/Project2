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
#include "User.h"

using namespace std;

class Advisor : public User {
private:
	string ID;
	string password;
	string fName;
	string lName;
	string room;
	string phone_num;
	vector<Student> advisees;
public:
	Advisor(string ID, string pw, string fname, string lname, string room, string phone, vector<Student> ad):User(ID,pw){};
	string GetID();
	string GetPassword();
	string GetFirstName();
	string GetLastName();
	string GetRoom();
	string GetPhoneNum();
	string GetAdvisees();
	bool SearchStudent(string StudentID);
	void printMenu();
	void printAdviseeList(vector<Student> students);
	void printAdviseeList();
    	bool static sortByID(Student left, Student right);
    	bool static sortByMajor(Student left, Student right);
    	bool static sortByHours(Student left, Student right);
	void search();
	void printNotesMenu();
	void showNotes();
	void addNote();
	void addAdvisee();
	void removeAdvisee();
	void moveAdvisees();
	void searchNonAdvisee(vector<Student> allStudents);
	void printAdvisorList(vector<Advisor> allAdvisors);
	void showMajorDetails();
};
#endif /* Advisor_h */
