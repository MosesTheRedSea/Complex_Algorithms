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

// #1 Valid Paranthesis - O(n) multiple ways to solve though 
bool validParenthesis(std::string s) {
    if (s == "") {
        return true;
    }
    std::stack<char> stack;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ')') {
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                return false;
            }
        } else if (s[i] == ']') {
            if (!stack.empty() && stack.top() == '[') {
                stack.pop();
            } else {
                return false;
            }
        } else if (s[i] == '}') {
            if (!stack.empty() && stack.top() == '{') {
                stack.pop();
            } else {
                return false;
            }
        } else {
            stack.push(s[i]);
        }
    }
    return stack.empty();
}

// Python Solution
/*
	 def isValid(self, s: str) -> bool:
        st = []
        for param in s:
            # Opening bracket
            if param in "([{":
                if param == "(":
                    st.append("(")
                elif param == "{":
                    st.append("{")
                elif param == "[":
                    st.append("[")
            # Closing bracket
            elif param in ")]}":
                if param == ")":
                    if st and st[-1] == "(":
                        st.pop()
                    else:
                        return False
                elif param == "}":
                    if st and st[-1] == "{":
                        st.pop()
                    else:
                        return False
                elif param == "]":
                    if st and st[-1] == "[":
                        st.pop()
                    else:
                        return False
        return not st
*/

// #2 Kth Largest Element in a Stream
class KthLargest {
	public:
		priority_queue<int> heap;
		int size;
		KthLargest(int value, std::vector<int> nums) {
			size = value;
			for (int num : nums) {
				heap.push(num);
			}
			while(heap.size() > size) {
			 	heap.pop();
			}
		}
		int add(int val) {
			heap.push(val);
			if (heap.size() > size) {
				heap.pop();
			}
			return heap.top();
		}
};

// #3 Number of Recent Calls
class RecentCounter {
	public:
		queue<int> track;
		RecentCounter() {
		}
		int ping(int t) {
			track.push(t);
			while (!track.empty() && track[0] + 3000 < t) {
				track.pop();
			}
			return track.size();
		}
};

// #4 Min Stack
class MinStack {
	public:
		stack<int> mins;
		stack<int> stack;
		int size;
		MinStack() {
			size = 0;
        }
	    void push(int val) {
	        stack.push(val);
	        if (mins.empty() || val < mins.peek()) {
	        	mins.push(val);
	        } else {
	        	mins.push(mins.peek());
	        }
	    }
	    void pop() {
	        stack.pop();
	        mins.pop();
	    }
	    int top() {
	        return stack.peek();
	    }
	    int getMin() {
	        return mins.peek();	 
	    }
};

// #5
class Queue {

	public:
		int size;
		stack<int> input;
		stack<int> output;
		MyQueue() {
        	size = 0;
    	}
	    void push(int x) {
	        input.push(x);
	    }
	    int pop() {
	        if (output.size() > 0) {
	        	return output.pop();
	        } else {
	        	while(input.size() > 0) {
	        		output.push(input.pop());
	        	}
	        	return output.pop();
	        }
	    }
	    int peek() {
	        if (output.size() > 0) {
	        	return output.peek();
	        } else {
	        	while (input.size() > 0) {
	        		output.push(input.pop());
	        	}
	        	return output.peek();
	        }
	    }
	    bool empty() {
	        return input.size() == 0 && output.size() == 0;
	    }
};

// #5 Implement a Queue Using Stacks
int main() {
	cout << validParenthesis("{{[]}}");
	return 0;
}

