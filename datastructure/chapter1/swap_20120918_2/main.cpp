#include <iostream>
using namespace std;
class util
{
public:
	void swap(int &x,int &y);
};
void util::swap(int &x,int &y)
{
   int t;
   t=x;
   x=y;
   y=t;
}
int main()
{
   int i=3;
   int j=4;
   cout<<"i="<<i<<" j="<<j<<endl;
   util u;
   u.swap(i,j);
   cout<<"i="<<i<<" j="<<j<<endl;
   system("pause");

}
