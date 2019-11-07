template <typename T>
class BST{

public:
	BST();
	void insert(const T& data);
	void remove(const T& data);
	bool search(const T& data) const;
	void print() const;
	~BST();
};
