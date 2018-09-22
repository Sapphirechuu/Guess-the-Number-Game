#include <iostream>
#include "checkValidHeader.h"

using std::cout;
using std::endl;
int main()
{
	while (true)
	{
		int min = 1;
		int max = 100;
		int guess;
		bool guessed = false;
		cout << "Welcome to the guess YOUR number game!\nYou think of a number and I'll try and guess it!\nThink of a number between 1-100 and click Enter when you have it." << endl;
		std::cin.get();
		cout << "Great! Now, for my first guess!" << endl;
		while (!guessed)
		{
			guess = (min + max) / 2;
			cout << "Is your number " << guess << "?\n(1 for yes, 2 for no)" << endl;
			int input = 0;
			if (checkValid(input) == 1)
			{
				guessed = true;
			}
			else
			{
				cout << "Is your number higher or lower? (1 for higher, 2 for lower)" << endl;
				int holIn = 0;
				if (checkValid(holIn) == 1)
				{
					min = guess;
				}
				else
				{
					max = guess;
				}
			}
		}
		cout << "Hey! I guessed the number!\nWould you like to restart? (1 for yes, 2 for no)" << endl;
		int exitIn = 0;
		if (checkValid(exitIn) == 2)
		{
			break;
		}
	}
	return 0;
}

int checkValid(int input)
{
	bool validNum = false;
	while (!validNum)
	{
		bool validIn = false;
		while (!validIn)
		{
			std::cin >> input;
			if (!(validIn = std::cin.good()))
			{
				cout << "I'm sorry, that wasn't a valid response. Please try again" << endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		if (input == 1 || input == 2)
		{
			validNum = true;
			return input;
		}
	}
}