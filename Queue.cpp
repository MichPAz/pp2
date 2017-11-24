#include <iostream>
#include <limits>

//#######################################################################
//######################### CLASS NODE QUEUE ############################
//#######################################################################
template <class T>
class NodeQueue
{
private:
	T item;
	NodeQueue<T>* next;
public:
	NodeQueue();

	T getItem();
	NodeQueue<T>* getNext();

	void setItem(T);
	void setNext(NodeQueue<T>*);
};

//#######################################################################
//####################### FUNCTIONS NODE QUEUE ##########################
//#######################################################################
template <class T>
NodeQueue<T>::NodeQueue(){
	next = NULL;
}

template <class T>
T NodeQueue<T>::getItem(){
	return item;
}

template <class T>
NodeQueue<T>* NodeQueue<T>::getNext(){
	return next;
}

template <class T>
void NodeQueue<T>::setItem(T item){
	this->item = item;
}

template <class T>
void NodeQueue<T>::setNext(NodeQueue<T>* next){
	this->next = next;
}


//#######################################################################
//########################### CLASS QUEUE ###############################
//#######################################################################
template <class T>
class Queue
{
private:
	NodeQueue<T>* back;
	NodeQueue<T>* front;
public:
	Queue();

	void push(T);
	T pop();
	bool empty();

	void showQueue();
};

//#######################################################################
//######################### FUNCTIONS QUEUE #############################
//#######################################################################
template <class T>
Queue<T>::Queue(){
	front = new NodeQueue<T>;
	front->setNext(NULL);
	back = front;
}

template <class T>
void Queue<T>::push(T item){
	back->setNext(new NodeQueue<T>);
	back = back->getNext();

	back->setItem(item);
	back->setNext(NULL);
}

template <class T>
T Queue<T>::pop(){
	T item;
	if(empty())
		return std::numeric_limits<int>::max();
	else{
		NodeQueue<T>* node = front;
		front = front->getNext();

		item = front->getItem();
		delete node;
	}
	return item;
}

template <class T>
bool Queue<T>::empty(){
	return back == front;
}

template <class T>
void Queue<T>::showQueue(){
	NodeQueue<T>* node = front;
	if(empty())
		std::cout << "Lista Vazia!" << std::endl;
	else{
		while(node->getNext() != NULL){
			node = node->getNext();
			std::cout << node->getItem() << "\t";
		}
		std::cout << std::endl;
	}
}

//#######################################################################
//########################### TESTE E MAIN ##############################
//#######################################################################
void populate(Queue<int> *q){
	q->push(2);
	q->push(5);
	q->push(3);
	q->push(1);
	q->push(4);
}

int testePop(Queue<int> *q){
	int x = q->pop();
	return x;
}

int main(int argc, char** argv){
	Queue<int> q;

	std::cout << "####################################" << std::endl;
	std::cout << "######## POPULATE AND SHOW #########" << std::endl;
	std::cout << "####################################" << std::endl;
	populate(&q);
	q.showQueue();

	std::cout << "####################################" << std::endl;
	std::cout << "############ TESTE POP #############" << std::endl;
	std::cout << "####################################" << std::endl;
	int result = testePop(&q);
	std::cout << "Result1 = " << result << std::endl;
	q.showQueue();

	return 0;
}
