#include <iostream>
#include <stack>
#include <exception>
using namespace std;
bool isOperator(char o)
{
	if(o=='+'||o=='-'||o=='*'||o=='/')
		return true;
	else
		return false;
}
double evaluator(char oprand1,char optr,char oprand2)
{
	float ret=0.0;
    switch(optr)
	{
	case '+': ret=oprand1+oprand2;break;
	case '-': ret=oprand1-oprand2;break;
	case '*': ret=oprand1*oprand2;break;
	case '/': 
		if(oprand2==0.0)
		{
           throw new exception("error");
		}
		else
		{
           ret=oprand1/oprand2; 
		}
		break;

	}
	return ret;
}
double evaluateSuffix() {
	char ch;
	double newOprand;
	stack<double>(s);
	double e1,e2,e3;
	while(cin>>ch,ch!='#'){
		if(!isOperator(ch)) 
		{
			cin.putback(ch);
			cin>>newOprand;
			s.push(newOprand);
		}
		else{
			
			e1=s.top();
			s.pop();
			e2=s.top();
			s.pop();
			e3 = evaluator(e2, ch, e1); 	// ���������
			s.push(e3);	
		} // else
	} // while
	e3=s.top();
	s.pop();
	if(!s.empty())
		throw new exception("error");
	return  e3;		// ���ؽ��
}
int main()
{
	cout<<"���ÿո����ÿ���������������������#��������4 3 5 * + #"<<endl;
   cout<<evaluateSuffix()<<endl;
}