#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double r, double i);

    double getReal() const;
    double getImag() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(double scalar) const;

    double abs() const;

    void display() const;
};

#endif
