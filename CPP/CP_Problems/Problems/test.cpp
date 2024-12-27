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
	// Two Pointer Approach
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
	int postfix = 1;
	for (int j = val2.size()-1; j > -1; --j) {
		val2[j] *= postfix;
		postfix *= values[j];
	}
	cout << " " << endl;
	return val2;
}

// String Times 
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

// Substr(first, index, start, length)
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

int countEvens(std::vector<int> nums) {
	int count = 0;
	for (int val : nums) {
		count++;
	}
	return count;
}

int bigDiff(std::vector<int> nums) {
	int max = 0; // What if first value is 0
	int min = nums[0];
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > max) {
			max = nums[i]; 
		}
	}
	for (int j = 1;  j < nums.size(); ++j) {
		if (nums[j] < min) {
			min =  nums[j];
		}
	}
	return max - min;
}	

int centeredAverage(std::vector<int> nums) {
	int max = 0; // What if first value is 0
	int min = nums[0];
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > max) {
			max = nums[i];
		}
		if (nums[i] < min) {
			min =  nums[i];
		}
	}
	int sum = 0;
	int count = 0;
	int m1 = 0;
	int m2 = 0;
	for (int k = 0; k < nums.size(); ++k) {
		if (nums[k] == max) {
			if (m1 == 0) {
				m1++;
				continue;
			}
		} else if(nums[k] == min) {
			if (m2 == 0)  {
				m2++;
				continue;
			}
		} 
		sum += nums[k];
		count++;
	}
	return sum / count;
}

 
string doubleChar(string n) {
	string ret = "";
	for (int i = 0; i < n.size(); ++i) {
		ret += n[i];
		ret += n[i];
	}
	return ret;
}

int main() {
	
	// cout << doubleChar("The") << endl;

	/*

		vector<int> graph = {1,8,6,2,5,4,8,3,7};
		
		cout << maxArea(graph) << endl;
		
		vector<int> graph2 = {2,3,4,5,18,17,6};

		// cout << maxArea(graph2) << endl;

		vector<int> nums = {1, 2, 3, 4, 100};

		vector<int> nums1 = {1, 1, 5, 5, 10, 8, 7};

		vector<int> nums2 = {-10, -4, -2, -4, -2, 0};

	*/
	
	// cout << centeredAverage(nums) << endl;

	// cout << centeredAverage(nums1) << endl;

	// cout << centeredAverage(nums2) << endl;
	
	return 0;
	
}	