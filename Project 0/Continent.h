/*****************************************
** File:    Continent.h
** Project: CSCE 221 Project 0, Spring 2019
** Author:  Benjamin Gabay
** Date:    1/23/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This header file contains the declarations for the Continent class which
** is an extension of the country class. This class contains a vector of
** countries that belong to the continent as well as pointers to specific
** countries within the continent with the highest population, GDP spending,
** and literacy rate. There are getter/setter functions for each member as well
** as a function to add countries to the continent. There is also an function that
** overloads the output operator to display the continent data as desired.
**
**
***********************************************/

//Header gaurds
#ifndef CONTINENT_H
#define CONTINENT_H

#include <iostream>
#include <vector>

#include "Country.h"

class Continent : public Country
{	
	public:
		std::vector<Country*> getCountriesInContinent();
		void addCountry(Country* newCountry); //Adds pointer to new country to vector
		Country* getHighestPop() const;
		void setHighestPop(Country* newCountry);
		Country* getHighestGDP() const;
		void setHighestGDP(Country* newCountry);
		Country* getHighestLitRate() const;
		void setHighestLitRate(Country* newCountry);
		
	private:
		std::vector<Country*> countriesInContinent;
		Country* highestPopulation;
		Country* highestGDPSpent;
		Country* highestLiteracyRate;
};

//Overloads the output operator to output the Continent object with the desired format
std::ostream& operator<<(std::ostream& os, const Continent& cont);

#endif