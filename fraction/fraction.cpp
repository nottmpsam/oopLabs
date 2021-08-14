#include "fraction.h"
#include <cmath>
void Fraction::ReplaceNumerator(int numerator)
{
    numerator_ = numerator;
}
void Fraction::ReplaceDenominator(int denominator)
{
        if (denominator == 0)
        {
            std::cerr << "Error! Denominator is zero. Reenter: ";
            int temp;
            while (!(std::cin >> temp) || temp == 0)
            {
                std::cin.clear();
                while(std::cin.get() != '\n')
                    continue;
                std::cerr << "Reenter again! " << std::endl;
            }
            denominator = temp;
        }
        denominator_ = denominator;
}
void Fraction::Enter() {

    std::cout << "Enter numerator and denominator: " << std::endl;
    std::cin >> numerator_;
    while (!(std::cin >> denominator_) || (denominator_ == 0)) {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "Enter again your denominator. " << std::endl;
    } //denominator can't be zero

}
void Fraction::ReplaceFraction(int numerator,  int denominator)
{   //instead of constr.
        if (denominator == 0)
        {
            std::cerr << "Error! Denominator is zero. Reenter: ";
            int temp;
            while (!(std::cin >> temp) || temp == 0)
            {
                std::cin.clear();
                while(std::cin.get() != '\n')
                    continue;
                std::cerr << "Reenter again! " << std::endl;
            }
            denominator = temp;
        }
        numerator_ = numerator;
        denominator_ = denominator;
        Check(numerator_, denominator_);
}
void Fraction::Display() {
    Check(numerator_, denominator_);
    if (numerator_ % denominator_ == 0) {
        std::cout << numerator_ / denominator_ << std::endl;
    } else if ((numerator_ > denominator_) && (numerator_ % denominator_ != 0)) {
        int cl, num, dem;
        cl = numerator_ / denominator_;
        num = numerator_ % denominator_;
        dem = denominator_;
        std::cout << cl << " * (" << num << " / " << dem << ")  ||  " <<
            numerator_ << '/' << denominator_ << std::endl;
    } else {
        std::cout << numerator_ << '/' << denominator_ << std::endl;
    }

}
void Fraction::Check(int numerator, int denominator) {

    int del = Nod(numerator, denominator);
    numerator_ /= del;
    denominator_ /= del;
    if (numerator_ < 0 && denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
}

bool Fraction::operator<(const Fraction& cFraction) const {
    if (numerator_ * cFraction.denominator_ < cFraction.numerator_ * denominator_)
        return true;
    return false;
}
bool Fraction::operator>(const Fraction& cFraction) const {
    if (numerator_ * cFraction.denominator_ > cFraction.numerator_ * denominator_)
        return true;
    return false;
}
bool Fraction::operator==(const Fraction& cFraction) const {
    if (numerator_ * cFraction.denominator_ == cFraction.numerator_ * denominator_)
        return true;
    return false;
}
bool Fraction::operator!=(const Fraction& cFraction) const {
    if ((numerator_ * cFraction.denominator_) != (cFraction.numerator_ * denominator_))
        return true;
    return false;
}
bool Fraction::operator<=(const Fraction& cFraction) const {
    if ((numerator_ * cFraction.denominator_ < cFraction.numerator_ * denominator_) || numerator_ * cFraction.denominator_ == cFraction.numerator_ * denominator_)
        return true;
    return false;
}
bool Fraction::operator>=(const Fraction& cFraction) const {
    if ((numerator_ * cFraction.denominator_ > cFraction.numerator_ * denominator_) || numerator_ * cFraction.denominator_ == cFraction.numerator_ * denominator_)
        return true;
    return false;
}

Fraction Fraction::operator*(int integer) const {
    Fraction temp;
    temp.numerator_ = integer * numerator_;
    temp.denominator_ = denominator_;
    return temp;
}
Fraction operator*(int integer,
    const Fraction& cFraction) {
    Fraction temp;
    integer *= cFraction.denominator_;
    temp.numerator_ = integer - cFraction.numerator_;
    temp.denominator_ = cFraction.denominator_;
    return temp;
}
Fraction operator/(int integer,
    const Fraction& cFraction) {
    Fraction temp;
    if (integer == 0) {
        std::cerr << "Can't calculate this operation!  ";
        temp.numerator_ = cFraction.numerator_;
        temp.denominator_ = cFraction.denominator_;
        return temp;
    }
    temp.numerator_ = cFraction.numerator_;
    temp.denominator_ = integer * cFraction.denominator_;
    return temp;
}
Fraction Fraction::operator/(int integer) const {
    if (integer == 0) {
        std::cerr << "Cann't calculate this operation!  ";
        return *this;
    }

    Fraction temp;
    temp.numerator_ = numerator_;
    temp.denominator_ = denominator_ * integer;
    return temp;

}
Fraction Fraction::operator-(int integer) const {
    Fraction temp;
    integer *= denominator_;
    temp.numerator_ = numerator_ - integer;
    temp.denominator_ = denominator_;
    return temp;
}
Fraction Fraction::operator+(int integer) const {
    Fraction temp;
    integer *= denominator_;
    temp.numerator_ = numerator_ + integer;
    temp.denominator_ = denominator_;
    return temp;
}
Fraction operator+(int integer,
    const Fraction & cFraction) {
    Fraction temp;
    integer *= cFraction.denominator_;
    temp.numerator_ = cFraction.numerator_ + integer;
    temp.denominator_ = cFraction.denominator_;
    return temp;
}
Fraction operator-(int integer,
    const Fraction & cFraction) {
    Fraction temp;
    integer *= cFraction.denominator_;
    temp.numerator_ = integer - cFraction.numerator_;
    temp.denominator_ = cFraction.denominator_;
    return temp;
}

Fraction Fraction::operator*(const Fraction& cFraction) const {
    Fraction temp;
    temp.numerator_ = cFraction.numerator_ * numerator_;
    temp.denominator_ = cFraction.denominator_ * denominator_;
    return temp;
}
Fraction Fraction::operator/(const Fraction& cFraction) const {

    if (cFraction.numerator_ == 0) {
        std::cerr << "Cann't calculate this operation! " << std::endl;
        return *this;
    }

    Fraction temp;
    temp.numerator_ = numerator_ * cFraction.denominator_;
    temp.denominator_ = denominator_ * cFraction.numerator_;
    return temp;

}
Fraction Fraction::operator+(Fraction& cFraction) {
    Fraction temp;
    if (denominator_ == cFraction.denominator_) {
        temp.numerator_ = numerator_ + cFraction.numerator_;
        temp.denominator_ = denominator_;
    } else {
        int k = Nok(denominator_, cFraction.denominator_);
        int k2 = k / cFraction.denominator_;
        k /= denominator_;
        denominator_ *= k;
        numerator_ *= k;
        cFraction.denominator_ *= k2;
        cFraction.numerator_ *= k2;
        temp.numerator_ = numerator_ + cFraction.numerator_;
        temp.denominator_ = cFraction.denominator_;

    }
    return temp;
}
Fraction Fraction::operator-(Fraction& cFraction) {
    Fraction temp;
    if (denominator_ == cFraction.denominator_) {
        temp.numerator_ = numerator_ - cFraction.numerator_;
        temp.denominator_ = denominator_;
    } else {
        int k = Nok(denominator_, cFraction.denominator_);

        int k2 = k / cFraction.denominator_;
        k /= denominator_;
        denominator_ *= k;
        numerator_ *= k;
        cFraction.denominator_ *= k2;
        cFraction.numerator_ *= k2;
        temp.numerator_ = numerator_ - cFraction.numerator_;
        temp.denominator_ = cFraction.denominator_;
    }
    return temp;
}
Fraction& Fraction::operator*=(const Fraction& cFraction) {
    numerator_ *= cFraction.numerator_;
    denominator_ *= cFraction.denominator_;
    return *this;
}
Fraction& Fraction::operator+=(Fraction& cFraction) {

    if (denominator_ == cFraction.denominator_) {
        numerator_ += cFraction.numerator_;
    } else {
        int k = Nok(denominator_, cFraction.denominator_);
        int k2 = k / cFraction.denominator_;
        k /= denominator_;
        denominator_ *= k;
        numerator_ *= k;
        cFraction.denominator_ *= k2;
        cFraction.numerator_ *= k2;
        numerator_ += cFraction.numerator_;
    }
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& cFraction) {
    if (cFraction.numerator_ == 0) {
        std::cerr << "Cann't calculate this operation! " << std::endl;
        return *this;
    }
    numerator_ *= cFraction.denominator_;
    denominator_ *= cFraction.numerator_;
    return *this;
}
Fraction& Fraction::operator-=(Fraction& cFraction) {
    if (denominator_ == cFraction.denominator_) {
        numerator_ -= cFraction.numerator_;
    } else {
        int k = Nok(denominator_, cFraction.denominator_);

        int k2 = k / cFraction.denominator_;
        k /= denominator_;
        denominator_ *= k;
        numerator_ *= k;
        cFraction.denominator_ *= k2;
        cFraction.numerator_ *= k2;
        numerator_ -= cFraction.numerator_;

    }
    return *this;
}
Fraction Fraction::operator=(const Fraction& cFraction) {
    numerator_ = cFraction.numerator_;
    denominator_ = cFraction.denominator_;
    return *this;
}
Fraction Fraction::operator++(int){
    Fraction temp = ++(*this);
    return temp;
}
Fraction Fraction::operator--(int){
    Fraction temp = --(*this);
    return temp;
}

Fraction& Fraction::operator--() {
    numerator_ -= denominator_;
    return *this;
}
Fraction& Fraction::operator++() {
    numerator_ += denominator_;
    return *this;
}

int Fraction::Nod(int numerator, int denominator) {
    numerator = (numerator < 0) ? -numerator : numerator;
    denominator = (denominator < 0) ? -denominator : denominator;
    if (numerator % denominator == 0)
        return denominator;
    if (denominator % numerator == 0)
        return numerator;
    if (numerator > denominator)
        return Nod(numerator % denominator, denominator);
    return Nod(numerator, denominator % numerator);
}
int Fraction::Nok(int numerator, int denominator) {
    return (numerator * denominator) / Nod(numerator, denominator);
}

void Fraction::Pow(int k) {
    if (k > 0) {
        numerator_ = pow(numerator_, k);
        denominator_ = pow(denominator_, k);
    } else {
        int temp = numerator_;
        numerator_ = pow(denominator_, -k);
        denominator_ = pow(temp, -k);

    }
}
void Fraction::Abs() {
    numerator_ = numerator_ < 0 ? -numerator_ : numerator_;
    denominator_ = denominator_ < 0 ? -denominator_ : denominator_;
}


