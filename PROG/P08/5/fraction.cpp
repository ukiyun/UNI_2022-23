#include <iostream>
#include <cmath>

using namespace std;

//! define the Fraction class.
class Fraction{
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        int numerator() const;
        int denominator() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
        int gcd(int a, int b);
        void normalise();
        void write() const;
    private:
        int numerator_;
        int denominator_;

};

Fraction::Fraction(){
    numerator_=0;
    denominator_=1;
}

Fraction::Fraction(int numerator, int denominator){
    numerator_=numerator;
    denominator_ = denominator;
    Fraction::normalise();
}

int Fraction::numerator() const{
    return numerator_;
}

int Fraction::denominator() const{
    return denominator_;
}

Fraction Fraction::sum(const Fraction& right){
    int numerator = (numerator_ * right.denominator()) + (denominator_*right.numerator());
    int denominator = right.denominator() * denominator_;
    return Fraction(numerator, denominator);
}

Fraction Fraction::sub(const Fraction& right){
    int numerator = (numerator_ * right.denominator()) - (denominator_*right.numerator());
    int denominator = right.denominator() * denominator_;
    return Fraction(numerator, denominator);
}

Fraction Fraction::mul(const Fraction& right){
    int numerator = numerator_ * right.numerator();
    int denominator = right.denominator() * denominator_;
    return Fraction(numerator, denominator);
}

Fraction Fraction::div(const Fraction& right){
    int numerator = numerator_ * right.denominator();
    int denominator = denominator_ * right.numerator();
    return Fraction(numerator, denominator);
}

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

// shows fraction f on the screen
void Fraction::write() const {
  cout << numerator() << '/' << denominator();
}
