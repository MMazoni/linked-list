#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct Node{
	int info; // the data in each Node of the list
	Node *next; // Node will pointer through the list, starting with header
};

struct List{
	Node *header; // the first of the list

	List(){
		header = NULL; // the list starts with the header pointing to NULL
	}
	bool emptyList(){
		return header == NULL;// true or false if the list is empty
	}
	void setValueLast(int x){
		Node *aux = new Node(); // alloc some memory to put a Node
		aux->info = x; // the parameter value is assigned in the info pointer of the Node
		if(header == NULL){ 
			aux->next = NULL; //if the list is empty: the Node points to NULL, and... 
			header = aux; // header now points to aux(that is pointing to Node)
		}
		else{
			Node *aux2 = header; // if the list is not empty: aux2 points to the header
			while(aux2->next != NULL){
				aux2 = aux2->next; // aux2 points to the next Node
			}                 //this loop stop when aux2->next points to NULL
			aux->next = aux2->next;// aux->next points to where aux2->next is pointing(NULL)
			aux2->next = aux; //aux2->next points to the new Node created(aux)
		}
	}
	void setValueBegin(int x){
		Node *aux = new Node(); //alloc some mememory
		aux->info = x; //put the 'x' value in the Node info
		aux->next = header; // aux->next points to where header is pointing (the old header)
		header = aux; // the header now points to aux (the new header)
	}


	void setValueBetween(int x, int n){
		Node *aux = new Node();
		aux->info = x;
		Node *aux2 = header;
		if(n==1){ // if it's the first element, aux2 doesn't need to points through the list
			aux->next = aux2->next;
			aux2->next = aux;
		}
		else{
			for(int i = 1;i < n; i++) //aux2 pointing through the list to where 'n' element is
				aux2 = aux2->next;
			aux->next = aux2->next;
			aux2->next = aux;
		}
	}
	
	int numberElements(){
		if(header == NULL) // if the list is empty, there is no elements
			return 0;
		else{
			Node *aux = header;
			int i = 0;
			while(aux != NULL){ //aux will points through the list and couting the elements
				i++;
				aux = aux->next;
			}
			return i;
		}
	}
				

	void deleteElement(int n){
		Node *temp = header;// temp points to header
		if(n == 1){ // if it is the header, doesn't need to temp points through the list
			header = temp->next; // the header points to the next of temps(or its own next) 
			delete temp; // the Node temp is deleted (the old header)
		}
		else{
			for(int i = 2;i < n; i++)//temp points through the element before 'n'
				temp = temp->next;
			Node *temp2 = temp->next;// temp2 points to the next of temp
			temp->next = temp2->next;// next of temp points to the next of temp2
			delete temp2;// temp2 is deleted
		}
	}

	bool searchValue(int x){
		Node *aux = header;
		while(aux != NULL){
			if(x == aux->info)
				return true;
			aux = aux->next;
		}
		return false;
	}
};

#endif // LINKED_LIST_H_INCLUDED
