#include<iostream>
using namespace std;

class Rectangle{
    float length, width;
public:
    float area(){
        return this->length*this->width;
    }
    Rectangle(float a, float b){
        this->length = a;
        this->width = b;
    }
};

class Cuboid :public Rectangle{
    float height;
public:
    float Vol(){
        return this->height*this->area();
    }
    Cuboid(float a, float b, float c) :Rectangle(a, b){
        this->height = c;
    }
};

int main(){
    float len, wid, a, b, c;
    cin >> len >> wid >> a >> b >> c;
    Rectangle aRect(len, wid);
    Cuboid aCuboid(a, b, c);
    cout << aRect.area() << ' ' << aCuboid.Vol();
}
