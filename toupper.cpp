#include<iostream>
#include<string>
using namespace std;

string toupper(string s){
    string::iterator b = s.begin();
    string::iterator e = s.end();
    for(; b!=e; b++){
        if(*b >= 'a' && *b <= 'z')
            *b += 'A'-'a';
    }
    return s;
}

int main(){
    string input;
    getline(cin, input);
    cout << toupper(input);
    return 0;
}
