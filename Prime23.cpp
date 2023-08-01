#include <iostream>
#include <time.h>
using namespace std;


class Prime23 {

};

int main(){

	srand((unsigned) time(NULL));
	int numToCheck = (rand() % 1000) + 2;
	int numFactors = 2;
	int smallestFactor = numToCheck;
	int currentFactor = numToCheck - 1;

	cout << "Checking if " << numToCheck << " is prime..." << endl;

	while(currentFactor >= 2) {
		if (numToCheck % currentFactor == 0) {
			cout << currentFactor << " divides " << numToCheck << endl;
			if (currentFactor < smallestFactor) {
				smallestFactor = currentFactor;
			}
			numFactors++;
		} else {
			cout << numToCheck << " is not a multiple of " << currentFactor << endl;
		}
		currentFactor--;
	}

	cout << "Number to check for primality " << numToCheck << endl;
	cout << "Smallest factor: " << smallestFactor << endl;

	switch(numFactors) {
		case 2:
			cout << "The number is prime!" << endl;
			break;

		case 3:
			cout << "The number has three factors so it is not prime" << endl;
			break;

		case 4:
			cout << "The number has four factors so it is not prime " << endl;
			break;

		case 5:
			cout << "The number has five factors so it is not prime " << endl;
			break;

		default: 
			cout << "Wow, " << numFactors << " is a lot of factors! This number is not prime." << endl;
			break;

	}


	return 0;
}