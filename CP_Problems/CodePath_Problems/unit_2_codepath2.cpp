#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>

// Built Data Structures
#include <bits/stdc++.h>
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

/*

Understand -
	Ask clarifying questions and use examples to understand what the interviewer wants out of this problem
	Choose a “happy path” test input, different than the one provided, and a few edge case inputs. 
	Verify that you and the interviewer are aligned on the expected inputs and outputs.

Match -
	See if this problem matches a problem category (e.g. Strings/Arrays) and strategies or patterns within the category

Plan -
	Sketch visualizations and write pseudocode
	Walk through a high level implementation with an existing diagram

Implement -
	Implement the solution (make sure to know what level of detail the interviewer wants)

Review -
	Re-check that your algorithm solves the problem by running through important examples
	Go through it as if you are debugging it, assuming there is a bug

Evaluate - 
	Finish by giving space and run-time complexity
	Discuss any pros and cons of the solution

*/
class ListNode {

public:
    int value;

    ListNode* next;

    ListNode() : value(0), next(nullptr) {}

    ListNode(int val) : value(val), next(nullptr) {}

    ListNode(int val, ListNode* next) : value(val), next(next) {}

    static void add(ListNode*& head, int data) {

        if (head == nullptr) {
            head = new ListNode(data);
            return;
        }
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        ListNode* n = new ListNode(data);
        curr->next = n;
        n->next = nullptr;
    }

    static void printLinkedList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* curr = head;
        while (curr->next != nullptr) {
            cout << curr->value << "->";
            curr = curr->next;
        }
        cout << curr->value;
    }
};


// Problem 1: Remove Nth Node from End of List
ListNode* removeNthNode(ListNode*& head, int n) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* temp = head;
	ListNode* p1 = temp;
	ListNode* p2 = temp;
	ListNode* prev_p2 = temp;
	for (int i = 0; i < n; ++i) {
		p1 = p1->next;
	}
	while (p1 != nullptr) {
		p1 = p1->next;
		prev_p2 = p2;
		p2 = p2->next;
	}
	if (prev_p2 != nullptr)
		prev_p2->next = p2->next;
	return temp->next;
}

// Problem 2: Add Two Numbers
ListNode* addToNumbers(ListNode*& l1, ListNode*& l2) {
	// Understand 
	ListNode* tempHead = new ListNode(0); // Dummy Node
	ListNode* currl1 = l1;
	ListNode* currl2 = l2;
	ListNode* temp_Sum = tempHead;
	int carry = 0;
	while (currl1 != nullptr || currl2 != nullptr) {
		int digitSum = carry;

		if (currl1 != nullptr) {
			digitSum += currl1->value;
			currl1 = currl1->next;
		}
		if (currl2 != nullptr) {
			digitSum += currl2->value;
			currl2 = currl2->next;
		}
		carry = digitSum / 10;
		temp_Sum->next = new ListNode(digitSum % 10);
		temp_Sum = temp_Sum->next;
	}
	return tempHead->next;
}

// Problem 3: Palindrome Linked List
ListNode* reverse(ListNode*& head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

bool palindromeLinkedlist(ListNode*& head) {
	if (head == nullptr) {
		return true;
	}
	ListNode* p1 = head;
	ListNode* p2 = head;
	int size = 0;
	while (p2 != nullptr) {
		p2 = p2->next;
		size++;
	}
	if (size == 1) {
		return true;
	}
	int mid =  size / 2;
	p2 = head;
	int c = 0;
	while (c != mid) {
		p2 = p2->next;
		c++;
	}
	p2 = reverse(p2);
	while (p2 != nullptr && p1 != nullptr) {
		if (p2->value != p1->value) {
			return false;
		}
		p2 = p2->next;
		p1 = p1->next;
	}
	return true;
}

	


// Problem 4: Remove Duplicates from Sorted List II


	


// (Bonus) Problem 5: Swap Nodes in Pairs
int main() {

	ListNode* h = nullptr;
    ListNode::add(h, 2);
    ListNode::add(h, 4);
    ListNode::add(h, 3);	

    ListNode::printLinkedList(h);
   	cout << endl;


    ListNode* i = nullptr; // True
    ListNode::add(i, 5);
    ListNode::add(i, 6);
    ListNode::add(i, 4);


    ListNode::printLinkedList(i);
   	cout << endl;

   	h = addToNumbers(h, i);

   	ListNode::printLinkedList(h);
   	cout << endl;





	return 0;
}