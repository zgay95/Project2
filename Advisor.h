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
	/*string ID;
	string password; We actualy dont need ID and password because it is an inheritance of User*/
	string fName;
	string lName;
	string room;
	string phone_num;
	vector<Student> advisees;
public:
	Advisor(string ID, string pw, string fname, string lname, string room, string phone, vector<Student> ad) :User(ID, pw) {
		//this->ID = ID;
		//this->password = pw;
		this->fName = fname;
		this->lName = lname;
		this->room = room;
		this->phone_num = phone;
		this->advisees = ad;
	};
	string GetID();
	string GetPassword();
	string GetFirstName();
	string GetLastName();
	string GetRoom();
	string GetPhoneNum();
	string GetAdvisees();
	vector<Student> GetallAdvisees();
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
	void addAdvisee(vector<Advisor> b, vector<Student> k);
	void removeAdvisee();
	void moveAdvisees(vector<Advisor>* allAdvisors);
    	void adviseesPushBack(Student* student);
	void searchNonAdvisee(vector<Student> allStudents, vector<Advisor> allAdvisors);
	void printAdvisorList(vector<Advisor> allAdvisors);
	void showMajorDetails();
};
#endif /* Advisor_h */
