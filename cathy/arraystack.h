template <class T>
class Stack{
	T* array_;
	int capacity_;
	int used_;
	void grow(){
		T* tmp=new T[capacity_*2];
		for(int i=0;i<used_;i++){
			tmp[i]=array_[i];
		}
		delete [] array;
		array_=tmp;
		capacity_=capacity_*2;
	}
public:
	Stack(int cap=13){
		array_=new T[cap];
		capacity_=cap;
		used_=0;
	}
	void push(const T& data){
		if(used_==capacity_){
			grow();
		}
		array_[used_++]=data;
	}
	void pop(){
		if(used_ > 0){
			used_--;
		}
	}
	T top() const{
		T rc;
		if(used_ > 0)
			rc=array_[used_-1];
		return rc;
	}
	bool isEmpty() const{
		return used_==0;
	}
	~Stack(){
		delete [] array_;
	}	
};