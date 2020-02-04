#include<iostream>
using namespace std;

int y1, y2, a, b, c;

long long f(int n){
    long long result;
    if(n == 1)
        result = y1;
    else if(n == 2)
        result = y2;
    else
        result = a*f(n-2) + b*f(n-1) + c;
    return result;
}

int main(){
    int n;
    cin >> y1 >> y2 >> a >> b >> c >> n;
    long long result = f(n)%1000007;
    if(result < 0)
        result += 1000007;
    cout << result;
    return 0;
}
