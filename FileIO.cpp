#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include "FileIO.h"

using namespace std;

FileIO::FileIO(string filename) {
	this->filename = filename;
}


void FileIO::readFile() {
	string temp;
	ifstream input_file;  
	input_file.open(this->filename);
	/*While loop checks if file was opened successfully*/
	while (input_file.good())
	{
		if (!getline(input_file, temp)) 
		{ break; }

		istringstream ss(temp);
		/*while the input file has another line*/
		while (ss)
		{
			string s;
			if (!getline(ss, s, ',')) break;
			this->dataVector.push_back(s);
			
		}
	}
	/*Check if data was successfulyl laoded into vector, if not display error*/
	if (this->dataVector.empty())
	{
		cout << "Error reading "<< this->filename << " file." << endl;
	}
	/*Done recieving data, close the stream*/
	input_file.close();

	/*Uncomment code below to see data values being read into vector*/
	//this->printData();
}

void FileIO::writeFile(vector <string> data) {
	ofstream output_file;
	output_file.open(this->filename);
	/*If statement checks if passed vector is empty. if it is then throw error otherwise write to file*/
	if (!data.empty())
	{	
		ostream_iterator<string> output_newline_iterator(output_file, "\n");
		copy(data.begin(), data.end(), output_newline_iterator);
	}
	else
	{
		cout << "No data passed to write to " << this->filename << " file." << endl;
	}	 
	/*Done writing data, close the stream*/
	output_file.close();
}

vector <string> FileIO::returnData() {
	return this->dataVector;
}

void FileIO::printData() {
	for (string i : this-> dataVector)
	{
		cout << i << endl;
	}
}
