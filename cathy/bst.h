template <typename T>
class BST{

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
	void insertR(const T& data, Node*& subtreeroot){
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
public:
	BST(){
		root_=nullptr;
	}
	void insertR(const T& data){
		insertR(data,root_);
	}
	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			Node* curr=root_;
			bool inserted=false;
			while(!inserted){
				if(data < curr->data_){
					if(curr->left_!=nullptr){
						curr=curr->left_;
					}
					else{
						curr->left_=new Node(data);
						inserted=true;
					}
				}
				else{
					if(curr->right_!=nullptr){
						curr=curr->right_;
					}
					else{
						curr->right_=new Node(data);
						inserted=true;
					}
				}
			}
		}

	}
	void remove(const T& data){

	}
	bool search(const T& data) const{

	}
	void print() const{

	}
	~BST(){

	}
};
