#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string.h>
#include<vector>
#include "User.h"

using namespace std;
class Student : public User {
private:
	string firstName;
	string lastName;
	string major;
	int TotalHours;
	double GPA;
	//string ID;
	//string password;
	//string Notes;
	vector<string> notes;
public:
	Student(string a, string p, string b, string c, int d, double e, string f, vector <string> g) :User(f, p) {
		firstName = a;
		//password = p;
		lastName = b;
		major = c;
		TotalHours = d;
		GPA = e;
		//ID = f;
		//Notes = g;
		notes = g;
	};
	string GetID();
	string GetPassword();
	string GetFirstName();
	string GetLastName();
	string GetMajor();
	string GetTotalHours();
	string GetGPA();
	vector<string> GetNotes();
	void menu();
	void view();
	void update();
	void Change(string f);
	void Change(double g);
	void changeTotalHours(int k);
	void SetNote(string Note);
};
#endif
