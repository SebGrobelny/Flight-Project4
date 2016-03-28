//Authors: Sebastian Grobelny Nicki Padar
#ifndef CITYLIST_H
	#define CITYLIST_H

#include "city.h"
class City;
class CityList;

class CityNode
{
	City city;
	CityNode *next;
	CityNode(City &cit, CityNode *nex);
	~CityNode();
	friend class CityList;
}; //class CityNode

class CityList
{	
	CityNode *head;
	CityNode *tail;
	static int count;
public:
	CityList();
	~CityList();
	int getCount()const;
	City& operator[] (int index);
	const City& operator[] (int index)const;
	CityList& operator+= (City& city);
	CityList& operator-= (City& city1);
}; //class CityList

#endif 
