#include <iostream>
#include "binary_tree.h"
using namespace std;
int main()
{
   binary_tree<char> bttree;
   cout<<"�밴����������,����ab##cdf###eg##h##"<<endl;
   bttree.create();
   cout<<"�ݹ����"<<endl;
   bttree.preoutput();
   cout<<"�ǵݹ��������"<<endl;
   bttree.preoutput_nonrecursive();
   cout<<"�ǵݹ��������"<<endl;
   bttree.inoutput_nonrecursive();

}