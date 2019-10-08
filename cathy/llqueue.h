template <class T>
class Queue{
	DList<T> theQueue_;
	int size_;
public:
	Queue(){
		size_=0;
	}
	void enqueue(const T& data){
		theQueue_.push_back(data);
		//v2: theQueue_.push_front();
		size_++;
	}
	void dequeue(){
		if(!isEmpty()){
			theQueue_.pop_front();
			//v2: theStack_.pop_back();
			size_--;
		}		
	}
	const T& front() const{
		return theStack_.front_->data_;
	}
	bool isEmpty() const{
		return size_==0;		
	}
	~Queue(){
	}	
};