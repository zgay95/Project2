#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string.h>

using namespace std;
class Student: public User {
private:
	string name;
	string major;
	int TotalHours;
	double GPA;
	string ID;
public:
	Student(string a, string b, int c, double d, string e);
	void menu();
	void view();
	void update();
	void ChangeMajor(string f);
	void ChangeGPA(double g);
	void changeTotalHours(int k);
};
#endif 
