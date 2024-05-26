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

// Helper functions
void printVector(vector<int> num) {
	for (int i = 0; i < num.size(); ++i) {
		cout << num[i] << " ";
	}
}

/*
	Return the maximum profit you can achieve from this transaction. 
	If you cannot achieve any profit, return 0.
*/
int maxProfit(vector<int> prices) {
	int lp = 0;
	int maxProfit = 0;
	int rp = 1;
	while (rp < prices.size()) {
		if (prices[lp] < prices[rp]) {
			int profit = prices[rp] - prices[lp];
			maxProfit = std::max(maxProfit, profit);
		} else {
			lp = rp;
		}
		rp += 1;
	}
	return maxProfit;
}

/*
	Calculate the value of every other item in the list except itself
	Example  nums = [1,2,3,4] -> [24,12,8,6]
*/
// Old Solution - productExceptSelf - Java
vector<int> productExceptSelf(vector<int> values) {
	vector<int> val2(values.size());
	int count = 0;
	while (count < values.size()) {
		int cur = values[count];
		int val = 1;
		for (int i = 0; i < values.size(); ++i) {
			if (i != count) {
				val *= values[i];
			}
		}
		val2[count] = val;
		count++;
	}	
	return val2;
}

// New Solution - productExceptSelf - C++
vector<int> productExceptSelf2(vector<int> values) {
	vector<int> val2(values.size(), 1);
	int prefix = 1;
	for (int i = 0; i <values.size(); ++i) {
		val2[i] = prefix;
		prefix *= values[i];
	}
	printVector(val2);
	cout << " " << endl;
	int postfix = 1;
	for (int j = val2.size()-1; j > -1; --j) {
		val2[j] *= postfix;
		postfix *= values[j];
	}
	printVector(val2);
	cout << " " << endl;
	return val2;
}

// stringTImes
string stringTimes(string str, int n) {
	string final = "";
	for (int i = 0; i < n; ++i) {
		final.append(str);
	}
	return final;
}

string frontTimes(string str, int n) {
	string final = str.substr(0,n+1);
	string output = "";
	for (int i = 0; i < n; ++i) {
		output.append(final);
	}
	return output;
}

// substr(first index start, length);
int countXX(string str) {
	int count = 0;
	for (int i = 0; i < str.length()-1; ++i) {
		if (str.substr(i, 2) == "xx") {
			count++;
		}
	}
	return count;
}

bool doubleX(string str) {
	return str.find("x") != -1 && str.substr(str.find("x")+1, 1) == "x";
}

string stringBits(string str) {
	string final = "";
	for (int i = 0; i < str.length(); i+=2) {
		final += str[i];
	}
	return final;
}

string stringSplosion(string str) {
	string final = "";
	for (int i = 0; i < str.length(); ++i) {
		final += str.substr(0, i+1);
	}
	return final;
}

int last2(string str) {
	/*
		public int last2(String str) {
		  // Screen out too-short string case.
		  if (str.length() < 2) return 0;
		  
		  String end = str.substring(str.length()-2);
		  // Note: substring() with 1 value goes through the end of the string
		  int count = 0;
		  
		  // Check each substring length 2 starting at i
		  for (int i=0; i<str.length()-2; i++) {
		    String sub = str.substring(i, i+2);
		    if (sub.equals(end)) {  // Use .equals() with strings
		      count++;
		    }
		  }

		  return count;
		}
	*/
	return 0;
}

void printSet(unordered_set<int> nums) {
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		cout << " " << *it;
	}
	std::cout << std::endl;
}

// Max Area - Solution 1 - O(n)
int maxArea(std::vector<int> graph) {
    int water = 0;
    int lp = 0;
    int rp = graph.size()-1;

    while (rp < graph.size()) {
        if (graph[lp] >= graph[rp] || graph[rp] >= graph[lp]) {
        	// These calculations are correct
            int diff = (graph[lp] - graph[rp]);
            int height = diff < 0 ? graph[rp] + diff : graph[lp] - diff;
            int width = rp - lp;
            water = std::max(height*width, water);
        } 
        if (graph[lp] < graph[rp]) {
        	lp++;
        } else {
        	rp--;
        }
   }
   return water;
}

// Max Area - Solution 2 - O(n^2)
int maxArea2(std::vector<int> graph) {
	int water = 0;
	for (int lp = 0; lp < graph.size(); ++lp) {
		for (int rp = 0; rp < graph.size(); ++rp) {
			int diff = (graph[lp] - graph[rp]);
            int height = diff < 0 ? graph[rp] + diff : graph[lp] - diff;
            int width = rp - lp;
            int area = height * width;
			water = std::max(area, water);
		}
	}
	return water;
}

int main() {
	vector<int> graph = {1,8,6,2,5,4,8,3,7};
	cout << maxArea(graph) << endl;

	vector<int> graph2 = {2,3,4,5,18,17,6};
	cout << maxArea(graph2) << endl;
	return 0;
}	