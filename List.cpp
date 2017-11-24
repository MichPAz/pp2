#include <iostream>

//#######################################################################
//######################### CLASS NODE LIST #############################
//#######################################################################
template <typename T>
class NodeList{
private:
	T item;
	NodeList<T>* next;
	NodeList<T>* previous;
	int id;

public:
	NodeList();

	T getItem();
	NodeList<T>* getNext();
	NodeList<T>* getPrevious();
	int getId();

	void setItem(T);
	void setNext(NodeList<T>*);
	void setPrevious(NodeList<T>*);
	void setId(int);
};


//#######################################################################
//##################### FUNCTIONS NODE LIST #############################
//#######################################################################
template <typename T>
NodeList<T>::NodeList(){
	next = NULL;
}

template <typename T>
T NodeList<T>::getItem(){
	return item;
}

template <typename T>
NodeList<T>* NodeList<T>::getNext(){
	return next;
}

template <typename T>
NodeList<T>* NodeList<T>::getPrevious(){
	return previous;
}

template <typename T>
int NodeList<T>::getId(){
	return id;
}

template <typename T>
void NodeList<T>::setItem(T item){
	this->item = item;
}

template <typename T>
void NodeList<T>::setNext(NodeList* next){
	this->next = next;
}

template <typename T>
void NodeList<T>::setPrevious(NodeList* previous){
	this->previous = previous;
}

template <typename T>
void NodeList<T>::setId(int id){
	this->id = id;
}


//#######################################################################
//########################### CLASS LIST ################################
//#######################################################################
template <typename T>
class List{
private:
	int size;
	NodeList<T>* first;
	NodeList<T>* last;

public:
	List();

	void insert(T);
	//void remove(T);
	void showList();
	void destroy();

	NodeList<T>* getAtPosition(int);

	int getSize();
	NodeList<T>* getFirst();
	NodeList<T>* getLast();

	void setSize(int);
	void setFirst(NodeList<T>*);
	void setLast(NodeList<T>*);
};

//#######################################################################
//####################### FUNCTIONS CLASS LIST ##########################
//#######################################################################
template <typename T>
List<T>::List(){
	first = new NodeList<T>();
	first->setPrevious(NULL);

	last = new NodeList<T>();
	last->setNext(NULL);
	last->setPrevious(first);
	first->setNext(last);

	size = 0;

	last->setId(size);
}

template <typename T>
void List<T>::insert(T item){
	last->setItem(item);
	last->setId(size);

	last->setNext(new NodeList<T>);
	last->getNext()->setPrevious(last);
	setLast(last->getNext());
	last->setNext(NULL);

	size++;

	last->setId(size);
}

template <typename T>
void List<T>::showList(){
	if(size == 0)
		std::cout << "LISTA VAZIA!" << std::endl;
	else{
		NodeList<T>* node = first->getNext();

		while(node->getNext() != NULL){
			if(node->getNext() != NULL)
				std::cout << node->getItem() << "\t";
			node = node->getNext();
		}
		std::cout << std::endl;
	}
}

template <typename T>
void List<T>::destroy(){
	NodeList<T>* node = first;

	while(node != NULL){
		NodeList<T>* n = node;
		node = node->getNext();
		delete n;
	}

	first = new NodeList<T>();
	first->getNext() = NULL;
	last = first;
}

template <typename T>
NodeList<T>* List<T>::getAtPosition(int id){
	NodeList<T>* node = first->getNext();

	while((node != last) && (node->getId() != id))
			node = node->getNext();
	return node;
}

template <typename T>
int List<T>::getSize(){
	return size;
}

template <typename T>
NodeList<T>* List<T>::getFirst(){
	return first;
}

template <typename T>
NodeList<T>* List<T>::getLast(){
	return last;
}

template <typename T>
void List<T>::setSize(int size){
	this->size = size;
}

template <typename T>
void List<T>::setFirst(NodeList<T>* first){
	this->first = first;
}

template <typename T>
void List<T>::setLast(NodeList<T>* last){
	this->last = last;
}

//#######################################################################
//########################### TESTE E MAIN ##############################
//#######################################################################
void populate(List<int> *l){
	l->insert(2);
	l->insert(5);
	l->insert(3);
	l->insert(1);
	l->insert(4);
}

void testeAt(List<int> *l){
	int result = l->getAtPosition(3)->getItem();
	std::cout << "Pos = 3 :: " << result << std::endl;

	result = l->getAtPosition(0)->getItem();
	std::cout << "Pos = 0 :: " << result << std::endl;

	result = l->getAtPosition(4)->getItem();
	std::cout << "Pos = 4 :: " << result << std::endl;
}

int main(int argc, char** argv){
	List<int> l;

	std::cout << "####################################" << std::endl;
	std::cout << "######## POPULATE AND SHOW #########" << std::endl;
	std::cout << "####################################" << std::endl;
	populate(&l);
	l.showList();

	std::cout << "####################################" << std::endl;
	std::cout << "########### AT POSITION ############" << std::endl;
	std::cout << "####################################" << std::endl;
	testeAt(&l);

	return 0;
}
