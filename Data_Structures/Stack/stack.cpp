#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>

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


#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX];
    int size;
    Stack() { top = -1; } // Creates an empty stack where the top parameter is -1
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void clear();
    bool contains(int value);
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {         
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        size++;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {  
        cout << "Stack Underflow";
        return 0;
    }   
    else {
        int x = a[top--];
        size--;
        return x;
    }
}

int Stack::peek()
{   
    if (top < 0) {  
        cout << "Stack is Empty";   
        return 0;   
    }   
    else {
        int x = a[top];
        return x;
    }
}

int size() {
    return size;    
}

bool Stack::isEmpty()
{
    return (top < 0);   
}

bool Stack::isFull() 
{
    return size == MAX; 
}

int main()
{   
    return 0;
}