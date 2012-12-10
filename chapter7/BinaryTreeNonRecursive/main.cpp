#include <iostream>
#include "binary_tree.h"
using namespace std;
int main()
{
   binary_tree<char> bttree;
   cout<<"请按照先序输入,例如ab##cdf###eg##h##"<<endl;
   bttree.create();
   cout<<"递归输出"<<endl;
   bttree.preoutput();
   cout<<"非递归先序输出"<<endl;
   bttree.preoutput_nonrecursive();
   cout<<"非递归中序输出"<<endl;
   bttree.inoutput_nonrecursive();

}