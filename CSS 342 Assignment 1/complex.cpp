/*
 CSS 342 Assignment 1
 Purpose: implement the functions of the complex class
 
 @file complex.hpp
 @author Leo Le
 @version 1.0   10/11/2017
 */

#include "complex.hpp"

//Constructors
/**
 Default constructor of the complex class
 */
complex::complex()
{
    this->real = 0.0;
    this->imaginary = 0.0;
}

/**
 Constructor with only real value
 
 @param real The real number of a complex
 */
complex::complex(double real)
{
    this->real = real;
    this->imaginary = 0.0;
}

/**
 Constructor with real and imaginary value
 
 @param real The real number of a complex
 @param imaginary The imaginary number of a complex
 */
complex::complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

//getter
/**
 Returns the real number of a complex
 
 @return real Get the real number
 */
double complex::getReal() const
{
    return this->real;
}

/**
 Returns the imaginary number of a complex
 
 @return imaginary Get the imaginary number
 */
double complex::getImaginary() const
{
    return this->imaginary;
}


//operator overloads
/**
 Overload the += operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex& complex::operator+=(const complex &comp)
{
    this->real = this->real + comp.real;
    this->imaginary = this->imaginary + comp.imaginary;
    return *this;
}

/**
 Overload the -= operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex& complex::operator-=(const complex &comp)
{
    this->real = this->real - comp.real;
    this->imaginary = this->imaginary - comp.imaginary;
    return *this;
}

/**
 Overload the *= operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex& complex::operator*=(const complex &comp)
{
    double originalReal = this->real; //this represents real before it changes itself
    this->real = (this->real * comp.real) - (this->imaginary * comp.imaginary);
    this->imaginary = (this->imaginary * comp.real) + (originalReal * comp.imaginary);
    return *this;
}

/**
 Overload the /= operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex& complex::operator/=(const complex &comp)
{
    complex conjNum;        //the conjugate number
    complex numerator;      //numerator is *this complex
    complex denominator;    //denominator is the comp complex to be used
    complex currNum;        //put *this's values into currNum as a copy
    //catch unacceptable denominator
    if (comp.real == 0.0 && comp.imaginary == 0.0)
    {
        cout << "ERROR: This calculation is incorrect!!!" << endl;
    }
    //calculate the division
    else {
        //get conjugate number of the denominator for calculation
        conjNum = comp.conjugate();
        currNum.real = this->real;
        currNum.imaginary = this->imaginary;
        //multiply both denominator and numerator by the conjugate of the denominator
        numerator.real = (currNum.real * conjNum.real) - (currNum.imaginary * conjNum.imaginary);
        numerator.imaginary = (currNum.imaginary * conjNum.real) + (currNum.real * conjNum.imaginary);
        denominator.real = (comp.real * conjNum.real) - (comp.imaginary * conjNum.imaginary);
        denominator.imaginary = (comp.imaginary * conjNum.real) + (comp.real * conjNum.imaginary); // this will cancel out (0)
        //divide the numerator by denomintor
        this->real = numerator.real / denominator.real;
        this->imaginary = numerator.imaginary / denominator.real;
    }
    return *this;
}

/**
 Overload the + operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex complex::operator+(const complex &comp) const
{
    //implement the += operator
    complex result = *this;
    result += comp;
    return result;
}

/**
 Overload the - operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex complex::operator-(const complex &comp) const
{
    //implement the -= operator
    complex result = *this;
    result -= comp;
    return result;
}

/**
 Overload the * operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex complex::operator*(const complex &comp) const
{
    //implement the *= operator
    complex result = *this;
    result *= comp;
    return result;
}

/**
 Overload the / operator
 
 @param comp The complex number
 @return result Result of the calculation
 */
complex complex::operator/(const complex &comp) const
{
    //implement the /= operator
    complex result = *this;
    result /= comp;
    return result;
}

/**
 Overload the == operator
 
 @param comp The complex number
 @return result Result of the comparison
 */
bool complex::operator==(const complex &comp) const
{
    return ((this->real == comp.real) && (this->imaginary == comp.imaginary));
}

/**
 Overload the != operator
 
 @param comp The complex number
 @return result Result of the comparison
 */
bool complex::operator!=(const complex &comp) const
{
    return ((this->real != comp.real) || (this->imaginary != comp.imaginary));
}

//overloading input/output operators

/**
 Overload the << operator
 
 @param comp The complex number
 @param outStream Output to the console
 @return print out the appropriate complex number form
 */
ostream& operator<<(ostream &outStream, const complex &comp)
{
    double negativeImg = -1 * comp.imaginary; //This double changes the sign of negative imaginary number
    //case when complex is 0.0
    if (comp == 0.0)
    {
        return outStream << "0";
    }
    //case when only imaginary exists
    else if (comp.real == 0.0 && comp.imaginary != 0.0)
    {
        if (comp.imaginary == 1.0)
            return outStream << "i";
        else if (comp.imaginary == -1.0)
            return outStream << "- i";
        else
            return outStream << comp.imaginary << "i";
    }
    //case when only real exists
    else if (comp.real != 0.0 && comp.imaginary == 0.0)
    {
        return outStream << comp.real;
    }
    //case when real and imaginary != 0
    else
    {
        if (comp.imaginary == 1.0)
            return outStream << comp.real << " + i";
        else if (comp.imaginary == -1.0)
            return outStream << comp.real << " - i";
        else if (comp.imaginary < 0.0)
            return outStream << comp.real << " - " << negativeImg << "i";
        else {
            return outStream << comp.real << " + " << comp.imaginary << "i";
        }
    }
}

/**
 Overload the >> operator
 
 @param comp The complex number
 @param inStream input from the console
 */
istream& operator>>(istream &inStream, complex &comp)
{
    //get input from user
    inStream >> comp.real >> comp.imaginary;
    return inStream;
}

//conjugate

/**
 Returns a conjugate of the complex number
 
 @return conjugate Conjugate of a complex
 */
complex complex::conjugate() const
{
    complex conjugated;
    conjugated.real = this->real;
    conjugated.imaginary = -1 * this->imaginary;
    return conjugated;
}
