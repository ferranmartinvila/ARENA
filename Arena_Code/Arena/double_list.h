#ifndef _DOUBLE_LIST_
#define _DOUBLE_LIST_
//VECTOR OF NODES
template<class type>
class list_double{
public:

	//DATA
	struct node{
		type data;

		node* next = nullptr;
		node* prev = nullptr;
		//constructor
		node(type data) :data(data) {}
	};
	node* first_element = nullptr;


	//OPERATORS
	type operator [](int k){
		if (k == 0)return first_element->data;
		else{
			node* temp = first_element;
			while (k){
				if (temp != nullptr)temp = temp->next;
				k--;
			}
			if (temp != nullptr)return temp->data;
			else return nullptr;
		}
	}


	//FUNCTIONS
	//empty function
	bool empty(){
		return first_element == nullptr;

	}
	//get size 
	unsigned int get_size(){
		node* temp = first_element;
		unsigned int size = 0;
		while (temp){
			size++;
			temp = temp->next;
		}
		return size;
	}
	//last node 
	node* last_element(){
		node* temp = first_element;
		if (first_element){
			while (temp->next != nullptr){
				temp = temp->next;
			}
		}
		return temp;
	}
	//push.back 
	void push_back(const type& element_added){
		node*added = new node(element_added);
		if (empty()){
			first_element = added;
		}
		else{
			node*last = last_element();
			last->next = added;
			added->prev = last;
		}
	}
	//push.front
	void push_front(const type& element_added){
		node*added = new node(element_added);
		if (!empty()){
			first_element->prev = added;
			added->next = first_element;

		}
		first_element = added;
	}
	//pop.back 
	bool pop_back(){
		if (empty() == false && get_size()>1){
			node*pre_last = last_element()->prev;
			delete last_element();
			pre_last->next = nullptr;
			return true;

		}
		else if (!empty()){
			node*last = first_element;
			first_element = nullptr;
			delete first_element;
			return true;
		}
		else return false;
	}
	//pop.front
	bool pop_front(){
		if (empty() == false){
			node*temp = first_element;
			if (get_size() > 1){
				first_element = first_element->next;
				first_element->prev = nullptr;
				temp->next = nullptr;
				return true;
			}
			else{
				first_element = nullptr;
			}
			delete temp;
			return true;
		}
		else return false;
	}
	//insert position
	bool insert(unsigned int position, const type& to_add){
		if (position == 0){
			push_front(to_add);
			return true;
		}
		else if (position == get_size()){
			push_back(to_add);
			return true;
		}
		else if (position < get_size() && position > 0){
			node* temp = first_element;
			node* added = new node(to_add);
			while (position){
				temp = temp->next;
				position--;
			}
			added->next = temp;
			added->prev = temp->prev;
			temp->prev->next = added;
			temp->prev = added;
			return true;
		}
		else return false;
	}
	//insert node
	bool insert_node(unsigned int position, node& added){
		if (added.data){
			node*to_add = new node(added.data);
			if (position == 0){
				push_front(to_add->data);
				return true;
			}
			else if (position == get_size()){
				push_back(to_add->data);
				return true;
			}
			else if (position < get_size() && position > 0){
				node* temp = first_element;
				while (position){
					temp = temp->next;
					position--;
				}
				to_add->next = temp;
				to_add->prev = temp->prev;
				temp->prev->next = to_add;
				temp->prev = to_add;
				return true;
			}
		}
		else return false;
	}
	//ERASES
	//erase position
	bool erase(unsigned int position){
		if (position == get_size() - 1){
			pop_back();
			return true;
		}
		else if (position == 0){
			pop_front();
			return true;
		}
		else if (position < get_size() && position >= 0 && !empty()){
			node*temp = first_element;
			while (position){
				temp = temp->next;
				position--;
			}

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			temp = nullptr;
			return true;
		}
		else return false;
	}

	//erase node
	node* erase_node(node* to_delete){
		node*deleted = new node(to_delete->data);
		if (to_delete == last_element()){
			pop_back();
		}
		else if (to_delete == first_element){
			pop_front();
		}
		else{

			to_delete->prev->next = to_delete->next;
			to_delete->next->prev = to_delete->prev;
			delete to_delete;
			to_delete = nullptr;
		}
		return deleted;
	}
	//erase entity
	bool erase_data(const type& to_delete){
		node* temp = first_element;
		while (temp){
			if (temp->data == to_delete || first_element->next == nullptr)break; 
			temp = temp->next;
		}
		if (temp == last_element()){
			pop_back();
		}
		else if (temp == first_element){
			pop_front();
		}
		else{

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			temp = nullptr;
		}
		return true;
	}
	//erase all the data of a list
	void erase_all(){
		node* temp = last_element();
		//Check if the list was cleared before
		if (temp != nullptr){
			//Erase all the list data
			node* pre_temp = temp->prev;
			while (temp){
				this->erase_node(temp);
				temp = pre_temp;
				if (pre_temp != nullptr) pre_temp = pre_temp->prev;
			}
		}
	}
	//pass entity(entity to erase , list destination , list from)
	void pass_entity(const type& A , list_double<type>& Other_list, list_double<type>& A_list){
		if (this != nullptr){
			A_list.erase_data(A);
			Other_list.push_back(A);
		}
	}
	//swap entities(entity A(from this list),entity B, B_list)
	void swap_entities(const type& A, const type& B, list_double<type>& B_list){
		if (this != nullptr){
			this->erase_data(A);
			B_list->push_back(A);
			if (B != nullptr){
				B_list->erase_data(B);
				this->push_back(B);
			}
		}
	}
	//find data 
	bool find_data(const type& data){
		node* temp = first_element;
		while (temp){
			if (temp->data == data)return true;
			temp = temp->next;
		}
		return false;
	}

};
#endif