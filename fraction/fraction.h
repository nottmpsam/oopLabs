#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {

    int numerator_;
    int denominator_;

    void Check(int numerator, int denominator);
    public:
    Fraction()
    {
            numerator_ = 0;
            denominator_ = 1;
    }

    Fraction(int numerator, int denominator)
    {
        if (denominator == 0) {
            denominator = 1;
            std::cerr << "Error! Now denominator is 1." << std::endl;
        }
        Check(numerator, denominator);
        numerator_ = numerator;
        denominator_ = denominator;
    }

    int Nok(int numerator, int denominator);
    int Nod(int numerator, int denominator);
    bool operator<(const Fraction& cFraction) const;
    bool operator>(const Fraction& cFraction) const;
    bool operator==(const Fraction& cFraction) const;
    bool operator!= (const Fraction& cFraction) const;
    bool operator<=(const Fraction& cFraction) const;
    bool operator>=(const Fraction& cFraction) const;

    Fraction operator*(int integer) const;
    friend Fraction operator*(int integer,
        const Fraction& cFraction);
    Fraction operator/(int integer) const;
    friend Fraction operator/(int integer,
        const Fraction& cFraction);
    Fraction operator+(int integer) const;
    friend Fraction operator+(int integer,
        const Fraction& cFraction);
    Fraction operator-(int integer) const;
    friend Fraction operator-(int integer,
        const Fraction& cFraction);

    Fraction operator=(const Fraction& cFraction);
    Fraction & operator/=(const Fraction& cFraction);
    Fraction & operator*=(const Fraction& cFraction);
    Fraction & operator-=(Fraction& cFraction);
    Fraction & operator+=(Fraction& cFraction);

    Fraction operator*(const Fraction& cFraction) const;
    Fraction operator/(const Fraction& cFraction) const;
    Fraction operator+(Fraction& cFraction);
    Fraction operator-(Fraction& cFraction);

    Fraction & operator++();
    Fraction & operator--();
    Fraction operator--(int);
    Fraction operator++(int);
    int GetNumerator() 
    { 
        return numerator_; 
    }
    int GetDenominator() 
    {
        return denominator_; 
    }
    void ReplaceFraction(int numerator,  int denominator);
    void ReplaceNumerator(int numerator);
    void ReplaceDenominator(int denominator);
    void Display(); 
    void Enter();
    void Pow(int k);
    void Abs();
};
#endif 
