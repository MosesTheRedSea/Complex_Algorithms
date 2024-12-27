#ifndef _arraylist_h
#define _arraylist_h

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

template <typename T> 

class ArrayList {

	public:

		// Constructors
		ArrayList();

		ArrayList(int initialSize);

		ArrayList(const ArrayList<T> & list);

		ArrayList(const ArrayList<T> &list, int theCapacity);

		// Methods
		void addFront(const T & value);

		void addBack(const T & value);

		void add(const T value, int index);

		void remove(int index);

		void removeFront();

		void removeBack();

		void clear();

		T get(int index);

		void insert(int index, T value);
			
		bool isEmpty();
		
		void set(int index, T value);
		
		int size();
		
		std::string toString();
		
	private:

		// Array of Elements
		T* myElements;
		
		// length of array  
		int myCapacity; 

		// number of elements added 
		int mySize; 
		
		void checkIndex(int index, int min, int max); 
		void checkResize();                  
};
#endif