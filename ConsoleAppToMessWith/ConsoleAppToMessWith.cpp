// ConsoleAppToMessWith.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int varInt = 123456;
	string varString("DefaultString");
	char arrChar[128] = "Long char array right there ->";

	int* ptr2int = &varInt;
	int** ptr2ptr = &ptr2int;
	int*** ptr2ptr2 = &ptr2ptr;

	while (true)
	{
		cout << "Process ID: " << GetCurrentProcessId << endl;
		cout << "\n";
		cout << "varInt (0x" << &varInt << ") = " << varInt << endl;
		cout << "varString (0x" << &varString << ") = " << varString << endl;
		cout << "arrChar[128] (0x" << &arrChar << ") = " << arrChar << endl;
		cout << "\n";
		cout << "ptr2int (0x" << &ptr2int << ") = 0x" << ptr2int << endl;
		cout << "ptr2ptr (0x" << &ptr2ptr << ") = 0x" << ptr2ptr << endl;
		cout << "ptr2ptr2 (0x" << &ptr2ptr2 << ") = 0x" << ptr2ptr2 << endl;
		cout << "\n";
		cout << "Press ENTER to print again." << endl;
		cout << "\n\n";
		cout << "---------------------------------------------" << endl;

		getchar();
	};
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
