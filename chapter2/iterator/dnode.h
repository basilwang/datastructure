#ifndef DNODE_H
#define DNODE_H
template <class T> class list;
template <class T> class iterator;
template <class T>
class dnode
{
friend list<T>;
friend iterator<T>;
private:
   T data;
   dnode<T> *left,*right;
public:
	dnode(const T& _data=T(),dnode<T> *_left=0,dnode<T> *_right=0)
		:data(_data),left(_left),right(_right){}
};
#endif