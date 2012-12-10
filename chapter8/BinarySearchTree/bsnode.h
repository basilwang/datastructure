#ifndef BSNODE
#define BSNODE
template <class T> class bs_tree;
template <class T>
class bsnode
{
friend bs_tree<T>;
private:
	T data;
	bsnode<T> *left,*right;
	//利用parent结点 简化删除操作
	bsnode<T> *parent;
public:
	bsnode()
	{
      left=right=0;
	  parent=0;
	};
	bsnode(T &d,bsnode<T>* l,bsnode<T>* r)
	{
       data=d;
	   left=l;
	   right=r;

	};
};
#endif