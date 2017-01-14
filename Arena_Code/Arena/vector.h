#ifndef _VECTOR_
#define _VECTOR_
#include <stdio.h>
#include <assert.h>
template<class TYPE>
class vector{
private:

	unsigned int capacity;
	unsigned int elements;
public:
	TYPE* buffer;


	//copy constructor
	vector(const vector& copy){
		elements = copy.elements;
		buffer = new TYPE[elements];
		for (unsigned int i = 0; i <= elements - 1; i++){
			buffer[i] = copy.buffer[i];

		}
	}

	//standar constructor
	vector(){
		capacity = 6;
		elements = 0;
		buffer = new TYPE[capacity];
	}


	//push back
	void push_back(const TYPE& element){
		if (elements == capacity){
			capacity *= 2;
			TYPE *copy = new TYPE[capacity];
			for (unsigned int k = 0; k < elements; k++){
				copy[k] = buffer[k];
			}
			//delete[] buffer;
			buffer = copy;
		}
		buffer[elements] = element;
		elements++;
	}

	//push front
	void push_front(const TYPE& element){
		if (elements + 1 == capacity){
			capacity = capacity * 2;;
			TYPE *copy = new TYPE[capacity];
			for (unsigned int k = 0; k < elements; k++){
				copy[k] = buffer[k];
			}
			delete[] buffer;
			buffer = copy;
		}
		for (int k = elements; k > 0; k--){
			buffer[k + 1] = buffer[k];
		}
		buffer[0] = element;
		elements++;
	}

	//empty
	bool empty(){
		return elements == 0;
	}

	//clean
	void clean(){
		elements = 0;
	}

	//size
	unsigned int get_size(){
		return elements;
	}

	//capacity
	unsigned int get_capacity(){
		return capacity;
	}

	//pop_back
	void pop_back(){
		elements--;
	}

};
#endif