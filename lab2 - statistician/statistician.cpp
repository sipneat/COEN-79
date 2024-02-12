/*
 * File Name: statistician.c
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-18-2023
 * 
 * Description: Defines the statistician class that can be used to calculate
 *              the sum, mean, minimum, and maximum of a sequence of numbers.
 */

#include "statistician.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2 {
    // Function: statistician (constructor)
    // Postcondition: The object has been initialized, and is ready to accept
    statistician::statistician() {
        count = 0;
        total = 0;
        smallest = 0;
        largest = 0;
    }

    // Function: resest
    // Postcondition: The statistician has been cleared, as if no numbers had
    void statistician::reset() {
        count = 0;
        total = 0;
        smallest = 0;
        largest = 0;
    }

    // Function: next
    // Precondition: given a number r
    // Postcondition: The number r becomes the next number in the sequence
    void statistician::next(double r) {
        count++;
        total += r;
        if (r < smallest || count == 1) {
            smallest = r;
        }
        if (r > largest) {
            largest = r;
        }
    }

    // Function: length
    // Postcondition: The return value is the length of the sequence that has
    int statistician::length() const {
        return count;
    }

    // Function: sum
    // Postcondition: The return value is the sum of all the numbers in the sequence
    double statistician::sum() const {
        return total;
    }

    // Function: mean
    // Precondition: length() > 0
    // Postcondition: The return value is the arithmetic mean
    double statistician::mean() const {
        assert(length() > 0);
        return sum() / length();
    }

    // Function: minimum
    // Precondition: length() > 0
    // Postcondition: The return value is the smallest number in the sequence
    double statistician::minimum() const {
        assert(length() > 0);
        return smallest;
    }

    // Function: maximum
    // Precondition: length() > 0
    // Postcondition: The return value is the largest number in the sequence
    double statistician::maximum() const {
        assert(length() > 0);
        return largest;
    }

    // Function: operator +
    // Precondition: s1 and s2 are valid statistician objects
    // Postcondition: The statistician object that is returned contains all the
    //                numbers of the sequences of s1 and s2
    statistician operator +(const statistician& s1, const statistician& s2) {
        statistician s3;
        s3.count = s1.length() + s2.length();
        s3.total = s1.sum() + s2.sum();
        s3.smallest = min(s1.minimum(), s2.minimum());
        s3.largest = max(s1.maximum(), s2.maximum());
        return s3;
    }

    // Function: operator *
    // Precondition: scale is a double and s is a valid statistician object
    // Postcondition: The statistician object that is returned contains the
    //                numbers of the sequence of s scaled by the factor scale
    statistician operator *(double scale, const statistician& s) {
        statistician s2;
        s2.count = s.length();
        s2.total = s.sum() * scale;
        s2.smallest = s.maximum() * scale;
        s2.largest = s.minimum() * scale;
        return s2;
    }

    // Function: operator ==
    // Precondition: s1 and s2 are valid statistician objects
    // Postcondition: The return value is true if s1 and s2 have zero length
    //                or if they have the same length and values, and false otherwise
    bool operator ==(const statistician& s1, const statistician& s2) {
        if (s1.length() == 0 && s2.length() == 0) {
            return true;
        } else if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()) {
            return true;
        } else {
            return false;
        }
    }
}