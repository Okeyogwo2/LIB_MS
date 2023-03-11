#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_
#include <iostream>

/**
 * Generic class CircularLLN is the node of the queue class
 * @tparam Type
 */
template<class Type>
class CircularLLN {
public:
	/**
	 * constructor function
	 * @param data
	 */
    CircularLLN(Type * data) {
        this->data = data;
        this->next = 0;
    }
    /**
     * function to set data and next pointer of the node
     * @param data: data of the node with generic type
     * @param next: pointer to the next node
     */
    void setNode(Type * data, CircularLLN* next ) {
        this->data = data;
        this->next = next;
    }
    /**
     * data of the node
     */
    Type* data;
    /**
     * pointer to the next node
     */
    CircularLLN* next;
};
/**
 * Generic class circularLL is the queue data structure which is implemented
 * based on the linked list datastructure
 * @tparam Type
 */
template<class Type>
class circularLL {
private:
	/**
	 * pointer to the first node of the queue
	 */
	CircularLLN<Type> * front;
	/**
	 * pointer to the last node of the queue
	 */
	CircularLLN<Type> * rear;
	/**
	 * size of the queue
	 */
    size_t size;

public:
    /**
	 * constructor function
	 */
	circularLL(){
		front = rear = 0;
		size = 0;
	}
	/**
	 * destructore function deletes the nodes in the queue and destroy the
	 * queuee
	 */
	virtual ~circularLL(){
	    CircularLLN<Type> *temp;

		while(front!=0)
		{
			temp=front;
			front=front->next;
			delete temp;
			size--;
		}
		rear=0;
		size=0;
	}
	/**
	 * function adds a new node to rear of the queue
	 * @param value: data of the node
	 */
	void add(Type * value) {

		// Create a new LL node
		CircularLLN<Type>* temp = new CircularLLN<Type>(value);

		if (rear == 0) { 	// If queue is empty,
			front = rear = temp;
			size++;
		}
		else{	// Add the new node at the end of queue
			rear->next = temp;
			rear = temp;
			size++;
		}
	}
	/**
	 * function removes and returns the data of the first node of the queue
	 * @return pointer to the data of the first node of the queue
	 */
	Type * remove() {
		Type * returnNode = 0;
		// If queue is empty, return false.
		if (front == 0) {
	        std::cout<<"Queue is empty.";
		}
		else{
			CircularLLN<Type>* temp = front;
			front = front->next;
			//queue gets empty
			if (front == 0)
				rear = 0;
			returnNode = temp->data;
			size--;
			delete (temp);
			temp = 0;
		}
		return returnNode;
	}
	/**
	 * function removes and returns the data of the node at location index of the queue
	 * @return pointer to the data of the node which is located at location index of the queue
	 */
	Type* removeAtIndex(int index)
	{
		Type * returnNode = 0;
		CircularLLN<Type>* temp = front;
		CircularLLN<Type>* prev = front;


	    int count = 0;
	    while (temp != 0)
	    {
	        if (count == index){
	        	if(temp!=front)
	        		prev->next = temp->next;
	        	else{
	        		front=rear = 0;
	        	}
				returnNode = temp->data;
				size--;
				delete (temp);
				temp = 0;
				return returnNode;
	        }
	        count++;
	    	prev=temp;
	        temp = temp->next;
	    }
	    std::cout<<"Node at index:"<<index<<" does not exist\n";

	    return 0;
	}
	/**
	 * function returns the node at location index of the queue
	 * @return pointer to the node which is located at location index of the queue
	 */
	CircularLLN<Type>* atIndex(int index)
	{

		CircularLLN<Type>* temp = front;


	    int count = 0;
	    while (temp != 0)
	    {
	        if (count == index)
	            return(temp);
	        count++;
	        temp = temp->next;
	    }
	    std::cout<<"Node at index:"<<index<<" does not exist\n";

	    return 0;
	}
	/**
	 * function overloads operator <<
	 * @param out: output stream
	 * @param b: queue object
	 * @return
	 */
	friend std::ostream& operator<<(std::ostream &out,  const circularLL &b) {

	    if(b.front==0){
	    	out<<"Queue is empty.";
	    }
	    else{
	    	CircularLLN<Type> *temp=b.front;
	    	while(temp){
				out<< *temp->data <<" \n";
				temp = temp->next;
			}
	    }
//	    os<<std::endl;
	    return out;
	}
//	CircularLLN<Type>& operator[](std::size_t idx) {
//		return *atIndex(idx);
//	}
	/**
	 * function return size of the queue
	 * @return size of the queue
	 */
	size_t getSize() const {
		return size;
	}
	/**
	 * function returns list of the nodes
	 * @return list of the nodes
	 */
	Type** nodeList(){
		Type ** list = new  Type*[size];
		int i=0;
		CircularLLN<Type> *temp=front;
		while(temp){
			list[i++] = temp->data ;
			temp = temp->next;
		}
		return list;
	}
	/**
	 * functions finds the index of the node with specififc data
	 * @param data: data of the node
	 * @return: index of the node
	 */
	int find(Type data){
		int i=-1;
		if(front){
			i=0;
			CircularLLN<Type> *temp=front;
			while(temp && *(temp->data)!=data){
				temp = temp->next;
				i++;
			}
			if(temp==NULL){
				i = -1;
			}
			else if(*temp->data!=data){
				i = -1;
			}
		}
		return i;
	}
};


#endif /* CIRCULARLINKEDLIST_H_ */
