#include "poly.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4 {
    // Function: update_current_degree
    // Postcondition: The current degree is updated
    void polynomial::update_current_degree() {
        for (int i = MAXIMUM_DEGREE; i >= 0; i--) {
            if (coef[i] != 0) {
                current_degree = i;
                return;
            }
        }
        current_degree = 0;
    }

    // Function: polynomial (constructor)
    // Postcondition: The object has been initialized
    polynomial::polynomial(double c, unsigned int exponent) {
        for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
            coef[i] = 0;
        }
        coef[exponent] = c;
        update_current_degree();
    }

    // Function: assign_coef
    // Postcondition: The coefficient is assigned to the exponent
    void polynomial::assign_coef(double coefficient, unsigned int exponent) {
        coef[exponent] = coefficient;
        update_current_degree();
    }

    // Function: add_to_coef
    // Postcondition: The amount is added to the exponent
    void polynomial::add_to_coef(double amount, unsigned int exponent) {
        coef[exponent] += amount;
        update_current_degree();
    }

    // Function: clear
    // Postcondition: The polynomial is cleared
    void polynomial::clear() {
        for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
            coef[i] = 0;
        }
        current_degree = 0;
    }

    // Function: antiderivative
    // Postcondition: The antiderivative of the polynomial is returned
    polynomial polynomial::antiderivative() const {
        polynomial p;
        for (int i = MAXIMUM_DEGREE; i >= 0; i--) {
            p.coef[i + 1] = coef[i] / (i + 1);
        }
        p.update_current_degree();
        return p;
    }

    // Function: coefficient
    // Postcondition: The coefficient of the exponent is returned
    double polynomial::coefficient(unsigned int exponent) const {
        return coef[exponent];
    }

    // Function: definite_integral
    // Postcondition: The definite integral of the polynomial from x0 to x1 is returned
    double polynomial::definite_integral(double x0, double x1) const {
        polynomial p = antiderivative();
        return p.eval(x1) - p.eval(x0);
    }

    // Function: derivative
    // Postcondition: The derivative of the polynomial is returned
    polynomial polynomial::derivative() const {
        polynomial p;
        for (int i = 1; i <= MAXIMUM_DEGREE; i++) {
            p.coef[i - 1] = coef[i] * i;
        }
        p.update_current_degree();
        return p;
    }

    // Function: eval
    // Postcondition: The value of the polynomial is returned
    double polynomial::eval(double x) const {
        double result = 0;
        for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
            result += coef[i] * pow(x, i);
        }
        return result;
    }

    // Function: is_zero
    // Postcondition: True is returned if the polynomial is zero
    bool polynomial::is_zero() const {
        for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
            if (coef[i] != 0) {
                return false;
            }
        }
        return true;
    }

    // Function: next_term
    // Postcondition: The next term is returned
    unsigned int polynomial::next_term(unsigned int e) const {
        for (int i = e + 1; i <= MAXIMUM_DEGREE; i++) {
            if (coef[i] != 0) {
                return i;
            }
        }
        return 0;
    }

    // Function: previous_term
    // Postcondition: The previous term is returned
    unsigned int polynomial::previous_term(unsigned int e) const {
        for (int i = e - 1; i >= 0; i--) {
            if (coef[i] != 0) {
                return i;
            }
        }
        return UINT_MAX;
    }

    // Function: operator +
    // Postcondition: The sum of the two polynomials is returned
    polynomial operator +(const polynomial& p1, const polynomial& p2) {
        polynomial p;
        for (int i = 0; i <= polynomial::MAXIMUM_DEGREE; i++) {
            p.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
        }
        return p;
    }

    // Function: operator -
    // Postcondition: The difference of the two polynomials is returned
    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial p;
        for (int i = 0; i <= polynomial::MAXIMUM_DEGREE; i++) {
            p.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
        }
        return p;
    }

    // Function: operator *
    // Precondition: The degree of the product is less than or equal to MAXIMUM_DEGREE
    // Postcondition: The product of the two polynomials is returned
    polynomial operator *(const polynomial& p1, const polynomial& p2) {
        polynomial p;
        for (int i = 0; i <= polynomial::MAXIMUM_DEGREE; i++) {
            for (int j = 0; j <= polynomial::MAXIMUM_DEGREE; j++) {
                if (i + j <= polynomial::MAXIMUM_DEGREE) {
                    p.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i + j);
                }
            }
        }
        return p;
    }

    // Function: operator <<
    // Postcondition: The polynomial is printed
    ostream& operator << (ostream& out, const polynomial& p) {
        bool first = true;
        for (int i = polynomial::MAXIMUM_DEGREE; i >= 0; i--) {
            if (i == 0 && p.coefficient(i) == 0 && first) {
                out << "0.0";
            }
            if (p.coefficient(i) != 0) {
                if (!first && p.coefficient(i) > 0) {
                    out << " + ";
                }
                if (i == 0) {
                    if (p.coefficient(i) < 0) {
                        if (first) {
                            out << "- " << fixed << setprecision(1) << abs(p.coefficient(i));;
                        } else {
                            out << " - " << fixed << setprecision(1) << abs(p.coefficient(i));
                        }
                    } else {
                    out << fixed << setprecision(1) << p.coefficient(i);
                    }
                } else {
                    if (p.coefficient(i) != 1) {
                        if (p.coefficient(i) < 0) {
                            if (first) {
                                out << "- " << fixed << setprecision(1) << abs(p.coefficient(i));;
                            } else {
                                out << " - " << fixed << setprecision(1) << abs(p.coefficient(i));
                            }
                        } else {
                            out << fixed << setprecision(1) << p.coefficient(i);
                        }
                    }
                    out << "x";
                    if (i != 1) {
                        out << "^" << i;
                    }
                }
                first = false;
            }
        }
        return out;
    }
}