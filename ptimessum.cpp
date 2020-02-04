#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, p;
    long long sum=0;
    cin >> n >> p;
    for(int i=1; i<=n; i++){
        sum += pow(i, p);
    }
    cout << sum;
    return 0;
}
