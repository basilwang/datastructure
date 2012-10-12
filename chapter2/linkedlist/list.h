#include "node.h"
#include <iostream>
using namespace std;
template<class T>
class list {  
private:
	node<T> *first;
public:
	list() {first = 0;}
	~list();
	bool empty( ) const {return first == 0;}
	int size( ) const;
	bool retrieve(int k, T& x) const;
	int locate(const T& x) const;
	list<T>& insert(int k, const T& x);
	list<T>& erase(int k, T& x);
	void printList(ostream& out) const;  
};
template<class T>
list<T>& list<T>::insert(int k, const T& x)
{
	node<T> *p=new node<T>;
	p->data=x;
	if(k==0)
	{
		p->next=first;
		first=p;
	}
	else
	{
	   node<T> *q=first;
       for(int i=1;i<=k-1;i++)
	   {
         q=q->next;
	   }
	   p->next=q->next;
	   q->next=p;
	}
	return *this;
}
template<class T>
list<T>::~list()
{

}
template <class T>
void list<T>::printList(ostream& out) const
{
   node<T> *q=first;
   while(q)
   {
      out<<q->data<<endl;
	  q=q->next;
   }
}
