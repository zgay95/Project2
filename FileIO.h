#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileIO
{
private:
	string filename;
	vector <string> dataVector;
public:
	FileIO(string File);
	void readFile();
	void writeFile(vector <string> data);
	void printData();
	vector <string> returnData();
};
