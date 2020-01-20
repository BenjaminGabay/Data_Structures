/*****************************************
** File:    Country.h
** Project: CSCE 221 Project 0, Spring 2019
** Author:  Benjamin Gabay
** Date:    1/23/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This header file contains the declarations for the Country class.
** The class countains multiple data members for all of the data included
** in the input file as well as getter/setter functions for each data member.
**
**
***********************************************/

//Header gaurds
#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country
{
	//Public class functions declared
	public:
		std::string getName() const;
		void setName(std::string newName);
		long getPopulation() const;
		void setPopulation(long newPop);
		float getLitteracyRate() const;
		void setLitteracyRate(float newRate);
		float getPrimCompFemale() const;
		void setPrimCompFemale(float newComp);
		float getPrimCompMale() const;
		void setPrimCompMale(float newComp);
		float getPrimCompTotal() const;
		void setPrimCompTotal(float newComp);
		float getEdGDPSpent() const;
		void setEdGDPSpent(float newEducationGDPSpent);
		float getYouthLitRateFem() const;
		void setYouthLitRateFem(float newLitRate);
		float getYouthLitRateMale() const;
		void setYouthLitRateMale(float newLitRate);
	
	//Private data members declared
	private:
		std::string name;
		long population;
		float litteracyRate;
		float primaryCompletionFemale;
		float primaryCompletionMale;
		float primaryCompletionTotal;
		float educationGDPSpent;
		float youthLitRateFem;
		float youthLitRateMale;
};

#endif