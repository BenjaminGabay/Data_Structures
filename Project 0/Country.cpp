/*****************************************
** File:    Country.cpp
** Project: CSCE 221 Project 0, Spring 2019
** Author:  Benjamin Gabay
** Date:    1/23/2019
** Section: 510
** E-mail:  benjigabay@tamu.edu
**
**	This file contains the definitions for the Country class.
**
**
***********************************************/

#include "Country.h"

std::string Country::getName() const
{
	return name;
}

void Country::setName(std::string newName)
{
	name = newName;
}

long Country::getPopulation() const
{
	return population;
}

void Country::setPopulation(long newPop)
{
	population = newPop;
}

float Country::getLitteracyRate() const
{
	return litteracyRate;
}

void Country::setLitteracyRate(float newRate)
{
	litteracyRate = newRate;
}

float Country::getPrimCompFemale() const
{
	return primaryCompletionFemale;
}

void Country::setPrimCompFemale(float newComp)
{
	primaryCompletionFemale = newComp;
}

float Country::getPrimCompMale() const
{
	return primaryCompletionMale;
}

void Country::setPrimCompMale(float newComp)
{
	primaryCompletionMale = newComp;
}

float Country::getPrimCompTotal() const
{
	return primaryCompletionTotal;
}

void Country::setPrimCompTotal(float newComp)
{
	primaryCompletionTotal = newComp;
}

float Country::getEdGDPSpent() const
{
	return educationGDPSpent;
}

void Country::setEdGDPSpent(float newEducationGDPSpent)
{
	educationGDPSpent = newEducationGDPSpent;
}

float Country::getYouthLitRateFem() const
{
	return youthLitRateFem;
}

void Country::setYouthLitRateFem(float newLitRate)
{
	youthLitRateFem = newLitRate;
}

float Country::getYouthLitRateMale() const
{
	return youthLitRateMale;
}

void Country::setYouthLitRateMale(float newLitRate)
{
	youthLitRateMale = newLitRate;
}