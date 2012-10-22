#include "dnode.h"
#include <iostream>
using namespace std;
template<class T>
class list {  
private:
	dnode<T> *header;
	int n;
public:
	list();
	~list();
	bool empty( ) const {return n == 0;}
	int size( ) const;
	bool retrieve(int k, T& x) const;
	int locate(const T& x) const;
	list<T>& insert(int k, const T& x);
	list<T>& erase(int k, T& x);
	void printList(ostream& out) const;  
};
template<class T>
list<T>::list()
{
    header=new dnode<T>();
	header->left=header;
	header->right=header;
	n=0;

}
template<class T>
list<T>& list<T>::insert(int k, const T& x)
{
	dnode<T> *y=new dnode<T>;
	y->data=x;
	//2012-10-22 和书上51页insert方法不太一样，书上好像有点问题
	dnode<T> *p=header;
    for(int i=0;i<=k-1;i++)
	{
     p=p->right;
	}
	y->right=p->right;
	y->left=p;
	p->right->left=y;
	p->right=y;
	n++;
	return *this;
}
template<class T>
list<T>::~list()
{

}
template <class T>
void list<T>::printList(ostream& out) const
{
	for(dnode<T> *current=header->right;current!=header;current=current->right)
	{
		out<<current->data<<endl;
	}
}
