#include<iostream>
using namespace std;

class Complex{
    double real, imag;
public:
    Complex(){
    }
    Complex(double real, double imag){
        this->real = real;
        this->imag = imag;
    }
    Complex& operator=(const Complex& comp){
        if(&comp != this){
            this->real = comp.real;
            this->imag = comp.imag;
        }
        return *this;
    }
    Complex operator~() const{
        return Complex(real, -imag);
    }
    friend const Complex operator+(const Complex& a, const Complex& b);
    friend const Complex operator-(const Complex& a, const Complex& b);
    friend const Complex operator*(const Complex& a, const Complex& b);
    friend const Complex operator*(const double x, const Complex& b);
    friend ostream& operator<<(ostream& out, const Complex& comp);
    friend istream& operator>>(istream& in, Complex& comp);
};

const Complex operator+(const Complex& a, const Complex& b){
    return Complex(a.real+b.real, a.imag+b.imag);
}
const Complex operator-(const Complex& a, const Complex& b){
    return Complex(a.real-b.real, a.imag- b.imag);
}
const Complex operator*(const Complex& a, const Complex& b){
    return Complex(a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real);
}
const Complex operator*(const double x, const Complex& b){
    return Complex(x*b.real, x*b.imag);
}
ostream& operator<<(ostream& out, const Complex& comp){
    out << '(' << comp.real << ',' << comp.imag << "i)";
    return out;
}
istream& operator>>(istream& in, Complex& comp){
    cout << "real:";
    if(in >> comp.real){
        cout << "imaginary:";
        in >> comp.imag;
    }
    return in;
}

int main(){
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while(cin >> c){
        cout << "c is " << c << endl;
        cout << "complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
        cout << "2 * c is " << 2 * c << endl;
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
