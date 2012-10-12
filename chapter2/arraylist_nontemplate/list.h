#include <iostream>
using namespace std;
class list {
private:
	int n;
	int max_size;
	int  * data; // ��Ԫ������
public:
	  list(int max_list_size = 10); // ���캯��
	  ~list( ) {delete [ ] data;} // ��������
	  bool empty( ) const {return n==0;}
	  int size( ) const {return n;}  
	  int locate(int x) const; 
	  // ���ر���Ԫ��xλ��
	  bool retrieve(int k, int x) const; 
	  //���ر��е�k��Ԫ�أ�����x�� 
	  void insert(int k, int x);       
	  //�ڱ��λ��k��֮�����Ԫ��x 
	  void erase(int k, int x);  
	  //�ӱ���ɾ��λ��k����Ԫ�أ�����x��
	  void printList(ostream& out) const;   
};