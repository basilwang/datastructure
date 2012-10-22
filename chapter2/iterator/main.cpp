#include "list.h"
#include <iostream>
using std::cout;
int main()
{
   list<int> l;
   l.insert(0,3);
   l.insert(0,2);
   l.insert(0,1);
   l.insert(3,4);
   l.printList(cout);
   for(iterator<int> it=l.begin();it!=l.end();it++)
   {
	   cout<<*it<<endl;
   }
   system("pause");


}