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

/*
	// ANSI escape codes for colors
	const std::string RESET_COLOR = "\033[0m";
	const std::string RED_COLOR = "\033[31m";
	const std::string GREEN_COLOR = "\033[32m";
	const std::string YELLOW_COLOR = "\033[33m";
	const std::string BLUE_COLOR = "\033[34m";
	int main() {
	    // Print text in different colors
	    std::cout << RED_COLOR << "This is red text." << RESET_COLOR << std::endl;
	    std::cout << GREEN_COLOR << "This is green text." << RESET_COLOR << std::endl;
	    std::cout << YELLOW_COLOR << "This is yellow text." << RESET_COLOR << std::endl;
	    std::cout << BLUE_COLOR << "This is blue text." << RESET_COLOR << std::endl;
	    return 0;
	}

*/
const std::string RESET_COLOR = "\033[0m";
const std::string RED_COLOR = "\033[31m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";

// Future feature to add is only chaning the correct letters including letter count

void displayWordleBoard(char board[6][5], string chosenWord) {
	int rows = 6;
    int cols = 5;
    std::cout << "+----+----+----+----+----+" << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::cout << "| ";
        for (int j = 0; j < cols; ++j) {
        	char letter = chosenWord[j];
        	if (tolower(board[i][j]) == letter) {
        		std::cout << GREEN_COLOR << board[i][j] << RESET_COLOR << "  | ";
        	} else if (tolower(board[i][j]) != letter && chosenWord.find(tolower(board[i][j])) != std::string::npos) {
        		std::cout << YELLOW_COLOR << board[i][j] << RESET_COLOR << "  | ";
        	} else {
        		 std::cout << board[i][j] << "  | ";
        	}
        }
        std::cout << std::endl;
        std::cout << "+----+----+----+----+----+" << std::endl;
    }
}

// Convert String to lowercase version of it self
std::string toLowerCase(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

void playWordle() {
	cout << "Type Play to Begin..." << endl;
	string playerResponse;
	do {
		cin >> playerResponse;
		if ( playerResponse == "Play") {
			cout << "Game Starting..." << endl;
			break;
		}
	} while (playerResponse != "Play");
	char player[6][5] = {
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' '},
	};
	std::vector<std::string> wordBank = {
        "apple", "banjo", "camel", "depot", "eagle", "fjord", "grape",
        "horse", "igloo", "joker", "koala", "lemon", "mango", "nacho",
        "olive", "piano", "quilt", "robot", "salad", "tiger", "umbra",
        "vivid", "whale", "xenon", "yacht", "zebra", "aloft", "brave",
        "crisp", "dwarf", "excel", "flute", "grill", "hatch", "inbox",
        "jolly", "knack", "lucky", "mirth", "noble", "ocean", "plumb",
        "quack", "raven", "scout", "trunk", "unify", "vigor", "wrack",
        "xerox", "yield", "zesty"
    };
    srand((unsigned) time(NULL));
    string word = wordBank[rand() % wordBank.size()];
    cout << "The chosen word is " << word << endl;
    int rows = 6;
    int cols = 5;
    std::cout << "+----+----+----+----+----+" << std::endl;
    for (int i = 0; i < rows; ++i) {
        std::cout << "| ";
        for (int j = 0; j < cols; ++j) {
            std::cout << player[i][j] << "  | ";
        }
        std::cout << std::endl;
        std::cout << "+----+----+----+----+----+" << std::endl;
    }
    cout << "You have six attempts to guess a five-letter word" << endl;
    int lives = 6;
    int round = 0;
    bool solved = false;

    while (lives > 0) {
    	cout << "Enter Guess .." << endl;
    	string playerGuess;
    	do {
    		cin >> playerGuess;
    	} while(playerGuess.size() < 5 || playerGuess.size() > 5);

    	for (int i = 0; i < 5; ++i) {
    		player[round][i] = toupper(playerGuess[i]);
    	}

    	displayWordleBoard(player, word);
 		

    	if (toLowerCase(playerGuess) == word) {
    		solved = true;
    		break;
    	}
    	round++;
    	lives--;
    }

    if (solved) {
    	std::cout << GREEN_COLOR << "YOU WIN" << RESET_COLOR << endl;
    } else {
    	std::cout << RED_COLOR << "YOU LOSE" << RESET_COLOR << endl;
    }

    std::cout << "Type Again to play one more time..." << endl;
	string response;
	do {
		cin >> response;
		if (response == "Again") {
		    playWordle();
		}
	} while(response != "Again");
}

int main() {

	playWordle();

	return 0;
}