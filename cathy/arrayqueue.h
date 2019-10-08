template <class T>
class Queue{
	T* array_;
	int capacity_;
	int used_;
	int front_;
	int back_;
public:
	Queue(int cap=13){
		array_=new T[cap];
		capacity_=cap;
		used_=0;
		front_=0;
		back_=0;		
	}
	void enqueue(const T& data){
		if(used_ == capacity_){
			grow();
		}
		array_[back_]=data;
		back_=(back_+1)%capacity_;
		used_++;
	}
	void dequeue(){
		if(used_ > 0){
			used_--;
			front_=((front_==capacity_-1)?0:front_+1);
		}		
	}
	T front() const{
	}
	bool isEmpty() const{
	}
	~Queue(){
	}	
};