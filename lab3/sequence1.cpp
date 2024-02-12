/*
 * File Name: sequence1.cpp
 * 
 * Author: Jake Esperson
 * 
 * Date: 01-24-2023
 * 
 * Description: Defines the sequence class that can be used to store a sequence
 *              of numbers.
 */

#include "sequence1.h"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3 {
    // Function: sequence (constructor)
    // Postcondition: The object has been initialized
    sequence::sequence() {
        used = 0;
        current_index = 0;    
    }

    // Function: is_item
    // Postcondition: True indicates that there is a valid "current" item
    bool sequence::is_item() const {
        if (current_index <= used) {
            return true;
        }
        return false;
    }

    // Function: start
    // Postcondition: Set iterator to 0
    void sequence::start() {
        current_index = 0;
    }

    // Function: end
    // Postcondition: Set iterator to last item
    void sequence::end() {
        current_index = used - 1;
    }

    // Function: last
    // Postcondition: Set iterator to last slot
    void sequence::last() {
        current_index = CAPACITY - 1;
    }

    // Function: advance
    // Precondition: is_item() returns true
    // Postcondition: Increase iterator by 1
    void sequence::advance() {
        assert(is_item());
        current_index++;
    }

    // Function: retreat
    // Precondition: is_item() returns true
    // Postcondition: Decrease iterator by 1
    void sequence::retreat() {
        assert(is_item());
        current_index--;
    }

    // Function: insert
    // Precondition: size() < CAPACITY
    // Postcondition: Insert entry into sequence at current_index
    void sequence::insert(const value_type& entry) {
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = 0;
        }
        for (int i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }

    // Function: insert_front
    // Precondition: size() < CAPACITY
    // Postcondition: Insert entry into sequence at front
    void sequence::insert_front(const value_type& entry) {
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = 0;
        }
        for (int i = used; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = entry;
        used++;
    }

    // Function: attach
    // Precondition: size() < CAPACITY
    // Postcondition: Insert entry into sequence after current_index
    void sequence::attach(const value_type& entry) {
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = used - 1;
        }
        for (int i = used; i > current_index + 1; i--) {
            data[i] = data[i - 1];
        }
        data[current_index + 1] = entry;
        used++;
    }

    // Function: attach_back
    // Precondition: size() < CAPACITY
    // Postcondition: Insert entry into sequence at back
    void sequence::attach_back(const value_type& entry) {
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = used - 1;
        }
        data[used] = entry;
        used++;
    }

    // Function: remove_current
    // Precondition: is_item() returns true
    // Postcondition: Remove current_index from sequence
    void sequence::remove_current() {
        assert(is_item());
        for (int i = current_index; i < used - 1; i++) {
            data[i] = data[i + 1];
        }
        used--;
    }

    // Function: remove_front
    // Precondition: is_item() returns true
    // Postcondition: Remove front from sequence
    void sequence::remove_front() {
        assert(is_item());
        for (int i = 0; i < used - 1; i++) {
            data[i] = data[i + 1];
        }
        used--;
    }

    // Function: operator+=
    // Postcondition: Add rhs to lhs
    void sequence::operator+=(const sequence& rhs) {
        assert(size() + rhs.size() <= CAPACITY);
        for (size_type i = 0; i < rhs.used; i++) {
            attach_back(rhs.data[i]);
        }
    }

    // Function: size
    // Postcondition: Return size of sequence
    sequence::size_type sequence::size() const {
        return used;
    }

    // Function: current
    // Precondition: is_item() returns true
    // Postcondition: Return current_index
    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }

    // Function: index
    // Precondition: is_item() returns true
    // Postcondition: Return current_index
    sequence::size_type sequence::index() const {
        assert(is_item());
        return current_index;
    }

    // Function: operator[]
    // Precondition: index < used
    // Postcondition: Return the item at index
    sequence::value_type sequence::operator[](int index) const {
        assert(index < used);
        return data[index];
    }

    // Function: mean
    // Precondition: size() > 0
    // Postcondition: Return the mean of the sequence
    sequence::value_type sequence::mean() const {
        assert(size() > 0);
        double sum = 0;
        for (int i = 0; i < used; i++) {
            sum += data[i];
        }
        return sum / used;
    }

    // Function: standardDeviation
    // Precondition: size() > 0
    // Postcondition: Return the standard deviation of the sequence
    sequence::value_type sequence::standardDeviation() const {
        assert(size() > 0);
        double sum = 0;
        double mean = this->mean();
        for (int i = 0; i < used; i++) {
            sum += (data[i] - mean) * (data[i] - mean);
        }
        return sqrt(sum / used);
    }

    // Function: operator+
    // Precondition: lhs.size() + rhs.size() <= CAPACITY
    // Postcondition: Return lhs + rhs
    sequence operator+(const sequence& lhs, const sequence& rhs) {
        assert(lhs.size() + rhs.size() <= sequence::CAPACITY);
        sequence result;
        result += lhs;
        result += rhs;
        return result;
    }

    // Function: summation
    // Postcondition: Return the summation of the sequence
    sequence::value_type summation(const sequence& s) {
        double sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i];
        }
        return sum;
    }
}
