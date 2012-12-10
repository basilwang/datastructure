#include "bsnode.h"
template <class T>
class bs_tree
{
private:
	bsnode<T>* root;
    void InOrder(bsnode<T> *t);
public:
	bs_tree(){root=0;}
	bsnode<T>* insert(const T &x);
	bsnode<T>* deleteNode(const T &x);
	void InOutput( ) {InOrder(root); cout << endl;}


};
template <class T>
bsnode<T>* bs_tree<T>::insert(const T &x)
{
	bsnode<T> *p=root;
	bsnode<T> *parent=0;
	while(p)
	{
		parent=p;
		if(x<p->data)
			p=p->left;
		else if(x>p->data)
			p=p->right;
		else
			return 0;

	}
	bsnode<T> *y=new bsnode<T>;
	y->data=x;
	if(parent)
	{
		if(x<parent->data)
		{
			parent->left=y;
		}
		else
		{
			parent->right=y;
		}
		y->parent=parent;
	}
	else
	{
		root=y;
	}
	return y;

}
template <class T>
bsnode<T>* bs_tree<T>::deleteNode(const T &x)
{
    bsnode<T> *p=root;
	bsnode<T> *pp=0;
	while(p&&p->data!=x)
	{
		pp=p;
		if(x<p->data)
			p=p->left;
		else if(x>p->data)
			p=p->right;

    } 
	if(p->left&&p->right)
	{
       bsnode<T>* s=p->left;
	   bsnode<T>* ps=p; 
	   while(s->right)
	   {
          ps=s;
          s=s->right;
	   }
	   p->data=s->data;
	   p=s;
	   pp=ps;        
	}
	bsnode<T> *c=0;
	if(p->left)
	{
	   c=p->left;
	}
	if(p->right)
	{
       c=p->right;
	}

	if(pp->left==p)
	{
       pp->left=c;
	}
	else
	{
       pp->right=c;
	}
    delete p;
   return 0;
}
template <class T>
void bs_tree<T>::InOrder(bsnode<T> *t)
{
	if(t==NULL)
		return;
	else
	{
		InOrder(t->left);
		cout<<t->data;
		InOrder(t->right);
	}
}