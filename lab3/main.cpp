/*
 * File Name: main.cpp
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-24-2023
 * 
 * Description: Testbench for the sequence class
 */

#include "sequence1.h"
#include <iostream>

using namespace std;
using namespace coen79_lab3;

void printSequence(sequence &s) {
    cout << "Contents: ";
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1) {
            cout << s[i];
        }
        else {
            cout << s[i] << " ";
        }
    }
    cout << endl;
}

void printStats(sequence &s) {
    cout << "-----------------------------" << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "StdDev: " << s.standardDeviation() << endl;
    cout << "Sum: " << summation(s) << endl;
    printSequence(s);
    cout << "-----------------------------" << endl;
}

int main(void) {
    sequence tester1;
    tester1.insert(1);
    tester1.insert(2);
    tester1.insert(3);
    printStats(tester1);

    sequence tester2;
    tester2.insert(2);
    tester2.insert(3);
    tester2.insert(4);
    printStats(tester2);

    cout << "tester 3 :" << endl;
    sequence tester3;
    tester3 = tester1 + tester2;
    printStats(tester3);

    cout << "tester 3 functions :" << endl;
    tester3.advance();
    printStats(tester3);
    tester3.advance();
    printStats(tester3);
    tester3.remove_front();
    printStats(tester3);
    tester3.advance();
    printStats(tester3);
    tester3.remove_front();
    printStats(tester3);
    tester3.advance();
    printStats(tester3);
    tester3.remove_current();
    printStats(tester3);
    tester3.attach_back(14);
    printStats(tester3);
}