#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define IN_FILEPATH "../lists"
#define OUT_FILEPATH "../lists"

int main()
{

	std::ostringstream inputFilePath;
	std::ostringstream myOutputFilePath;

	inputFilePath << IN_FILEPATH << "/names.txt";
	//need to make outputs for every name

	std::ifstream input;
	input.open(inputFilePath.str());
	

	std::string line;
	std::string first;
	std::string last;

	while (1)
	{

		if (input.eof() == true)
		{
			break;
		}

		getline(input, line);
		std::istringstream ss(line);


		std::cout << line << std::endl;



	}




}