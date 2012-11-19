class tree;
class node
{
friend class tree;
private:
	node* leftChild;
	node* rightSib;
	char  data;

};