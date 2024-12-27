#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*

█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀

*/

int num_courses;
vector<vector<string>> final_info;

void print2DVector(vector<vector<string>> arr);
void printTable();
void calculateGPA();

int main() {

	// How many courses student is in
	cout << "How many classes are you currently enrolled in ?" << endl;

	cin >> num_courses;

	cout << "\n" << endl;

	vector<string> info;

	string name;
	string credit;

	string grade;
	int count = 0;

	// Take in user data
	for (int i = 0; i < num_courses; ++i) {

		vector<string> info = {};

		cout << "----------------------------------" << endl;
		cout << "Select a random letter ?" << endl;
		cin >> name;
		info.push_back(name);

		cout << "How many credits is the course ?" << endl;
		cin >> credit;
		info.push_back(credit);

		cout << "What is your grade in the course ?" << endl;
		cin >> grade;
		info.push_back(grade);

		cout << "----------------------------------" << endl;
		final_info.push_back(info);
		print2DVector(final_info);

		cout << " " << endl;
	}

	printTable();

	cout << "\n" << endl;

	calculateGPA();

	int a;
	cin >> a;
	cout << a << endl;
}

// Test Vector Printer
void printVector(vector<string> a) {
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
}

// Test Matrix Printer 
void print2DVector(vector<vector<string>> arr) {
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			cout << arr[i][j] + " ";
		}
		cout << "\n";
	}
}

void printTable() {
	cout << "--------------------------------------------------------" << endl;
	cout << "|      Course      |      Credit      |     Grade      |"<< endl;
	cout << "--------------------------------------------------------";
	for (int i = 0; i < num_courses; ++i) {
		cout << " " << endl;
	    cout << "|         " <<  final_info[i][0] << "        |        " <<  final_info[i][1]  << "         |       " << final_info[i][2] << "      |" << endl;
		//cout << "|            |            |            |"<< endl;
		//cout << std::format("|   {}   |   {}   |   {}    |", final_info[i][0], final_info[i][0], final_info[i][0]) << endl;
		cout << "--------------------------------------------------------";
	}
}

void calculateGPA() {

	double totalCredits = 0;
	double sum = 0;

	for (int i = 0; i < final_info.size(); ++i) {

		int gradeValue = stoi(final_info[i][2]);

		if (gradeValue >= 90 && gradeValue <= 100) {

			totalCredits += (4 * stoi(final_info[i][1]));

		} else if (gradeValue >= 80 && gradeValue <= 89) {

			totalCredits += (3 * stod(final_info[i][1]));

		} else if (gradeValue >= 75 && gradeValue <= 79) {

			totalCredits += (2 * stod(final_info[i][1]));
			
		} else if (gradeValue >= 70 && gradeValue <= 74) {
			
			totalCredits += (1 * stod(final_info[i][1]));

		} else if (gradeValue >= 60 && gradeValue <= 69) {

			totalCredits += (0 * stod(final_info[i][1]));
			
		}

		// Adds the Credit to the 
		sum += stoi(final_info[i][1]);

	}

	cout << "\n" << endl;

	double gpa = (double)totalCredits / (double)sum;

	cout << "--------------------------------------------------------" << endl;
	cout << "|     Grade*Credits    |    Credits   |   Final GPA    |"<< endl;
	cout << "--------------------------------------------------------";
	cout << " " << endl;
	cout << "|         " <<  ceil(totalCredits * 100.0) / 100.0 << "        |        " <<  ceil(sum * 100.0) / 100.0  << "         |       " << ceil(gpa * 100.0) / 100.0 << "    |" << endl;
	cout << "--------------------------------------------------------";


	
}

