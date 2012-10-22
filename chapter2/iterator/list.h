#include "dnode.h"
#include "iterator.h"
#include <iostream>
using std::ostream;
using std::endl;
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
	iterator<T> begin();
	iterator<T> end();
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
	//2012-10-22 ������51ҳinsert������̫һ�������Ϻ����е�����
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
template <class T>
iterator<T> list<T>::begin()
{
   return iterator<T>(header->right);
}
template <class T>
iterator<T> list<T>::end()
{
   return iterator<T>(header);
}
