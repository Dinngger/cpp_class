#include<iostream>
using namespace std;

int main(){
    float x, y;
    cin >> x;
    if(x > 0)
        y = x*3 + 1;
    else if(x == 0)
        y = 0;
    else
        y = x*x - 1;
    cout << y;
    return 0;
}
