#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int num;

class RandomMath {

};


int main() {

	cout << "1, Powers of a Number" << endl;
	cout << "2, Random Positive Integer with Maximum" << endl;
	cout << "3, Area of Random Circle" << endl;
	cout << "4, Area of Random Square" << endl;
	cout << "What would you like to do ?" << endl;

	int userInput;
	cin >> userInput;
	
	while(userInput < 1 || userInput > 4) {
		cout << "Invalid user input, type a number 1-4" << endl;
		cin >> userInput;
	}

	if (userInput == 1) {
		cout << "What number would you like to calculate powers of?" << endl;
		cin >> num;

		if (num == -1) {
			cout << "-1 raised to 0 is 1 \n -1 raise to odd powers greater than 0 is -1 \n -1 raised to even powers greater than 0 is 1" << endl;
		} else if (num == 0) {

			cout << "0 raised to the 0 is 1" << endl;
			cout << "0 raised to powers greater than 0 is 0" << endl;

		} else if (num == 1) {
			cout << "1 raised to ANY power is still 1" << endl;
		} else {
			int exp = 0;
			do {
				cout << num << " raised to the " << exp << " is " << pow(num, exp) << endl;
				exp++; 
			} while(abs(pow(num, exp)) < 100);
	}

	

	} else if (userInput == 2) {

		cout << "What is the max value you want your random number to be?" << endl;
		cin >> num;

		while(num <= 0) {
			cout << "User input must be positive and non-zero" << endl;
			cin >> num;
		}

		srand((unsigned) time(NULL));

		int random = 1 + (rand() % num);

		cout << "Your random number is " << random << endl;


	} else if (userInput == 3) {	
		srand((unsigned) time(NULL));
		int circleRadius = rand() % 100;

		cout << "A circle of radius " << circleRadius << " has an area of " << pow(circleRadius,2) * 3.14 << endl;
			
	} else if (userInput == 4) {
		
		srand((unsigned) time(NULL));

		int randomSquare = rand() % 100;

		cout << "A sqaure of side length " << randomSquare << " has an area of " << pow(randomSquare, 2) << endl;

	}




	return 0;
}