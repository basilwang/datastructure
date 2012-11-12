#include <iostream>
using namespace std;
int recursiveInfinite(int n);
int recursiveSuccess(int n);
int main()
{
    recursiveInfinite(10);
	//cout<<recursiveSuccess(10);
	return 0;
}
int recursiveInfinite(int n)
{	
    return n*recursiveInfinite(n-1);
}
int recursiveSuccess(int n)
{
	 if(n==0) 
     {return 1;} 
	 else
    return n*recursiveSuccess(n-1);
}