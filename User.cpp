#include<iostream>
#include<string.h>
#include "User.h"

using namespace std;

User::User(string a, string b) {
	userID = a;
	password = b;
}
string User::GetuserID() {
	return userID;
}
string User::Getpassword() {
	return password;
}
