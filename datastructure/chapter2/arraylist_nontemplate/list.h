#include <iostream>
using namespace std;
class list {
private:
	int n;
	int max_size;
	int  * data; // 表元素数组
public:
	  list(int max_list_size = 10); // 构造函数
	  ~list( ) {delete [ ] data;} // 析构函数
	  bool empty( ) const {return n==0;}
	  int size( ) const {return n;}  
	  int locate(int x) const; 
	  // 返回表中元素x位置
	  bool retrieve(int k, int x) const; 
	  //返回表中第k个元素，存于x中 
	  void insert(int k, int x);       
	  //在表的位置k处之后插入元素x 
	  void erase(int k, int x);  
	  //从表中删除位置k处的元素，存入x中
	  void printList(ostream& out) const;   
};