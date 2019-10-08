#include "lab3.h"
template <class T>
class Stack{
	DList<T> theStack_;
	int size_;
public:
	Stack(){
		size_=0;
	}
	void push(const T& data){
		theStack_.push_front(data);
		size_++;
		//v2: theStack_.push_back(data);
	}
	void pop(){
		if(!isEmpty()){
			theStack_.pop_front();
			//v2: theStack_.pop_back();
			size_--;
		}
	}
	const T& top() const{
		return theStack_.front_->data_;
	}
	bool isEmpty() const{
		return size_==0;
	}
	~Stack(){
	}	
};