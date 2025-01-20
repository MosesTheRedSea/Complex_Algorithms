#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>
#include<numeric>
#include <algorithm>

// Header Files
#include "add.h" 

// Built Data Structures
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <deque>
#include <unordered_set>
#include <set> 
#include <algorithm>
#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include "add.h"
#include <climits> // for CHAR_BIT
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <cstdint> // for fast and least types

using namespace std;

#define IDENTIFIER substitution_text
#define MY_NAME "Alex"
#define PRINT_JOE

/* 
	█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
	█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
	█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀	
*/

// All of the following statements are part of the global namespace

void doNothing(int&) {}

int getValueFromUser(){
	std::cout << "Enter a number: ";
	int input{};
	std::cin >> input;
	return input;
}

void doubleValue(int/*takes in number*/){}

int main() {

	std::cout << "Hello, World!\n";

	std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

	// std::cout << sizeof(int) << 65'\n'; 
	// int x{};

	std::int32_t x2 { 32767 }; // x is always a 32-bit integer
    x2 = x2 + 1;                // so 32768 will always fit
    std::cout << x2 << '\n';

	// std::cin >> x;	
	// std::cout << "You Entered" <<  '\n' << x << '\n';

	std::int8_t x3 { 65 };   // initialize 8-bit integral type with value 65 | Acts like a char
    std::cout << x3 << '\n'; // You're probably expecting this to print 65

	// double width;
	// int length {2};
	// int a, b;

	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";

	std::cout << '\n';

	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

	// width = 5.0;
	// string name = "";

	std::uint_fast16_t sometype { 0 };
    sometype = sometype - 1; // intentionally overflow to invoke wraparound behavior

    std::cout << sometype << '\n';
    // This code will produce different results depending on whether std::uint_fast16_t is 16, 32, or 64 bits! This is exactly what we were trying to avoid by using fixed-width integers in the first place!

	// std::cout << width << endl;
	// std::cout << "Hello world!" << endl;

	// // getline(cin, name);
	// std::cout << name << endl;

	// int y;
	// doNothing(y);
	// std::cout << y << '\n';

	// We could also use 
	// In place of #ifdef PRINT_BOB and #ifndef PRINT_BOB, you’ll also see #if defined(PRINT_BOB) and #if !defined(PRINT_BOB).
	// These do the same, but use a slightly more C++-style syntax.
	#ifdef PRINT_JOE
	    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
	#endif
	#ifdef PRINT_BOB
	    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
	#endif
	// To temporarily re-enable code that has been wrapped in an #if 0, you can change the #if 0 to #if 1

	#if 0 // Don't compile anything starting here
    std::cout << "Bob\n";
    std::cout << "Steve\n";
	#endif // until this point

	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

	int w{getValueFromUser()};
	std::cout << "You Selected: " << w << endl;

	// std::size_t is actually a typedef.
	int x {5};
    std::size_t s { sizeof(x) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

     // Compiled as a 32-bit (4 byte) console app on the author’s system, this prints: 4
    std::cout << sizeof(std::size_t) << '\n';
   
    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

    // Outputting Floating Point Values
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';;',';

    float f { 123456789.0f }; // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << '\n';


    // Data Structures

    // Vector

    // std::vector<int> vect;
    // for (int i = 0; i < 6; ++i) {
    // 	vect.push_back(10 - i); // Insert at the end of the array
    // }

    // for (int k = 0; k < vect.size(); ++k) {
    // 	std::cout << vect[k] << ' ';
    // }

    // std::cout << "\n";

    // // Deque 
    // std::deque<int> deq;
    // for (int i = 0; i < 3; ++i) {
    // 	deq.push_back(i);
    // 	deq.push_front(10-i);
    // }
    // for (int k = 0; k < deq.size(); ++k) {
    // 	std::cout << deq[k] << ' ';
    // }


    // STL Iterators Overview

    /*
		- Operator* - Dereferencing the iterator
		 returns the element that the iterator is cucrently pointing at

		 Operator++ - Moves the iterator to the next element in the container.
		 Most Iterators also have the Operator-- 

		 Operator== and Operator!= - Basic Comparison operators to determine fi two iterators point
		 to the same element

		 Operator = - Assign the iterator to a new position typically the start or end of the conrainers elements

		begin()

		end()

		cbegin()

		cend()
		
		container::iterator()
		container::const_iterator

    */

	// Iterator through a string using Iterator
	// std::vector<int>::const_iterator it;
	// it = vect.cbegin();
	// while (it != vect.cend()) {
	// std::cout << *it << ' ';
	// ++it;
	// }
	// cout << "\n";


	// // Iterating through a list using iterator

	// std::list<int> li;
	// for (int count = 0; cout < 6; ++count) {
	// li.push_back(count);
	// }

	// std::list<int>::const_iterator it;
	// it = li.cbegin();
	// while (it != li.cend()) {
	// std::cout << *it << ' ';
	// ++it;
	// }
	// cout << "\n";

	// // Iterating through a set using iterator
	// std::set<int> myset;
	// myset.insert(6);
	// myset.insert(5);
	// myset.insert(4);
	// myset.insert(3);
	// myset.insert(2);
	// myset.insert(1);
	// myset.insert(0);
	// std::set<int>::const_iterator it;
	// it = myset.cbegin();
	// while (it != myset.cend()) {
	// std:: cout << *it << '';
	// it++;
	// }

	// cout << "\n";

    // Iterating through a map in C++ using iterator
    std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	//auto iterator{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
	std::map<int, std::string>::const_iterator iterator = mymap.cbegin();
	while (iterator != mymap.cend()) // while it hasn't reach the end
	{
		std::cout << iterator->first << '=' << iterator->second << ' '; // print the value of the element it points to
		++iterator; // and iterate to the next element
	}

	cout << "\n";

	// STL Algorithm

	std::list<int> li(6);
	// Fill li with numbers starting at 0;
	std::iota(li.begin(), li.end(), 0);
	std:: cout << *std::min_element(li.begin(), li.end());

	// Find the value of 3 in the list

	auto it{ std::find(li.begin(), li.end(), 3)};
	

	return 0;
}
