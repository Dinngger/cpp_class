#include<iostream>
using namespace std;

int main(){
    const char* mouth[] = {"January", "February", "March", "April", "May",
        "June", "July", "August", "September",
        "October", "November", "December"};
    int i;
    cin >> i;
    cout << mouth[i-1];
    return 0;
}
