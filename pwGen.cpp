// TODO: 
// 	- Break into functions
// 	- Allow for multiple passwords in one run

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <climits>
#include <ctime>

class Generator {
	private:
		const static int NUM_LETTERS = 26;
		const static int NUM_NUMS = 10;
		const static int NUM_SYMS = 13;

		const char lowercase[NUM_LETTERS] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		const char uppercase[NUM_LETTERS] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		const char numbers[NUM_NUMS] = {'0','1','2','3','4','5','6','7','8','9'};
		const char syms[NUM_SYMS] = {'.','!','?','@','#','$','%','&','*','(',')','[',']'};

		int len;
		char password[];
	public:
		Generator(int length) : len(length) { password[len]; }

	void makePassword() {
		//srand(time(NULL));

	//	int lowIndex, upperIndex, numIndex, symIndex;
		for(int i = 0; i < len; i++) {
			int nextChar = rand() % 4;
			switch(nextChar) {
				case 0:
					{
					int lowIndex = rand() % NUM_LETTERS;
					password[i] = lowercase[lowIndex]; 
					break;
					}
				case 1:
					{
					int upperIndex = rand() % NUM_LETTERS;
					password[i] = uppercase[upperIndex];
					break;
					}
				case 2:
					{
					int numIndex = rand() % NUM_NUMS;
					password[i] = numbers[numIndex];	
					break;
					}
				case 3:
					{
					int symIndex = rand() % NUM_SYMS;
					password[i] = syms[symIndex];
					break;
					}
			};	
		}

	}

	void printPassword() {

		for(int i = 0; i < len; i++) {
		std::cout << password[i];
		}

	std::cout << std::endl;
	
	}

};

// Gets string input from user
std::string getStringInput(); 
// Gets integer input from user
int getIntInput(std::string message); 

int main() {

	srand(time(NULL));
	std::cout << "How many passwords would you like to generate?" << std::endl;
	int numPasswords = getIntInput(">");
	std::cout << "How long would you like each password to be?" << std::endl;
	int passwordLength = getIntInput(">");
	for(int i = 0; i < numPasswords; i++) {
		Generator * g = new Generator(passwordLength);
		g->makePassword();
		g->printPassword();
		delete g;
	}

	return 0;

}

// Gets string input from user
std::string getStringInput() {
	std::string input;
	std::getline(std::cin,input);
	return input;
}

// Gets integer input from user
int getIntInput(std::string message) {
	std::string rawInput;
	while(true) {
		std::cout << message;
		rawInput = getStringInput();
		std::stringstream stream(rawInput);

		int value;
		char temp;
		stream >> value;
		if(stream && !(stream >> temp) && value > 0 && value <= 24) {
			return value;
		}
		else {
			std::cout << "Invalid input" << std::endl;
		}
	}
}	
