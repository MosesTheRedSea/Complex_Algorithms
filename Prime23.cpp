#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <array>
using namespace std; //standard namespace


/*
	When to use a namespace

	1. common functionality
	2. group from a company / project
	3. Categories of things change which one you want to use
	depending on the namespace (classifying categories)
*/
namespace utilz {
	double multiply(double num1, double num2) {
		double product = num1 * num2;
		cout << product << endl;
		return product;
	}
}



// Global Variables
#define user_name "Moses Adewolu";
const int age = 19;
static int count = 10;
extern double gpa;
int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

extern void print_array(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] << endl;
	}
}

extern void print_vector(vector<int> data) {
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i] << endl;
	}
}

// STL Array
void print_array2(std::array<int, 20> &data, int size) {
	for (int i = 0; i < size; ++i) {
		std:cout << data[i] << endl;
	}
}

// "Used for Small Data Types"
struct Book { 

	string title;
	string author;
	string subject;
	int book_id;
	vector<int> ratings;
	int len = sizeof(ratings) / sizeof(ratings[0]);

	void printBookName() {
		cout << title << endl;
	}

	void addBookRating(int rate) {
		ratings.push_back(rate);
	}

	void printBookRatings() {
		for (int i = 0; i < len; ++i) {
			cout << ratings[i] << endl;
		}
	}
};



/*
	Arrays, ArrayLists,
	Stacks, Queues, Deques, Priority Queues
	Various Trees: Binary, Binary Search, AVL, Splay, Heaps, 2-4 Trees, etc…
	Hash Maps/Tables; External Chaining and Probing
	Graphs and their algorithms
	Become familiar with common algorithms on these data structures
	Sorting Algorithms: Bubble, Insertion, Selection, Cocktail Shaker, Merge, Quick, Radix etc...
	Pattern Matching Algorithms: Brute force, Boyer-Moore, KMP, Rabin-Karp
	Graph Algorithms: Dijkstra’s Shortest Path and multiple MSTs
	Dynamic Programming Algorithms
	
*/



void linearSearch() {

}

void selectionSort() {

}

void bubbleSort() {

}

void insertionSort() {
}

void mergeSort() {
}

int main() {

	enum class Season {summer, spring, fall, winter};
	Season now = Season::spring;
	int random_nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int len = sizeof(random_nums) / sizeof(random_nums[0]);

	// Vectors
	// Templatized Array
	// Dynamic Programming	

	vector<int> num_Values; // know's it's size
	Book book1;
	book1.title = "Percy Jackson and the Lighting Thief";
	book1.printBookName();

	string name1 = "123";

	int len1 = name1.length(); 
	int n = len1;
	string holder = "";
	
	/*
	while(n--) {
		holder.append(name1[n]);
	}
	*/

	cout << holder << endl;
	/*
		
		//Array 
			static
			must pass in size

		// Vector
			dynamic
			for (int i = 0l )

		// STL Array
			static
			size() assing to other vars

	*/

	// STL Arrays
	std::vector<int> data = {1, 2, 3};
	//print_vector(data);

	//it has a size of 20
	std::array<int, 20> data2 = {5, 6, 7}; 

	//print_array2(data2, 3);

	register int count = 10;

	utilz::multiply(5.0, 2.0);

}