#include "bst.h"

int main(void){
	BST<int> tree;
	tree.insert(20);
	tree.insert(10);
	tree.insert(30);
	tree.insert(15);
	tree.insert(35);
	tree.insert(40);

	tree.print();
}