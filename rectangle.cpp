#include<iostream>
using namespace std;

struct coordinate{
    float x, y;
};

class Rectangle{
    coordinate bottonleft, upright;
    float hight, width;
    public:
    Rectangle(coordinate bl, coordinate ur){
        this->bottonleft = bl;
        this->upright = ur;
        this->width = ur.x - bl.x;
        this->hight = ur.y - bl.y;
    }
    float perimeter(){
        return 2*(this->hight + this->width);
    }
    float area(){
        return this->width*this->hight;
    }
    int print(){
        cout << this->perimeter() << ' ' << this->area();
        return 0;
    }
};
int main(){
    coordinate bl, ur;
    cin >> bl.x >> bl.y >> ur.x >> ur.y;
    Rectangle my_rect(bl, ur);
    my_rect.print();
    return 0;
}
