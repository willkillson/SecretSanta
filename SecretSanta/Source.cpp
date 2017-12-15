#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>



#include <cstdlib> //std::rand, std::srand
#include <ctime> //std::time
#include <algorithm> //std::random_shuffle

#define IN_FILEPATH "../lists"
#define OUT_FILEPATH "../lists/Finished/"


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
	input.close();

}
void printList(std::vector <People> list)
{
	std::cout << std::endl;
	std::cout << "List total is ";
	std::cout << list.size() << std::endl << std::endl;

	for (unsigned int i = 0; i < list.size(); i++)
	{
		std::cout << list[i].getFullName() << std::endl;
	}

}
void splitIntoTwoLists(std::vector <People> rawlist, std::vector <People> &Alist, std::vector <People> &Blist)
{
	for (unsigned int  i = 0; i < rawlist.size(); i++)
	{
		if (i % 2 == 0)
		{
			Alist.push_back(rawlist[i]);
		}
		else
		{
			Blist.push_back(rawlist[i]);
		}
	}

}
void randomizeTheList(std::vector <People> &rawlist)
{
	std::random_shuffle(rawlist.begin(), rawlist.end());
	std::random_shuffle(rawlist.begin(), rawlist.end());
	std::random_shuffle(rawlist.begin(), rawlist.end());
	std::random_shuffle(rawlist.begin(), rawlist.end());
	std::random_shuffle(rawlist.begin(), rawlist.end());
	std::random_shuffle(rawlist.begin(), rawlist.end());
	

}
void writeOutData(std::vector <People> Alist, std::vector <People> Blist)
{

	std::ofstream output;

	for (unsigned int  i = 0; i < Alist.size(); i++)
	{
		std::ostringstream myOutputFilePath;
		myOutputFilePath << OUT_FILEPATH << Alist[i].getFirstName() << Alist[i].getLastName() << ".txt";
		output.open(myOutputFilePath.str());
		output << Blist[i].getFullName();
		output.close();
	}
	for (unsigned int  i = 0; i < Blist.size(); i++)
	{
		std::ostringstream myOutputFilePath;
		myOutputFilePath << OUT_FILEPATH << Blist[i].getFirstName() << Blist[i].getLastName() << ".txt";
		output.open(myOutputFilePath.str());
		output << Alist[i].getFullName();
		output.close();
	}

}


int main()
{
	//Read information from file to populate the raw list
	//randomize the raw list
	//split the raw list into two seperate lists
	//the pairing of the first and section vector lists are the matches
	//output the matches

	std::vector <People> rawlist; 
	std::vector <People> Alist;
	std::vector <People> Blist;


	readInData(rawlist);//read in the data
	printList(rawlist);
	randomizeTheList(rawlist);
	splitIntoTwoLists(rawlist, Alist, Blist);

	writeOutData(Alist, Blist);
}