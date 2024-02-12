/*
 * File Name: p2.c
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-11-2023
 * 
 * Description: The user enters a 10-digit number. The program should print out inputs and reversed
 * inputs in a specified format (see below). If the input is illegal (size() != 10), notify the user and
 * quit the program. You can assume that the input has no whitespace and only contains digits.
 * Input: Custom 10-digit input
 * Output: 5 "tilted" rows of input and reversed input.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main() {
    string input;
    string reversedInput;

    cout << "Enter a 10-digit number: \n";
    getline(cin, input);

    if (input.length() != 10) {
        cout << "Illegal input." << endl;
        return 0;
    }

    for (int i = input.length() - 1; i >= 0; i--) {
        reversedInput += input[i];
    }

    for (int i = 0; i < 5; i++) {
        cout << "\t" << setw(10 + 2*i) << input << setw(20) << reversedInput << endl;
    }

    cout << endl;

    return 0;
}