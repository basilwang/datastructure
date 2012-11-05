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
	ret = evaluatorImp(left_opnd, optr_top, right_opnd); 	// ���������
	opnd.push(ret);	

}

// ����������ȼ�
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
		   //����ǿ�ͷ��#,���������ջ
		   if(optr.size()==0)
		   {
               optr.push(ch);
		   }
		   else
		   {
                optr_top=optr.top();
				//����ջ��Ҳ��#,���˳�ѭ��
				if(isPoundSign(optr_top))
				{
                   break;
				}
				else
				{
                   
					//����ǰ��������ݲ�����
					cin.putback(ch);
					//�Ӳ�����ջ�����������������������ջ����һ�����������������ָ�������������ջ
					evaluator(optr,opnd);
				
				}
 
				

		   }

		}
		//���ǡ��������������ջ
		else if(isLeftParenthesis(ch))
		{
           optr.push(ch);
		}
		//���ǡ�����
		else if(isRightParenthesis(ch))
		{
            //�������ջ���ǡ��������򵯳�ջ��Ԫ��
            optr_top=optr.top();
			if(isLeftParenthesis(optr_top))
			{
				optr.pop();
			}
			else
			{
				//����ǰ��������ݲ�����
                cin.putback(ch);
				//�Ӳ�����ջ�����������������������ջ����һ�����������������ָ�������������ջ
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
                //����ǰ��������ݲ�����
                cin.putback(ch);
				//�Ӳ�����ջ�����������������������ջ����һ�����������������ָ�������������ջ
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
	return  ret;		// ���ؽ��
}
int main()
{
	cout<<"���ÿո����ÿ���������������������#��������# 4 + 3 * 5 #"<<endl;
   cout<<evaluateSuffix()<<endl;
}