#ifndef GUESS_H
#define GUESS_H

#include <utility>
#include <ctime>
#include <iostream>

using namespace std;

// Austin Chandler - this is my own work and what we did in class

class Guess {
private:
	int aGuess[4];
	bool isValid(int) const; 
public:
	Guess();
	void setGuess(int, int, int, int);
	void setMaster();
	int operator[](int) const;
};

//implementations
//constructor
Guess::Guess()
{
	aGuess[0] = aGuess[1] = aGuess[2] = aGuess[3] = -1;
	srand(time(NULL));
}

//overloading the operator so I can use it as an array
int Guess::operator[](int index) const
{
	return aGuess[index];
}

//setting a guess
void Guess::setGuess(int a, int b, int c, int d)
{
	if (isValid(a)) aGuess[0] = a;
	else {
		//aking for a new value if there is a bad value
		while (isValid(a) == false) {
			cout << a << " is not a valid value. Please enter a new value: ";
			cin >> a;
		}
		aGuess[0] = a;
	}
	if (isValid(b)) aGuess[1] = b;
	else {
		//aking for a new value if there is a bad value
		while (isValid(b) == false) {
			cout << b << " is not a valid value. Please enter a new value: ";
			cin >> b;
		}
		aGuess[1] = b;
	}
	if (isValid(c)) aGuess[2] = c;
	else {
		//aking for a new value if there is a bad value
		while (isValid(c) == false) {
			cout << c << " is not a valid value. Please enter a new value: ";
			cin >> c;
		}
		aGuess[2] = c;
	}
	if (isValid(d)) aGuess[3] = d;
	else {
		//aking for a new value if there is a bad value
		while (isValid(d) == false) {
			cout << d << " is not a valid value. Please enter a new value: ";
			cin >> d;
		}
		aGuess[3] = d;
	}
}

//making sure the inputted values are within the range I want (0-5)
bool Guess::isValid(int a) const
{
	return (0 <= a && a <= 5);
}

//making the code
void Guess::setMaster()
{
	aGuess[0] = rand() % 6;
	aGuess[1] = rand() % 6;
	aGuess[2] = rand() % 6;
	aGuess[3] = rand() % 6;
}

#endif
