#include<iostream>
using namespace std;

int main(){
    int n, a=1, b=1;
    cin >> n;
    if(n > 2){
        for(int i=1; i<=n-2; i++){
            b += a;
            a = b - a;
        }
    }
    cout << b;
    return 0;
}
