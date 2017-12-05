/*
 CSS 342 Assignment 1
 Purpose: list all the functions of the complex class
 
 @file complex.hpp
 @author Leo Le
 @version 1.0   10/11/2017
 */

#include <stdio.h>
#include <iostream>
using namespace std;

class complex
{
public:
    //Constructors
    /**
     Default constructor of the complex class
     */
    complex();
    
    /**
     Constructor with only real value
     
     @param real The real number of a complex
     */
    complex(double real);
    
    /**
     Constructor with real and imaginary value
     
     @param real The real number of a complex
     @param imaginary The imaginary number of a complex
     */
    complex(double real, double imaginary);
    
    
    //getter
    /**
     Returns the real number of a complex
     
     @return real Get the real number
     */
    double getReal() const;
    
    /**
     Returns the imaginary number of a complex
     
     @return imaginary Get the imaginary number
     */
    double getImaginary() const;
    
    
    //operators overload
    /**
     Overload the += operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex& operator+=(const complex &comp);
    
    /**
     Overload the -= operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex& operator-=(const complex &comp);
    
    /**
     Overload the *= operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex& operator*=(const complex &comp);
    
    /**
     Overload the /= operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex& operator/=(const complex &comp);
    
    /**
     Overload the + operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex operator+(const complex &comp) const;
    
    /**
     Overload the - operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex operator-(const complex &comp) const;
    
    /**
     Overload the * operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex operator*(const complex &comp) const;
    
    /**
     Overload the / operator
     
     @param comp The complex number
     @return result Result of the calculation
     */
    complex operator/(const complex &comp) const;
    
    /**
     Overload the == operator
     
     @param comp The complex number
     @return result Result of the comparison
     */
    bool operator==(const complex &comp) const;
    
    /**
     Overload the != operator
     
     @param comp The complex number
     @return result Result of the comparison
     */
    bool operator!=(const complex &comp) const;
    
    
    //overloading input/output operators
    
    /**
     Overload the << operator
     
     @param comp The complex number
     @param outStream Output to the console
     @return print out the appropriate complex number form
     */
    friend ostream& operator<<(ostream &outStream, const complex &comp);
    
    /**
     Overload the >> operator
     
     @param comp The complex number
     @param inStream input from the console
     */
    friend istream& operator>>(istream &inStream, complex &comp);
    
    
    //conjugate
    
    /**
     Returns a conjugate of the complex number
     
     @return conjugate Conjugate of a complex
     */
    complex conjugate() const;
    
private:
    /**
     Real number of a complex
     */
    double real;
    /**
     Imaginary number of a complex
     */
    double imaginary;
};
