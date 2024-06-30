#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>	
#include <array>	
#include <time.h>
#include <time.h>	
#include <time.h>
#include <bits/stdc++.h>
	
// Built Data Structures	
#include <unordered_map>	
#include <map>	
#include <queue>	
#include <stack>	
#include <vector>	
#include <unordered_set>
#include <set> 
using namespace std;

/*
█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀
*/


class Node {
	
public:

	int data;

	Node* next;

	Node() {
		data = 0;
		next = NULL;   
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

	Node(vector<int> data) {  // Create Linked List from Vector
		Node* head = nullptr;

	}
};

class LinkedList {
	Node* head;
public: 
    Linkedlist() { head = NULL;} 
    void insertFront(int data); 
    void intertEnd(int data);
    void insertNode(int data);
    void deleteNode(int data); 
    void deleteFront();
    void deleteBack();
    Node* search(int data);
    Node* search(int pos);
    void printList();
    std::vector<int> to_list();
    int get_length();
    bool is_empty();
    void reverse();
}; 

