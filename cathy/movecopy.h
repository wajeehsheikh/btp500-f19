#include <iostream>
/****************************************/
/*                                      */
/* Lab 3 starter file                   */
/* V 1.1.1:fixed back_ typo in line 150 */
/* V 1.1: updated Sentinel::print()     */
/*        and sentinel::reversePrint()  */
/*                                      */
/*                                      */
/****************************************/
template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~DList();
	DList(const DList& other);
	DList(const DList&& other);
};

template <typename T>
DList<T>::::DList(const DList<T>& other){
	/*front_=back_=nullptr;
	for(auto it=other.cbegin();it!=other.cend();it++){
		push_back(*it);
	}*/
	

	front_=back_=nullptr;
	Node* curr=other.front_;
	while(curr){
		//create a new node out of curr
		Node* nn=new Node(curr->data_);
		//if linked list is empty
		if(front_==nullptr){
			front_=back_=nn;
		}
		else{
			//
		}
		//add it to back of current linked list
	}


}
/* steal data from other*/

template <typename T>
DList<T>::::DList(DList<T>&& other){
	front_=other.front_;
	back_=other.back_;
	other.front_=nullptr;
	other.back_=nullptr;	
}

template <typename T>
DList& DList<T>::operator=(const DList<T>& other){
	if(&other != this){
		//go through current object
		curr=front_;
		while(curr){
			//...
		}
		//destroy every node

		front_=back_=nullptr;
		for(auto it=other.cbegin();it!=other.cend();it++){
			push_back(*it);
		}
	}

	return *this;
}

template <typename T>
DList& DList<T>::operator=(DList<T>&& other){
	if(&other != this){
		Node* temp=front_;
		front_=other.front_;
		other.front_=temp;

		temp=back_;
		back_=other.back_;
		other.back_=temp;					
	}
	return *this;
}


template <typename T>
void DList<T>::push_front(const T& data){

	Node* nn=new Node(data,front_);
	if(front_){
		front_->prev_=nn;
	}
	else{
		back_=nn;
	}
	front_=nn;

}
template <typename T>
void DList<T>::push_back(const T& data){

}
template <typename T>
void DList<T>::pop_front(){
	if(front_){
		Node* rm = front_;
		front_=rm->next_;
		if(front_)
			front_->prev_=nullptr;
		}
		else{
			back_=nullptr;
		}
		delete rm;
	}
}
template <typename T>
void DList<T>::pop_back(){

}
template <typename T>
void DList<T>::print() const{
	Node* curr=front_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(!front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void DList<T>::reversePrint() const{
	Node* curr=back_;
	while(curr!=nullptr){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(!back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
DList<T>::~DList(){

}
template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data){

	Node* nn=new Node(data, front_->next_, front_);
	front_->next_=nn;
	nn->next_->prev_=nn;

}
template <typename T>
void Sentinel<T>::push_back(const T& data){

}
template <typename T>
void Sentinel<T>::pop_front(){
	if(front_->next_!=back_){
		Node* rm = front_->next_;
		rm->next_->prev_=rm->prev_;
		rm->prev_->next_=rm->next_;
/* v2:

		Node* rm = front_->next_;
		Node* n=rm->next_;
		Node* p=rm->prev_;
		n->prev_=p;
		p->next_=n;

*/		
		delete rm;
	}
}
template <typename T>
void Sentinel<T>::pop_back(){

}
template <typename T>
void Sentinel<T>::print() const{
	Node* curr=front_->next_;
	while(curr!=back_){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	if(front_->next_==back_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
void Sentinel<T>::reversePrint() const{
	Node* curr=back_->prev_;
	while(curr!=front_){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	if(back_->prev_==front_){
		std::cout << "empty list";
	}
	std::cout << std::endl;
}
template <typename T>
Sentinel<T>::~Sentinel(){

}
