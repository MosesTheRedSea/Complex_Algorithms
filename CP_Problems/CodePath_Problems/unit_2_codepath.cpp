#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <ctime>

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

/*
    
    Understand
    	Ask clarifying questions and use examples to understand what the interviewer wants out of this problem
    	Choose a “happy path” test input, different than the one provided, and a few edge case inputs. 
    	Verify that you and the interviewer are aligned on the expected inputs and outputs.
    
    Match
    	See if this problem matches a problem category (e.g. Strings/Arrays) and strategies or patterns within the category
    
    Plan
    	Sketch visualizations and write pseudocode
    	Walk through a high level implementation with an existing diagram
    
    Implement
    	Implement the solution (make sure to know what level of detail the interviewer wants)
    
    Review
    	Re-check that your algorithm solves the problem by running through important examples
    	Go through it as if you are debugging it, assuming there is a bug
    
    Evaluate
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

// Problem 1: Remove Duplicates from Sorted List

void removeDuplicates(ListNode*& head) {
    if (head == nullptr) {
        return;
    }
    ListNode* curr = head;
    while (curr->next != nullptr) {
        if (curr->value == curr->next->value) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

// Problem 2 : Linked List Cycle

bool hasCycle(ListNode*& head) {
    ListNode* sp = head;
    ListNode* fp = head;
    while (fp != nullptr && fp->next != nullptr) {
        sp = sp->next;
        fp = fp->next->next;
        if (sp == fp) {
            return true;
        }
    }
    return false;
}

// Problem 3 : Reverse Linked List

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


// (Bonus) Problem 4 : Linked List Cycle II

// (Bonus) Problem 5 : Remove Linked List Elements

// Reverse Linked List Section
ListNode* reverseSection(ListNode*& head, int left, int right) {
    ListNode* start = head;
    ListNode* end = head

    while (start.next != nullptr && start.next.value != left) {

        

    }

    while (end.next != nullptr && end.value != right) {

        

    }   
}


int main() {

    ListNode* h = nullptr;

    ListNode::add(h, 5);
    ListNode::add(h, 1);
    ListNode::add(h, 2);

    ListNode::add(h, 3);
    ListNode::add(h, 4);
    ListNode::add(h, 5);

    h = reverseSection(h, 2, 4);

}