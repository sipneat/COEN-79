/*
 * File Name: tb_statistician.c
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-18-2023
 * 
 * Description: Test bench for the statistician class that can be used to calculate
 *              the sum, mean, minimum, and maximum of a sequence of numbers.
 */

#include "statistician.h"
#include <iostream>

using namespace std;
using namespace coen79_lab2;

void printInfo(statistician &s) {
    cout << "Sum: " << s.sum() << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "Smallest: " << s.minimum() << endl;
    cout << "Largest: " << s.maximum() << "\n" <<endl;
}

int main(void) {
    statistician s1, s2, s3;
    double nums1[] = {1.1, -2.4, 0.8};
    double nums2[] = {5.7, -3.8, 4.9};

    cout << "--- s1 prints ---" << endl;
    for (int i = 0; i < 3; i++) {
        s1.next(nums1[i]);
        printInfo(s1);
    }

    cout << "--- s2 prints ---" << endl;
    for (int i = 0; i < 3; i++) {
        s2.next(nums2[i]);
        printInfo(s2);
    }

    cout << "--- s3 print ---" << endl;
    s3 = s1 + s2;
    printInfo(s3);

    cout << "--- erase prints ---" << endl;
    s1.reset();
    s1.next(5);
    printInfo(s1);
    s2 = s1;
    printInfo(s2);
    
    s1.reset();
    s2.reset();
    s1.next(4);
    s2.next(4);
    if (s1 == s2) {
        cout << "s1 is equal to s2\n" << endl;
    } else {
        cout << "s1 is not equal to s2\n" << endl;
    }

    cout << "--- scaling test ---" << endl;
    s1.reset();
    s1.next(4);
    s1.next(-2);
    printInfo(s1);

    s1 = -1 * s1;
    printInfo(s1);
    return 0;
}