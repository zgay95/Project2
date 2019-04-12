#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string.h>

using namespace std;
class Student: public User  {
private:
	string firstName;
	string lastName;
	string major;
	int TotalHours;
	double GPA;
	string ID;
	string Notes;
public:
	Student(string a, string b, string c, int d, double e, string f, string g);
	string GetID();
	void menu();
	void view();
	void update();
	void ChangeMajor(string f);
	void ChangeGPA(double g);
	void changeTotalHours(int k);
};
#endif 
