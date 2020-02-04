#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Move{
    double x, y;
public:
    Move(double x=0, double y=0){
        this->x = x;
        this->y = y;
    }
    int showmove() const;
    Move add(const Move& m);
    int reset(double x=0, double y=0){
        this->x = x;
        this->y = y;
        return 0;
    }
};

int Move::showmove() const{
    cout << x << ',' << y << endl;
    return 0;
}
Move Move::add(const Move& m){
    this->x += m.x;
    this->y += m.y;
    return *this;
}

int main(){
    Move mymove;
    mymove.showmove();
    double x, y;
    string input;
    cin >> input;
    size_t pos = input.find(',');
    size_t size = input.size();
    stringstream ss;
    ss << input.substr(0, pos);
    ss >> x;
    ss.clear();
    ss << input.substr(pos+1, size);
    ss >> y;
    Move yourmove(x, y);
    yourmove.showmove();
    mymove.add(yourmove).showmove();
    yourmove.reset();
    yourmove.showmove();
    return 0;
}
