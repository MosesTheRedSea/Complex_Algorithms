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

// Link : https://codeforces.com/blog/entry/82143
// Problem 1 - A.Team
int A_Team() {  
    int count;  
    std::cin >> count; // 3 How many inputs to have 
    std::cin.ignore(); // To ignore the newline character after the integer inputs
    int questions = 0;  
    for (int i = 0; i < count; ++i) {
        std::string input;  
        std::getline(std::cin, input);  
        std::istringstream ss(input);   
        std::vector<int> values;    
        std::string item;
        while (ss >> item) {
            values.push_back(std::stoi(item));
        }
        int track = 0;
        for (int num : values) {
            if (num == 1) {
                track++;
            }
        }
        if (track >= 2) {
            questions++;
        }
    }
    cout << questions << endl; // Output the Answer not return it
    return 0;
}

// Problem 2 - A. Is your horseshoe on the other hoof ?
int horseShoe_On_Other_Hoof() { 
	std::string input;
    std::getline(std::cin, input);
    std::istringstream ss(input);
    std::vector<int> values;
    std::string item;
    while (ss >> item) {
        values.push_back(std::stoi(item));
    }
    std::set<int> tracker(values.begin(), values.end());
    cout << values.size() - tracker.size() << endl;           
}

void boyOrGirl() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream ss(input);
    // We have the String input now we can make the necessary checks
    for (int i = 0; i < max.size(); ++i) {
        
    }       
}

void checkValues() {    
}       




int main() {

    return 0;

}