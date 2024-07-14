#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>
#include <sstream>

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

// Reverse the elements in a matrix

void printMatrix(vector<vector<int>> nums) {
	
}

vector<vector<int>> reverseElementsInMatrix(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size()); // .resize() method in C+= to resize the contents inside a matrix
    for (int i = 0; i < A.size(); i++) {  // Loop through A size
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}

float calculatePrice() {
	string mystr;
	float price=0;	
	int quantity=0;
	cout << "Enter price: ";	
	getline (cin,mystr);		
	stringstream(mystr) >> price; // stringstream essentially converts the string to a double or float
	cout << "Enter quantity: ";
	getline (cin,mystr);	
	stringstream(mystr) >> quantity;		
	cout << "Total price: " << price*quantity << endl;	
	// Using clog for logging - printing logs
   std::clog << "This is a log message." << std::endl;
   // Using cerr for error messages - reporting errors
   std::cerr << "This is an error message." << std::endl;	
}

int searchMatrix(vector<vector<int>> nums, int target) {
	int ROWS, COLS = nums.size(0), nums[0].size();
	top, bot = 0, ROWS - 1
	while (top <= bot) {
		int row = std::floor((top + bot) / 2);
		if target > matrix[row].back();
			top++;
		else if (target < matrix[row].back()) {
			
		}
	}
}

int main ()
{

	for (int n=0, i=100; n!=i; ++n, --i )
	{
	   // whatever here...
		cout << n << " " << i << endl; // Essentially reaches half way
	}
  	return 0;

}