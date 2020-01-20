/*****************************************
** File:    driver.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author:  Benjamin Gabay
** Date:    1/23/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the main driver program as well as some
** input helper functions for Project 0. This program reads in
** the input files of continent and country data and organizes it
** accordingly using the Continent and Country classes. The data for
** each continent is then exported to an output file.
**
**
***********************************************/

//All includes listed
#include <fstream>
#include <sstream>
#include <iostream>

#include "Continent.h"
#include "Country.h"

using namespace std;

//Global vector of continents to be used in main and input helpers
vector<Continent> continents;

//Helper function for repetative code to convert string data to float type
float checkFloatData(const istringstream& lineStream)
{
	string data;
	lineStream >> data;
	if(data == "N/A")
		{ return -1; }
	return stof(data);
}

//Helper input function to read in input file data
void readFromFiles(const ifstream& file1, const ifstream& file2)
{
	string line;
	getline(file1, line); //Skip first line
	vector<Country*> statCountries;
	string data;
	
	//Reads in statistical data for each country
	while(getline(file1, line) && line != "")
	{
		istringstream lineStream(line);
		Country* c = new Country;
		lineStream >> data;
		c->setName(data);
		lineStream >> data;
		if(data == "N/A")
			{ c->setPopulation(-1); }
		else
			{ c->setPopulation(stol(data)); }
		c->setLitteracyRate(checkFloatData(lineStream));
		c->setEdGDPSpent(checkFloatData(lineStream));
		c->setPrimCompTotal(checkFloatData(lineStream));
		c->setPrimCompMale(checkFloatData(lineStream));
		c->setPrimCompFemale(checkFloatData(lineStream));
		c->setYouthLitRateFem(checkFloatData(lineStream));
		c->setYouthLitRateMale(checkFloatData(lineStream));
		
		statCountries.push_back(c);
	}
	
	//Organizes countries into their appropriate continent
	string name;
	while(file2 >> name)
	{
		Continent cont;
		cont.setName(name);
		cont.setPopulation(0);
		cont.setHighestPop(nullptr);
		cont.setHighestGDP(nullptr);
		cont.setHighestLitRate(nullptr);
		int numCountries;
		file2 >> name >> numCountries; //Pass over dashes
		getline(file2, name); //Flush buffer
		for(int i = 0; i < numCountries; ++i)
		{
			getline(file2, name);
			for(int j = 0; j < statCountries.size(); ++j)
			{
				Country* c = statCountries.at(j);
				if(name == (c->getName()))
				{
					cont.addCountry(c);
					cont.setPopulation(cont.getPopulation() + c->getPopulation());
					if(cont.getHighestPop() == nullptr || c->getPopulation() > (cont.getHighestPop())->getPopulation())
						{ cont.setHighestPop(c); }
					if(cont.getHighestGDP() == nullptr || c->getEdGDPSpent() > (cont.getHighestGDP())->getEdGDPSpent())
						{ cont.setHighestGDP(c); }
					if(cont.getHighestLitRate() == nullptr || c->getLitteracyRate() > (cont.getHighestLitRate())->getLitteracyRate())
						{ cont.setHighestLitRate(c); }
				}
			}
		}
		continents.push_back(cont); //Adds continent to vector
	}
}

//Main method for project 0
int main()
{
	//Input files
	string fileName1 = "2013WorldBankEducationCensusData.txt";
	ifstream file1(fileName1);
	string fileName2 = "CountriesContinents.txt";
	ifstream file2(fileName2);
	readFromFiles(file1, file2);
	
	//Make output file
	ofstream output("output.txt");
	for(int i = 0; i < continents.size(); ++i)
		{ output << continents.at(i); }
	
	//Close all files
	file1.close();
	file2.close();
	output.close();
	
	return 0;
}