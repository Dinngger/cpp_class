#include<iostream>
using namespace std;

class Point{
    friend int calcH(const Point&, const Point&);
    friend int calcV(const Point&, const Point&);
private:
    int x,y;
public:
    Point(int i = 0, int j = 0){
        this->x = i;
        this->y = j;
    }
};

int abs(int a){
    return a<0 ? 0-a:a;
}
int calcH(const Point &a, const Point &b){
    return abs(a.x - b.x);
}
int calcV(const Point &a, const Point &b){
    return abs(a.y - b.y);
}
int main(){
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    Point a(ax, ay), b(bx, by);
    cout << calcH(a, b) << ' ' << calcV(a, b);
    return 0;
}