#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string.h>
#include "User.h"

using namespace std;
class Student : public User {
private:
	string firstName;
	string lastName;
	string major;
	int TotalHours;
	double GPA;
	string ID;
	string password;
	string Notes;
public:
	Student(string a, string p, string b, string c, int d, double e, string f, string g) :User(a, b) {};
	string GetID();
	string GetPassword();
	string GetFirstName();
	string GetLastName();
	string GetMajor();
	string GetTotalHours();
	string GetGPA();
	string GetNotes();
	void menu();
	void view();
	void update();
	void ChangeMajor(string f);
	void ChangeGPA(double g);
	void changeTotalHours(int k);
	void SetNote(string Note);
};
#endif 
