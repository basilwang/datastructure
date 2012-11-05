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
bool isLeftParenthesis(char o)
{
    if(o=='(')
		return true;
	else
		return false;
}
bool isPoundSign(char o)
{
	if(o=='#')
		return true;
	else
		return false;
}
bool isRightParenthesis(char o)
{
    if(o==')')
		return true;
	else
		return false;
}
double evaluatorImp(double oprand1,char optr,double oprand2)
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
void evaluator(stack<char> &optr, stack<double> &opnd)
{
	double left_opnd,right_opnd,ret;
	char optr_top;
   	right_opnd=opnd.top();
	opnd.pop();
	left_opnd=opnd.top();
	opnd.pop();
    optr_top=optr.top();
	optr.pop();
	ret = evaluatorImp(left_opnd, optr_top, right_opnd); 	// 运算符计算
	opnd.push(ret);	

}

// 求运算符优先级
int priority(char op)
{
	switch(op)
	{
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default :
		return -1;
	}
}
double evaluateSuffix() {
	char ch;
	double newOprand,ret;
	stack<double>(opnd);
	stack<char>(optr);
	char optr_top;
	while(cin>>ch){

        if(isPoundSign(ch))
		{
		   //如果是开头的#,则入操作符栈
		   if(optr.size()==0)
		   {
               optr.push(ch);
		   }
		   else
		   {
                optr_top=optr.top();
				//否则栈顶也是#,则退出循环
				if(isPoundSign(optr_top))
				{
                   break;
				}
				else
				{
                   
					//否则当前读入符号暂不处理
					cin.putback(ch);
					//从操作数栈弹出两个操作数，从运算符栈弹出一个运算符，生成运算指令，结果送入操作数栈
					evaluator(optr,opnd);
				
				}
 
				

		   }

		}
		//若是“（”，进运算符栈
		else if(isLeftParenthesis(ch))
		{
           optr.push(ch);
		}
		//若是“）”
		else if(isRightParenthesis(ch))
		{
            //当运算符栈顶是“（”，则弹出栈顶元素
            optr_top=optr.top();
			if(isLeftParenthesis(optr_top))
			{
				optr.pop();
			}
			else
			{
				//否则当前读入符号暂不处理
                cin.putback(ch);
				//从操作数栈弹出两个操作数，从运算符栈弹出一个运算符，生成运算指令，结果送入操作数栈
                evaluator(optr,opnd);
			}


		}
		else if(isOperator(ch))
		{
            optr_top=optr.top();
			if(priority(ch)>priority(optr_top))
			{
				optr.push(ch);
                
			}
			else
			{
                //否则当前读入符号暂不处理
                cin.putback(ch);
				//从操作数栈弹出两个操作数，从运算符栈弹出一个运算符，生成运算指令，结果送入操作数栈
                evaluator(optr,opnd);
			}


		}
		else 
		{
			cin.putback(ch);
			cin>>newOprand;
			opnd.push(newOprand);
		}
	} // while
	ret=opnd.top();
	opnd.pop();
	if(!opnd.empty())
		throw new exception("error");
	return  ret;		// 返回结果
}
int main()
{
	cout<<"请用空格隔开每个操作数或操作符，并以#结束，例# 4 + 3 * 5 #"<<endl;
   cout<<evaluateSuffix()<<endl;
}