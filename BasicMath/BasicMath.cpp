// BasicMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

int getUserInput() 
{
	std::cout << "Enter an integer: ";
	int value;
	std::cin >> value;
	return value;
}

int getOperator() {
	int op;
	std::cin >> op;
	return op;
}

int moreCalculations() {
	std::cout << "Do you need to do another calculation? (Yes: 1; anything else: no) ";
	int more;
	std::cin >> more;
	return more;
}

int calculate(int x, int y, int op)
{
	if (op == 1)
	{
		return x + y;
	}
	else if (op == 2)
	{
		return x - y;
	}
	else if (op == 3)
	{
		return x * y;
	}
	else if (op == 4)
	{
		return x / y;
	}
	else if (op == 5) {
		double f = pow(x, y);
#pragma warning
		int g = f;
		return g;
	}
	else if (op == 6) {
		return pow(y, 1 / x);
	}
	else if (op == 7) {
		return (log10(x) / log10(y));
	}
	else if (op == 8) {
		return log(x);
	}
}

void help() {
	std::cout << "For which operation? ";
	int helpOperation;
	std::cin >> helpOperation;
	if (helpOperation == 1) {
		std::cout << "This shows the sum of two items.\n";
	}
	else if (helpOperation == 2) {
		std::cout << "This shows the difference of the first item and the second item in that order.\n";
	}
	else if (helpOperation == 3) {
		std::cout << "This shows the product of the two items.\n";
	}
	else if (helpOperation == 4) {
		std::cout << "This shows the quotient of the first item and the second item in that order.\n";
	}
	else if (helpOperation == 5) {
		std::cout << "This shows the first number as base b raised to the second number as exponent n.\n";
	}
	else if (helpOperation == 6) {
		std::cout << "This is the second number taken to the first number-th root.";
	}
	else if (helpOperation == 7) {
		std::cout << "This is the log with a base of the second number.";
	}
}

void print(int result)
{
	std::cout << "Your result is: " << result << std::endl;
}

int input1, input2;
void calculator() {
	std::cout << "Please enter which operator you want (1 = +, 2 = -, 3 = *, 4 = /, 5 = ^, 6 for root, 7 for log, 8 for ln)\nType anything else for help. ";

	int op = getOperator();
	if (op > 8) {
		help();
	}
	else if (op == 8) {
		input1 = getUserInput();
		input2 = 0;
	}
	else {
		input1 = getUserInput();
		input2 = getUserInput();
	}

	int result = calculate(input1, input2, op);
	print(result);
}


void runAgain(int confirm) {
	if (confirm == 1) {
		calculator();
	}
	else {
		exit(0);
	}
}

void start() {
	std::cout << "This is a basic calculator.\n";
	
	calculator();

	int again = moreCalculations();
	runAgain(again);
}

int main()
{	
	while (true) {
		start();
	}
	return 0;
}

