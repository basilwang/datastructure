#include "list.h"
list::list(int max_list_size)
{
   max_size=max_list_size;
   n=0;
   data=new int[max_size];
}
void list::insert(int k, int x)
{
   for(int i=n-1;i>=k;i--)
   {
     data[i+1]=data[i];
   }
   data[k]=x;
   n++;
}
void list::printList(ostream& out) const
{
   for(int i=0;i<n;i++)
   {
	   out<<data[i]<<endl;
   }
}

