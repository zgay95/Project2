#include<iostream>
#include<string>
#include "Student.h"
#include"User.h"

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
string Student::GetID() {
	return User::GetuserID();
}
string Student::GetPassword() {
	return User::Getpassword();
}
string Student::GetFirstName() {
	return this->firstName;
}
string Student::GetLastName() {
	return this->lastName;
}
string Student::GetMajor() {
	return this->major;
}
string Student::GetTotalHours() {
	return to_string(this->TotalHours);
}
string Student::GetGPA() {
	return to_string(this->GPA);
}
vector<string> Student::GetNotes() {
	return this->notes;
}
void Student::view() {
	for (string a : notes)//For some reason it is not printing the notes
		cout << a << endl;

	cout << endl;
	cout << "Student ID: " << User::GetuserID() << "\n" << firstName << " " << lastName << "`s major: " << major << "\nTotal Hours: " << TotalHours << "\nGPA: " << GPA << endl;
}
void Student::menu() {
	cout << "========== Menu ==========\n\n0-View advisor information\n1-View information\n2-Update information\n3-Exit\n\n==========================\n" << endl;
}
void Student::Change(string f) {
	major = f;
	cout << "Major updated successfully!!" << endl;
}
void Student::Change(double g) {
	try {
		if (g<0.0 || g>4.0) {

			throw "GPA should be between 0.0 and 4.0";
		}
		else {
			GPA = g;
			cout << "GPA updated successfully!!" << endl;
		}
	}
	catch (const char* Invalidgpa) {
		cout << Invalidgpa << endl;
	}
}
void Student::update() {
	int n = 0, i, j, new_hours;
	double new_GPA;
	char a[100];
	string new_major;
	while (n != 4) {
		cout << "========== Menu ==========\n\n1-Update GPA\n2-Update Major\n3-Update Total Hours\n4-Exit\n\n==========================\n\n" << endl;
		cout << "Enter selection: ";
		cin >> n;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (n) {
		case 1:cout << "New GPA: ";
			cin >> new_GPA;
			Student::Change(new_GPA);
			break;
		case 2:cout << "New Major: ";
			i = readline(a, 100);
			for (j = 0; j <= i; j++)
				new_major.push_back(a[j]);
			Student::Change(new_major);
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
	catch (const char* InvalidHour) {
		cout << InvalidHour << endl;
	}
}

void Student::SetNote(string Note) {
	notes.push_back(Note);
}
