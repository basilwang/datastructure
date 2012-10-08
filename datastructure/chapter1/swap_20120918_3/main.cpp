#include <iostream>
#include "util.h"
using namespace std;
int main()
{
   int i=3;
   int j=4;
   cout<<"i="<<i<<" j="<<j<<endl;
   util<int> u;
   u.swap(i,j);
   cout<<"i="<<i<<" j="<<j<<endl;
   system("pause");

}
