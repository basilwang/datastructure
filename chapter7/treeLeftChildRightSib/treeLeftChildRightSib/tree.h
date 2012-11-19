#include <iostream>
#include <queue>
#include "node.h"

using namespace std;
class tree
{
private:
	node* root;
public:
	void create();
};
void tree::create()
{
   queue<node*> q;
   char parent;
   char child;
   char comma;
   node* leftSib;
   cin;
   while(cin>>parent>>child>>comma)
   {
	  if(child=='#')
		   break;
	  node* p;
	  p=new node;
	  p->data=child;
	  p->leftChild=p->rightSib=NULL;
	  q.push(p);
	  if(parent=='#')
	  {
		root=p;
	  }
	  else
	  {
		  while(parent!=q.front()->data)
		  {
			  q.pop();
		  }
		  node* parentNode=q.front();
		  if(!parentNode->leftChild)
		  {
			  parentNode->leftChild=p;
			  leftSib=p;
		  }
		  else
		  {
			  leftSib->rightSib=p;
			  leftSib=p;
		  }
	  }

   }
}