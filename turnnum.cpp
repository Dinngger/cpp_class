#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
    cin >> input;
    const char* output = input.c_str();
    int n = input.length();
    while(output[n-1] == '0'){
        if(n-1 == 0)
            break;
        n--;
    }
    while(n-1>=0){
        cout << output[n-1];
        n--;
    }
    return 0;
}
