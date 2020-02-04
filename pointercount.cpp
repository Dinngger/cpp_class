#include<iostream>
#include<string>
using namespace std;

int main(){
    string s_input;
    getline(cin, s_input);
    const char *input = s_input.c_str();
    int space=0, capital=0, lowercase=0, number=0;
    for(unsigned int i=0; i<s_input.length(); i++){
        if(input[i] == ' ')
            space ++;
        else if(input[i] >= 'A' && input[i] <= 'Z')
            capital ++;
        else if(input[i] >= 'a' && input[i] <= 'z')
            lowercase ++;
        else if(input[i] >= '0' && input[i] <= '9')
            number ++;
    }
    cout << "space: " << space << endl
        << "capital: " << capital << endl
        << "lowercase: " << lowercase << endl
        << "number: " << number << endl;
    return 0;
}
