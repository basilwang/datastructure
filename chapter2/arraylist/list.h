#include <iostream>
using namespace std;
template<class T>
class list {
private:
	int n;
	int max_size;
	T  * data; // 表元素数组
public:
	  list(int max_list_size = 10); // 构造函数
	  ~list( ) {delete [ ] data;} // 析构函数
	  bool empty( ) const {return n = = 0;}
	  int size( ) const {return n;}  
	  int locate(const T& x) const; 
	  // 返回表中元素x位置
	  bool retrieve(int k, T& x) const; 
	  //返回表中第k个元素，存于x中 
	  list<T>& insert(int k, const T& x);       
	  //在表的位置k处之后插入元素x 
	  list<T>& erase(int k, T& x);  
	  //从表中删除位置k处的元素，存入x中
	  void printList(ostream& out) const;   
};
template<class T>
list<T>::list(int max_list_size)
{
   max_size=max_list_size;
   n=0;
   data=new T[max_size];
}
template<class T>
list<T>& list<T>::insert(int k, const T& x)
{
   for(int i=n-1;i>=k;i--)
   {
     data[i+1]=data[i];
   }
   data[k]=x;
   n++;
   return *this;
}
template <class T>
void list<T>::printList(ostream& out) const
{
   for(int i=0;i<n;i++)
   {
	   out<<data[i]<<endl;
   }
}
