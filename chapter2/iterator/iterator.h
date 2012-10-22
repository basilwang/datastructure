#include "dnode.h"
template <class T> class list;
template <class T>
class iterator
{
friend list<T>;
public:
	iterator(){location=0;}
	iterator(dnode<T>* p):location(p){}
	T& operator *() {return location->data;}
	void operator =(const iterator& it)
	{
	 location=it.location;
	 n=it.n;
	 k=it.k;
	}
	bool operator !=(const iterator& it)
    {return location!=it.location;}
	iterator operator++(int)
	{
       iterator it(location);
	   location=location->right;
	   if(k>n) 
		   k-=n;
	   else
		   k++;
	   return it;
	}
protected:
	dnode<T> *location;
	int k,n;
};