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

public:
	BST();
	void insert(const T& data);
	void remove(const T& data);
	bool search(const T& data) const;
	void print() const;
	~BST();
};
