#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>



#include <cstdlib> //std::rand, std::srand
#include <ctime> //std::time
#include <algorithm> //std::random_shuffle

#define IN_FILEPATH "../lists"
#define OUT_FILEPATH "../lists"


class People {

public:

	std::string getFullName() { std::string fname; fname = _firstname + " " + _lastname; return fname; }//this just catenates first and last names
	std::string getFirstName() { return this->_firstname; }
	std::string getLastName() { return this->_lastname; }
	void setFirstName(std::string nametoset) { this->_firstname = nametoset; }
	void setLastName(std::string nametoset) { this->_lastname = nametoset; }
private:
	std::string _firstname;
	std::string _lastname;
};

void readInData(std::vector <People> &list)
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

		ss >> first;
		ss >> last;

		People person;
		person.setFirstName(first);
		person.setLastName(last);

		list.push_back(person);

	}

}
void printList(std::vector <People> list)
{

	std::cout << "List total is ";
	std::cout << list.size() << std::endl << std::endl;

	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i].getFullName() << std::endl;
	}

}




int myrandom(int i) { return std::rand() % i; }




int main()
{


	std::vector <People> rawlist; 
	readInData(rawlist);//read in the data

	std::vector <People> Alist;
	std::vector <People> Blist;



	printList(rawlist);//print out the list
}