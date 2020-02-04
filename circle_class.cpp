#include<iostream>
using namespace std;

class Circle{
    const float pi = 3.14;
    float radius, perimeter, area;
    int compute(){
        this->perimeter = 2 * pi * this->radius;
        this->area = pi * this->radius * this->radius;
        return 0;
    }
    int print(){
        cout << this->radius << ' ' << this->perimeter << ' ' << this->area;
        return 0;
    }
public:
    Circle(float r=0){
        this->radius = r;
        this->compute();
        this->print();
    }
    Circle& operator =(const Circle& cir){
        if(this != &cir){
            this->radius = cir.radius;
            this->perimeter = cir.perimeter;
            this->area = cir.area;
        }
        return *this;
    }
};

int main(){
    float r;
    cin >> r;
    Circle mycircle(r);
    return 0;
}
