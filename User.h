//
//  User.cpp
//  
//
//  Created by Jose Monge on 4/12/19.
//
#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class User {

private:
	string userID;
	string password;
public:
	User(string a, string b);
	string GetuserID();
	string Getpassword();
};
#endif 
