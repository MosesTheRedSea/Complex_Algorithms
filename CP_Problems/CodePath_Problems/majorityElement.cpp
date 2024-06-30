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

int majorityElement(vector<int> nums) {
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		m[nums[i]]++;
	}
	int max = 0;
	int num = 0;
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second > max) {
			max = i->second;
			num = i->first;
		}
	}
	return num;
}

int main() {
	
	vector<int> vals = {1, 2, 3, 4, 4, 4, 4}; // 4
	vector<int> vals2 = {1 , 2, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}; // 5
	vector<int> vals3 = {1, 2, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6}; // 6

	cout << "Majoirty Element " << majorityElement(vals) << endl;
	cout << "Majoirty Element " << majorityElement(vals2) << endl;
	cout << "Majoirty Element " << majorityElement(vals3) << endl;

}			