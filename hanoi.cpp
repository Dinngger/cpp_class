#include<iostream>
using namespace std;

int main(){
    int n, out=1;
    cin >> n;
    for(int i=0; i<n; i++){
        out *= 2;
        while(out > 999999)
            out -= 1000000;
    }
    out -= 1;
    cout << out;
    return 0;
}
