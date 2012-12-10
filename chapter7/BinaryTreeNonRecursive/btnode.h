#ifndef BTNODE
#define BTNODE
template <class T> class binary_tree;
template <class T>
class btnode
{
friend binary_tree<T>;
private:
	T data;
	btnode<T> *left,*right;
public:
	btnode()
	{
      left=right=0;
	};
	btnode(T &d,btnode<T>* l,btnode<T>* r)
	{
       data=d;
	   left=l;
	   right=r;

	};
};
#endif