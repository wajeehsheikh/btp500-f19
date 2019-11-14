template <typename T>
class AVL{

	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};
	Node* root_;
	/*this function will insert data into the subtree
	  with root subtreeroot*/
	void insert(const T& data, Node*& subtreeroot){
		if(subtreeroot == nullptr){
			subtreeroot=new Node(data);
		}
		else{
			if(data < subtreeroot->data_){
				insertR(data,subtreeroot->left_);
			}
			else{
				insertR(data,subtreeroot->right_);
			}
		}
	}
	void printInorder(const Node* subtree) const{
		if(subtree!=nulllptr){
			printInorder(subtree->left_);
			std::cout << subtree->data_ << " ";
			printInorder(subtree->right_);
		}
	}
	void destroy(Node* subtree){
		if(subtree){
			destroy(subtree->left_);
			destroy(subtree->right_);
			delete subtree;
		}
	}

public:
	AVL(){
		root_=nullptr;
	}
	void insert(const T& data){
		insert(data,root_);
	}


	bool search(const T& data) const{

	}
	//print from smallest to biggest
	void print() const{
		printInorder(root_);
	}
	void breadthFirstPrint() const{
		Queue<Node*> nodes;
		if(root_){
			nodes.enqueue(root_);
		}
		while(!nodes.isEmpty()){
			Node* curr=nodes.front();
			nodes.dequeue();
			std::cout << curr->data_ << " ";
			if(curr->left_){
				nodes.enqueue(curr->left_);
			}
			if(curr->right_){
				nodes.enqueue(curr->right_);
			}
		}


	}
	~AVL(){
		destroy(root_);

	}
};
