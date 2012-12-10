#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
using namespace std;
int main()
{
	cout<<"请输入先序序列（空节点用#）"<<endl;
   BinaryTree<char> tree;
   cout<<"先序序列是："<<endl;
   tree.PreOutput();
   cout<<"中序序列是："<<endl;
   tree.InOutput();
   cout<<"后序序列是："<<endl;
   tree.PostOutput();
   cout<<"树的高度是:" <<tree.Height()<<endl;
  return 0;
}