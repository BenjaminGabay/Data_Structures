/*****************************************
** File:    Continent.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author:  Benjamin Gabay
** Date:    1/23/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the definitions for the Continent class.
**
**
***********************************************/

#include "Continent.h"

using namespace std;
		
vector<Country*> Continent::getCountriesInContinent()
{
	return countriesInContinent;
}

//Essentially the "setter" method but adds the pointer to the vector rather
//then overriding the variable
void Continent::addCountry(Country* newCountry)
{
	countriesInContinent.push_back(newCountry);
}

Country* Continent::getHighestPop() const
{
	return highestPopulation;
}

void Continent::setHighestPop(Country* newCountry)
{
	highestPopulation = newCountry;
}

Country* Continent::getHighestGDP() const
{
	return highestGDPSpent;
}

void Continent::setHighestGDP(Country* newCountry)
{
	highestGDPSpent = newCountry;
}

Country* Continent::getHighestLitRate() const
{
	return highestLiteracyRate;
}

void Continent::setHighestLitRate(Country* newCountry)
{
	highestLiteracyRate = newCountry;
}

//Overloads the output operator to output he Continent object with the desired format
//Returns a reference to an output stream
ostream& operator<<(ostream& os, const Continent& cont)
{
	os << cont.getName() << endl;
	os << " Population: " << cont.getPopulation() << endl;
	os << " Country with highest litteracy rate: " << (cont.getHighestLitRate())->getName();
	os << " with a population of " << (cont.getHighestLitRate())->getPopulation();
	os << " and a literacy rate of " << (cont.getHighestLitRate())->getLitteracyRate() << endl;
	os << " country with highest GDP spendature on education: " << (cont.getHighestGDP())->getName();
	os << " with a population of " << (cont.getHighestGDP())->getPopulation();
	os << " and a literacy rate of " << (cont.getHighestGDP())->getLitteracyRate() << endl;
	os << " country with highest population: " << (cont.getHighestPop())->getName();
	os << " with a population of " << (cont.getHighestPop())->getPopulation();
	os << " and a literacy rate of " << (cont.getHighestPop())->getLitteracyRate() << endl;
	return os;
}