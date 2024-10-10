#include "Complex.h"
#include <iostream>
#include <cmath>

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(double scalar) const {
    return Complex(real * scalar, imag * scalar);
}

double Complex::abs() const {
    return std::sqrt(real * real + imag * imag);
}

void Complex::display() const {
    std::cout << real << " + " << imag << "i" << std::endl;
}
