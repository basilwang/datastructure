#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
using namespace std;
int main()
{
	cout<<"�������������У��սڵ���#��"<<endl;
   BinaryTree<char> tree;
   cout<<"���������ǣ�"<<endl;
   tree.PreOutput();
   cout<<"���������ǣ�"<<endl;
   tree.InOutput();
   cout<<"���������ǣ�"<<endl;
   tree.PostOutput();
   cout<<"���ĸ߶���:" <<tree.Height()<<endl;
  return 0;
}