#include<iostream>
using namespace std;
int n, r;
int* list;

int out(int _n, int _r){
    if(_r == 1){
        for(int i=_n; i>=1; i--){
            list[r-1] = i;
            for(int j=0; j<r; j++)
                cout << list[j];
            cout << endl;
        }
    }
    else{
        for(int i=_n; i>=_r; i--){
            list[r-_r] = i;
            out(i-1, _r-1);
        }
    }
    return 0;
}

int main(){
    cin >> n >> r;
    list = new int[r];
    out(n, r);
    return 0;
}
