#include <iostream>
#include <stack>
#include <exception>
using namespace std;
void parenthesis(char *expr);
int main()
{
    char* s="(x*(x+y)-z";
    parenthesis(s);
	return 0;
}
void parenthesis(char *expr)
{
   int max_size=5;
   stack<int> s;
   int j,n=strlen(expr);
   for(int i=1;i<=n;i++)
   {
      if(expr[i-1]=='(') 
		  s.push(i);
	  else if(expr[i-1]==')')
	  {
		if(!s.empty())
		{
	    j=s.top();
        s.pop();
		cout<<j<<' '<<i<<endl;
		}
		else
		cout<<"位置"<<i<<"处的右括号不匹配"<<endl;
		
	  }
	  
   }
   while(!s.empty())
   {
	 j=s.top();
     s.pop();
	 cout<<"位置"<<j<<"处的左括号不匹配"<<endl;
   }
} 