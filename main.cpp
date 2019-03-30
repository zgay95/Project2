/*Porject 2 - Application for Students and advisors to manage their data*/
#include <iostream>
#include <string>
#include "FileIO.h"
using namespace std;
											// Below is how the data is organized in the related file.
#define StudentData  "StudentData.txt"		// StudentID, Password, FirstName, LastName, Major, GPA, HoursEarned
#define StudentNotes "StudentNotesData.txt" // StudentID, Notes
#define AdvisorData  "AdvisorData.txt"		// AdvisorID, Password, FirstName, LastName, Phone#, Room#
#define AdviseeData  "AdviseeData.txt"		// AdvisorID, StudentID, StudentID, StudentID, ..., ..., ...

int main() {
	/*Create FileIO objects*/
	FileIO stData(StudentData);
	FileIO stNotes(StudentNotes);
	FileIO adData(AdvisorData);
	FileIO adST(AdviseeData);

	/*Read Data from Files before program starts*/
	stData.readFile();
	stNotes.readFile();
	adData.readFile();
	adST.readFile();

	/*Ask for user id and password here*/


	return 0;
}
