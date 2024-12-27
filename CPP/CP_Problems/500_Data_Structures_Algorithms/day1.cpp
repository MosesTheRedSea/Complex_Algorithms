#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>
#include<numeric>

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

// Helper Methods 
template <typename T>	
void printVector(const std::vector<T>& vec) {
    std::cout << " Vector elements :" << std::endl;
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << endl;
}

// Daily Solve 25 Practice Coding Problems
// #1 - Find a pair with the given sum in an array - O(n) Runtime - Solved
vector<int> twoSumPair(vector<int> numbers, int target) {
	map<int, int> m;
	for (int i = 0; i < numbers.size(); ++i) {
		int complement = target - numbers[i];
		map<int, int>::iterator it;
		it = m.find(complement);
		if (it != m.end()) { // it's in the map
			return vector<int>{it->first, numbers[i]};
		}
		m.insert(pair<int, int>(numbers[i], numbers[i]));
	}
	return vector<int>{};
}

// #2 - Check if a subarray with 0 sum exists or not - Solved	
bool zeroSubArray(vector<int> numbers) {
	for (int i = 0; i < numbers.size(); ++i) {
		vector<int> items;
		for (int j = 0; j < numbers.size(); ++j) {
			items.push_back(numbers[j]);
			if (accumulate(items.begin(), items.end(), 0) == 0) {
				printVector(items);
				return true;
			}
		}
	}
	return false; 
}

// #3 - Given an integer array, print all subarrays with zero-sum - Solved	
bool allZeroSubArray(vector<int> numbers) {
	for (int i = 0; i < numbers.size(); ++i) {
		vector<int> items = {};	
		for (int j = i; j < numbers.size(); ++j) {
			items.push_back(numbers[j]);
			if (accumulate(items.begin(), items.end(), 0) == 0) {
				printVector(items);
				continue;
			}
		}
	}
	return false;
}

// #4 - 
void linearSort(vector<int> nums) {
 	int n = nums.size();
 	int z = 0;
 	for (int zero : nums) {
 		if (zero == 0) {
 			z++;
 		}
 	}
 	int o = 0;
 	for (int ones : nums) {
 		if (ones == 1) {
 			o++;
 		}
 	}
 	vector<int> items(n, 1);	
 	for (int h = 0; h < z; ++h) {	
 		items[h] = 0;	
 	}
 	printVector(items); // Solved
 }

// #5 Find the duplicate element in a limited range array - Looked At Solution
int findDuplicate(vector<int> const&nums) { // -- Linear Runtime O(n)
	int n = nums.size();
	vector<bool> visited(n + 1);
	for (int i: nums) {
		if (visited[i]) {
			return i;
		}
		visited[i] = true;
	}
	return -1;
}

// #6 - Given an integer array, find the largest subarray formed by consecutive integers. - Solved
void largestSubArrayConsecutive(std::vector<int> numbers) {
	// Hashmap to check
	int len = 0;
	vector<int> ret = {};
	for (int i = 0; i < numbers.size(); ++i) {
		map<int, int> track;
		map<int, int>::iterator it;
		vector<int> temp = {};
		for (int j = i; j < numbers.size(); ++j) {
			it = track.find(numbers[j]);
			if (it == track.end()) {
				track.insert(pair<int, int>(numbers[j], numbers[j])); // Insert the key value pair into the map
				temp.push_back(numbers[j]); // Add that value to the vector we are tracking
			} else {
				break;
			}
		}
		if (temp.size() > len) {
			len = temp.size();
			ret = temp;
		}
	}
	printVector(ret);
}

// #7 - Given an integer array, find the maximum length subarray having a given sum - Solved
void maxLengthSubArraySum(vector<int> nums, int target) {
	vector<int> subarray = {};
	for (int i  = 0; i < nums.size(); ++i) {
		vector<int> ret = {};
		for (int j = i; j < nums.size(); ++j) {
			ret.push_back(nums[j]);
			if (accumulate(ret.begin(), ret.end(), 0) == target) {
				if (ret.size() > subarray.size()) {
					subarray = ret;
				}
			}
		}
	}
	printVector(subarray);
}

// #8 - Given a binary array containing 0’s and 1’s, find the largest subarray with equal numbers of 0’s and 1’s - Solved
void largestSubArrayEqual(vector<int> nums) {
	vector<int> arr = {};
	for (int i = 0; i < nums.size(); ++i) {
		vector<int> ret = {};
		int watch = 0;
		for (int j = 0; j < nums.size(); ++j) {
			if (j == 0) {
				watch = nums[j];
				ret.push_back(nums[j]);
				continue;
			}
			if (watch == 0) {
 				if (nums[j] == 1) {
 					watch = 1;
					ret.push_back(nums[j]);
 				}
			} else if (watch == 1) {
				if (nums[j] == 0) {
					watch = 0;
					ret.push_back(nums[j]);
 				}
			}
			if (ret.size() > arr.size()) {
				arr = ret;
			}
		}
	}
	printVector(arr);	
}

// #9 - Sort an array of 0’s, 1’s, and 2’s (Dutch National Flag Problem) - Looked At Solution
void swap(int A[], int i, int j) {
	int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void dutchNationalFlag(int A[], int end) {
	int start = 0, mid = 0;
    int pivot = 1;
    while (mid <= end)
    {
        if (A[mid] < pivot)  
        {	
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] > pivot)   
        {
            swap(A, mid, end);
            --end;
        }
        else {                      
            ++mid;
        }
    }
}

// #10 - In-place merge two sorted arrays
void merge(int X[], int Y[], int m, int n) {
	int l, r = 0;
	int ls = sizeof(X) / sizeof(int);
	int rs = sizeof(Y) / sizeof(int);
	int ret[] = new int[ls + rs];
	While (l < ls && r < rs) {
		if (X[l] <= Y[r]) {
			ret[l + r] = X[l];
			l++;
		} else { 
			ret[l + r] = Y[r];
			r++;
		}
	}
	while (l < ls) {
		ret[r + l] = X[l];
		l++;
	}
	while (r < rs) {
		ret[r + l] = Y[r];
		r++;
	}
}

// #11 -  Merge two arrays by satisfying given constraints
void merge(int X[], int Y[], int m, int n) {


	
	 
}

// #12 - Find the index of 0 to be replaced to get the maximum length sequence of continuous ones
int findIndexofZero(int arr[], int n) {




}

// #13 - Find the maximum product of two integers in an array
void findMaximumProduct(int arr[], int n) {  



}

// #14 - Shuffle an array using Fisher–Yates shuffle algorithm
void rearrangeArray(int arr[], int n) {



}

// #15 - Rearrange an array with alternate high and low elements
void threeWayPartition(int A[], int end) {



}

int main() {

	// allZeroSubArray(vector<int>{3, 4, -7, 3, 1, 3, 1, -4, -2, -2 });

	// linearSort(vector<int>{1, 0, 1, 0, 1, 0, 0, 1});

	// largestSubArrayConsecutive(vector<int> { 2, 0, 2, 1, 4, 3, 1, 0 });

	// maxLengthSubArraySum(vector<int> { 5, 6, -5, 5, 3, 5, 3, -2, 0 }, 8);

	// largestSubArrayEqual(vector<int> {0, 0, 1, 0, 1, 0, 0 });

	return 0;

}