#include "BinaryTreeNode.h"
template<class T>
class BinaryTree 
{
	   public:
			   //BinaryTree( ) {root = 0;};//初始化为空
			   BinaryTree( ) {Create(root);}
			   ~BinaryTree( ){ }; //消除空二叉树    
			   void PreOutput( ) {PreOrder(root); cout << endl;}        
			   void InOutput( ) {InOrder(root); cout << endl;}
			   void PostOutput( ){PostOrder(root); cout << endl;}
			   int Height( ) const {return Height(root);}//注意区分同名函数
	private:
			  BinaryTreeNode<T> *root;  // 树根(唯一的成员数据)
			  void Create(BinaryTreeNode<T> *  &r);       
			  void PreOrder(BinaryTreeNode<T> *t);
			  void InOrder(BinaryTreeNode<T> *t);
			  void PostOrder(BinaryTreeNode<T> *t);         
			 int Height(BinaryTreeNode<T> *t) const;
//用递归的方式求二叉树中结点*t的高度
};
template<class T>
void BinaryTree<T> ::Create(BinaryTreeNode<T> *  &r)
{
	char ch;
    cin>>ch;
    if (ch=='#')     r=NULL; 
    else {
        r=new BinaryTreeNode<T>; 
        r->data=ch;
        Create(r->LeftChild); 
        Create(r->RightChild); 
    }  
}
template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *t)
{
	if(t==NULL)
		return;
	else
	{
		InOrder(t->LeftChild);
		cout<<t->data;
		InOrder(t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *t)
{
	if(t==NULL)
		return;
	else
	{
		cout<<t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *t)
{
	if(t==NULL)
		return;
	else
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout<<t->data;
	}
}
template<class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t) const
{
      if(t==NULL)
		  return -1;
	  else
	  {
           int l=Height(t->LeftChild);
		   int r=Height(t->RightChild);
		   return (l>=r?l:r)+1;
	  }
}

