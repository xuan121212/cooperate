#include<iostream>
#include<cstdlib>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(double realPart);
	Complex(double realPart, double imaginaryPart);
	friend const Complex operator +(const Complex& number1, const Complex& number2);
	friend const Complex operator -(const Complex& number1, const Complex& number2);
	friend const Complex operator *(const Complex& number1, const Complex& number2);
	friend bool operator ==(const Complex& number1, const Complex& number2);
	friend istream& operator >>(istream& input, Complex& number);
	friend ostream& operator <<(ostream& output, const Complex& number);
private:
	double real, imaginary;
};

const Complex i(0, 1); //0a + i = i

int main()
{
	Complex myComplex(5, 2); //5 + 2i
	Complex youComplex;
	cout << "Enter a complex number(format: real imaginary): ";
	cin >> youComplex;
	cout << "c1: " << myComplex << endl;
	cout << "c2: " << youComplex << endl << endl;

	if (myComplex == youComplex)
	{
		cout << "two complex are same" << endl << endl;
	}
	else
	{
		cout << "two complex are difference" << endl << endl;
	}

	cout << "c1+c2 = " << myComplex + youComplex << endl;
	cout << "c1-c2 = " << myComplex - youComplex << endl;
	cout << "c1*c2 = " << myComplex * youComplex << endl;

	return 0;
}
Complex::Complex():real(0), imaginary(0)
{

}
Complex::Complex(double realPart) :real(realPart), imaginary(0)
{

}
Complex::Complex(double realPart, double imaginaryPart):real(realPart), imaginary(imaginaryPart)
{

}
istream& operator >>(istream& input, Complex& number)
{
	input >> number.real >> number.imaginary;
	return input;
}
ostream& operator <<(ostream& output, const Complex& number)
{
	if (number.real != 0)
	{
		if (number.imaginary == 0)
		{
			output << number.real;
			return output;
		}
		else if (number.imaginary < 0)
		{
			output << number.real << number.imaginary << "i";
			return output;
		}
		else
		{
			output << number.real << " + " << number.imaginary << "i";
			return output;
		}
	}
	else if (number.real == 0)
	{
		if (number.imaginary == 0)
		{
			output << number.real;
			return output;
		}
		else if (number.imaginary != 0)
		{
			output<< number.imaginary << "i";
			return output;
		}
	}
}
const Complex operator +(const Complex& number1, const Complex& number2)
{
	double realSum = number1.real + number2.real;
	double imagSum = number1.imaginary + number2.imaginary;
	return Complex(realSum, imagSum);
}
const Complex operator -(const Complex& number1, const Complex& number2)
{
	double realDiff = number1.real - number2.real;
	double imagDiff = number1.imaginary - number2.imaginary;
	return Complex(realDiff, imagDiff);
}
const Complex operator *(const Complex& number1, const Complex& number2)
{
	double realProduct = (number1.real * number2.real) - (number1.imaginary * number2.imaginary);
	double imagProduct = (number1.real * number2.real) + (number1.imaginary * number2.imaginary);
	return Complex(realProduct, imagProduct);
}
bool operator ==(const Complex& number1, const Complex& number2)
{
	return(number1.real == number2.real && number1.imaginary == number2.imaginary);
}