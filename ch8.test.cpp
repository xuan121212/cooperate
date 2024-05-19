#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;



class Complex {


public:

    //constructor of the class
    Complex() :real(0), imaginary(0) {};

    //constructor of the class
    Complex(double realPart, double imaginaryPart) :real(realPart), imaginary(imaginaryPart) {};

    //constructor of the class
    Complex(double realPart) :real(realPart), imaginary(0) {};

    //setter of real
    void setReal(double real) { this->real = real; };

    //setter of imaginary
    void setImaginary(double imaginary) { this->imaginary = imaginary; };

    //getter of real
    double getReal() const { return  real; };

    //getter of imaginary
    double getImaginary() const { return imaginary; };

    friend const Complex operator +(const Complex& num1, const Complex& num2);

    friend const Complex operator -(const Complex& num1, const Complex& num2);

    friend const Complex operator *(const Complex& num1, const Complex& num2);

    friend bool operator ==(const Complex& num1, const Complex& num2);

    friend ostream& operator <<(Complex& num, ostream& outputStream);

    friend istream& operator >>(Complex& num, istream& inputStream);

private:

    double real;
    double imaginary;

};

const Complex i(0, 1);

//operator of ==
bool operator ==(const Complex& num1, const Complex& num2) {

    //whether num1 and num2 are equal
    return (num1.real == num2.real && num1.imaginary == num2.imaginary);

}


//operator of +
const Complex operator +(const Complex& num1, const Complex& num2) {

    double real, imaginary;

    //(a+bi)+(c+di) = (a+c)+(b+d)i
    real = num1.getReal() + num2.getReal();
    imaginary = num1.getImaginary() + num2.getImaginary();

    return Complex(real, imaginary);

}

//operator of -
const Complex operator -(const Complex& num1, const Complex& num2) {

    double real, imaginary;

    //(a+bi)-(c+di) = (a-c)+(b-d)i
    real = num1.getReal() - num2.getReal();
    imaginary = num1.imaginary - num2.imaginary;

    return Complex(real, imaginary);

}

//operator of *
const Complex operator *(const Complex& num1, const Complex& num2) {

    double real, imaginary;

    //(a+bi)*(c+di) = (ac-bd)+(ad+bd)i
    real = num1.real * num2.real - num1.imaginary * num2.imaginary;

    imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;

    return Complex(real, imaginary);

}

//operator of >>
istream& operator >>(istream& inputStream, Complex& num) {

    double real, imaginary;

    cout << "Enter the complex number (ex: a+bi => a b) => ";

    //input the complex number
    inputStream >> real >> imaginary;

    num.setReal(real);
    num.setImaginary(imaginary);

    return inputStream;

}

//operator of <<
ostream& operator <<(ostream& outputStream, const Complex& num) {

    //output the complex number
    //if imaginary part is more than 0, output a+bi
    if (num.getImaginary() >= 0)
        outputStream << num.getReal() << " + " << num.getImaginary() << "i";

    //if imaginary part is less than 0, output a-bi
    else
        outputStream << num.getReal() << " - " << -num.getImaginary() << "i";

    return outputStream;

}

int main() {

    Complex num1, num2;

    //input num1 and num2
    cin >> num1;
    cin >> num2;

    //output num1+num2
    cout << "(" << num1 << ") + (" << num2 << ") = " << num1 + num2 << endl;

    //output num1-num2
    cout << "(" << num1 << ") - (" << num2 << ") = " << num1 - num2 << endl;

    //output num1*num2
    cout << "(" << num1 << ") * (" << num2 << ") = " << num1 * num2 << endl;

    //if num1 is equal to num2
    if (num1 == num2)
        cout << num1 << " == " << num2 << endl;

    //if num1 isn't equal to num2
    else
        cout << num1 << " != " << num2 << endl;

    system("pause");

    return 0;

}