//Authors: Sebastian Grobelny Nicki Padar

#include "citylist.h"
#include "city.h"
#include <iostream>
int CityList::count=0;
CityNode::CityNode(City &cit, CityNode *nex) : city(cit), next(nex)
{
} //CityNode()

CityNode::~CityNode()
{
//	delete &city; 
} //~CityNode()

CityList::CityList() : head(NULL), tail(NULL)
{
} //constructor

CityList::~CityList()
{
	for (CityNode *ptr = head; ptr; ptr = head)
	{
		head = ptr -> next; //use head as a temp to store the next ptr
		delete ptr;
	}
}//destructor

City& CityList::operator[] (int index)
{
	CityNode *ptr = head;
	City city;

	for (int i = 0; ptr && i < index; i++, ptr = ptr->next);

	if (ptr)
		//cout << "index: " << index << '\n';
		//cout << "Operator City : " << ptr->city << '\n';
		return ptr->city;
  else
		return ptr->city;
	//example: obama[3] = 'b' bc changing obamas name
} //operator[]

const City& CityList::operator[] (int index)const
{
	CityNode *ptr = head;
	City city;

	for (int i = 0; ptr && i < index; i++, ptr = ptr->next);

	if (ptr)//ptr points to something that isnt null
		return ptr->city;
  else//ptr is pointing to null
	  return ptr->city;
	//example: cout << obama[3] not changing obamas name
} //operator[] const

CityList& CityList::operator+= (City& city)
{ 
	CityNode *ptr=NULL;
        
        if (!tail)
		{
             head = tail = new CityNode(city, ptr);
		}
	
       else	 
         {
          tail= tail -> next = new CityNode(city, ptr);
         }
        count++;
	return *this;
        
//if tail=null then head=tail=new citynode else tail=tail->next=new citynode....count++..return *this


} //operator+=

CityList& CityList::operator-= ( City& city1)
{
	CityNode *ptr;
        //cout << "Im getting deleted:" << city1;
	for (ptr = head; ptr && !(ptr->city == city1); ptr = ptr->next);//
        head = ptr->next;
	delete ptr;
	count--;
        return *this;

	//find in list, if not a city remove it from the linked list
}//operator-=

int CityList::getCount()const
{
	//cout << count << '\n';
	return count;
} //getCount
