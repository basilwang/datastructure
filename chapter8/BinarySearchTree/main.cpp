#include <iostream>
#include "bs_tree.h"
using namespace std;
int main()
{
   bs_tree<char> bs;
   char c;
   cout<<"�����뵥�����֣��Կո�ֿ�����β��#�Ž���������5 7 2 3 #"<<endl;
   while(cin>>c,c!='#')
   {
	   bs.insert(c);

   }
   bs.InOutput();
   system("pause");
   bs.deleteNode('5');
   bs.InOutput();
   system("pause");

}