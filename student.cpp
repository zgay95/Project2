#include<iostream>
#include<string>
#include "Student.h"

using namespace std;

int readline(char a[], int b) {
	int ch, i = 0;

	while (isspace(ch = getchar()));
	a[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < b)
			a[i++] = ch;
	}
	a[i] = '\0';
	return i;
}

	Student::Student(string a, string b,int c, double d,string e) {
		name = a;
		major = b;
		TotalHours = c;
		GPA = d;
		ID = e;
	}
	void Student::view() {
		cout << name << "`s major: " << major << "\nTotal Hours: " << TotalHours << "\nGPA: " << GPA << endl;
	}
	void Student::ChangeMajor(string f) {
		major = f;
		cout << "Major updated successfully!!" << endl;
	}
	void Student::ChangeGPA(double g) {
		try {
			if (g<0.0 || g>4.0) {
				
				throw "GPA should be between 0.0 and 4.0";
			}
			else {
				GPA = g;
				cout << "GPA updated successfully!!" << endl;
			}
		}
		catch(const char* Invalidgpa ){
			cout << Invalidgpa << endl;
		}
	}
	void Student::menu() {
		int n=0;
		while (n!=3) {
			cout << "1-View information\n2-Update information\n3-Exit" << endl;
			cin >> n;
			switch (n) {
			case 1: Student::view();
				break;
			case 2: Student::update();
				break;
			case 3:
				break;
			default: cout << "Invalid option" << endl;
			}
		}
	}
	void Student::update() {
		int n=0,i,j,new_hours;
		double new_GPA;
		char a[100];
		string new_major;
		while (n!=4) {
			cout << "1-GPA\n2-Major\n3-Total Hours\n4-Return" << endl;
			cin >> n;
			switch (n) {
			case 1:cout << "New GPA: ";
				cin >> new_GPA;
				Student::ChangeGPA(new_GPA);
				break;
			case 2:cout << "New Major: ";
				i = readline(a, 100);
				for (j = 0; j <= i; j++)
					new_major.push_back(a[j]);
				Student::ChangeMajor(new_major);
				break;
			case 3:cout << "Total Hours: ";
				cin >> new_hours;
				Student::changeTotalHours(new_hours);
				break;
			case 4:
				break;
			default: cout << "Invalid option" << endl;
			}
		}
	}
	void Student::changeTotalHours(int k) {
		try {
			if (k > 0) {
				TotalHours = k;
				cout << "Total hours updated" << endl;
			}
			else
				throw "Invalid total hours!";
		}
		catch(const char* InvalidHour){
			cout << InvalidHour << endl;
		}
	}
