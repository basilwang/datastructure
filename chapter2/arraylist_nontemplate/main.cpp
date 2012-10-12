#include "list.h"

int main()
{
   list l;
   l.insert(0,3);
   l.insert(0,2);
   l.insert(0,1);
   l.insert(3,4);
   l.printList(cout);
   system("pause");


}