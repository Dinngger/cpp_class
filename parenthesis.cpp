#include<iostream>
#include<string>
using namespace std;

char stack[1000];
unsigned int p=0;
int push(char c){
    stack[p] = c;
    p++;
    return 0;
}
char pop(){
    p--;
    return stack[p];
}
int main(){
    string input;
    getline(cin, input);
    const char* s = input.c_str();
    bool pair = true;
    for(unsigned int i=0; i<input.length(); i++){
        switch(s[i]){
            case '[':push('[');break;
            case '(':push('(');break;
            case ']':if(pop() != '[')
                         pair = false;break;
            case ')':if(pop() != '(')
                         pair = false;break;
        }
        if(!pair)
            break;
    }
    if(!pair)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
