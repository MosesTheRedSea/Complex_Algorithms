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

// Returns which letter in the string appears first
std::string appearTwice(string str) { // - O(n^2)
	string s = "";
	for (int i = 0; i < str.size(); ++i) {
		s = str[i];
		int c = 0;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == str[i]) {
				c++;
			}
		}
		if (c > 2) {	
			return s;
		}
	}
}

// appearTwice2 - O(m) + O(n) 
/*
std::string appearTwice2(string str) { 
	map<char, int> m;
	for (int i = 0; i < str.size(); ++i) {
		char *char_array = new char(str[i].size());
		strcpy(char_array, str[i].c_str());
		m[char_array]++;
	}
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second > 2) {
			return i->first;
		}
	}
}
*/

// Contains Duplicates - O(m + n)
bool containsDuplicates(vector<int> numbers) {
	map<int, int> m;
	for (int i = 0; i < numbers.size(); ++i) {
		m[numbers[i]]++;
	}

	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second > 1) {
			return true;
		}
	}
	return false;
}


// Two Sum - O(n^2)
vector<int> twoSum(vector<int> numbers, int target) {
	for (int i = 0; i < numbers.size(); ++i) {
		for (int j = 0; j < numbers.size(); ++j) {
			if (numbers[i] + numbers[j] == target) {
				vector<int> ret {numbers[i], numbers[j]};
				return ret;
			}
		}
	}
}

// Longest Consecutive Sequence - O(n) runtime

/*
int longestConsecutive(vector<int> numbers) {
	set<int> s;
	int maxNum = 0;
	for (int x : v) {
		s.insert(x);
	}
	for (int value : numbers) {
		if (s.find(value - 1) == -1) {
			int curr = val;
			int count = 1;
			while(s.find(curr + 1) != -1) {
				curr = curr + 1;
				count = count + 1;
			}
			maxNum = std::max(maxNum, count);
		}
	}
	return maxNum;
}
*/

// Roman to Integer
int romanToInteger(std::string roman) {
	map<char, int> m;
	m.insert(pair<char, int>('I', 1));
	m.insert(pair<char, int>('V', 5));
	m.insert(pair<char, int>('X', 10));
	m.insert(pair<char, int>('L', 50));
	m.insert(pair<char, int>('C', 100));
	m.insert(pair<char, int>('M', 1000));
	int result = 0;
	for (int i = 0; i < roman.size()-1; ++i) {
		char s = roman[i];
		char s2 = roman[i+1];
		auto i0 = m.find(s);
		auto i1 = m.find(s2);
		if (i0->second < i1->second) {
			result -= i0->second;
		} else {
			result += i0->second;
		}
	}
	char fin = roman[roman.size()-1];
	return result + (m.find(fin))->second;
}


// Destination City
std::string destinationCity(std::vector<std::vector<std::string>>& paths) {
    std::unordered_set<std::string> startingCities;
    for (const auto& path : paths) {
        startingCities.insert(path[0]);
    }
    for (const auto& path : paths) {
        if (startingCities.find(path[1]) == startingCities.end()) {
            return path[1];
        }
    }
    return "";
}


// Heaps
/*

	Heap-Sort : Sorting Items using heaps
		
	Dijkstra's Algorithm

	- Finding trhe least tentative distance between to places
	
	Priority Queue 

	- Queus based on priority for weighted items

*/


int main() {

	// Understand | Match | Plan | Implement | Review | Evaluate
}