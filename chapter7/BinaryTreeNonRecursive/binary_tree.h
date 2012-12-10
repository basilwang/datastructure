
#include <iostream>
#include <stack>
#include "btnode.h"
using namespace std;
template <class T>
class binary_tree
{
private:
	btnode<T>* root;
	void create(btnode<T> *&node);
	void preorder(btnode<T> *node);
public:
	void create();
	void preoutput();
	void preoutput_nonrecursive();
	void inoutput_nonrecursive();
	
};
template <class T>
void binary_tree<T>::create(btnode<T> *&node)
{
   char c;
   cin>>c;
   if(c!='#')
   {
       node = new btnode<T>;
	   node->data=c;
	   create(node->left);
	   create(node->right);
   }
   else
   {
       return;
   }
}
template <class T>
void binary_tree<T>::create()
{
   create(root);
}
template <class T>
void binary_tree<T>::preorder(btnode<T> *node)
{
  if(node==NULL)
  {
     return ;
  }
  else
  {
     cout<<node->data<<endl;
	 preorder(node->left);
	 preorder(node->right);
  }
}
template <class T>
void binary_tree<T>::preoutput()
{
   preorder(root);
}
template <class T>
void binary_tree<T>::preoutput_nonrecursive()
{
   stack<btnode<T>*> s;
   s.push(root);
   while(!s.empty())
   {
	   
	   btnode<T>* p=s.top();
	   s.pop();
       while(p)
	   {
	     cout<<p->data<<endl;
		 if(p->right!=NULL)
			 s.push(p->right);
	     p=p->left;
	   }

   }

}
template <class T>
void binary_tree<T>::inoutput_nonrecursive()
{
   stack<btnode<T>*> s;
   btnode<T>* p=root;
   //s.push(root);
   while(p)
   {
      if(p->left!=NULL)
	  {
		  s.push(p->left);
		  //p=p->left;
	  }
	  else
	  {
		  cout<<p->data<<endl;
		  s.pop();
		  //此时p没有改变指向 切记
		  if(p->right!=NULL)
		  {
			  s.push(p->right);
		  }
		  else
		  {
			  p=s.top();
		  }
	  }
	  

   }


}