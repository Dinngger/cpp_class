#include<iostream>
#include<string>
using namespace std;

const char table[19][2] = {{'a', 'd'}, {'b', 'w'}, {'c', 'k'},
    {'d', ';'}, {'e', 'i'}, {'f', 'h'},
    {'g', 'm'}, {'h', 'o'}, {'i', 'a'},
    {'j', 'z'}, {'k', 'b'}, {'l', 'n'},
    {'m', 'y'}, {';', 'c'}, {'w', 'e'},
    {'o', 'f'}, {'y', 'g'}, {'z', 'j'},
    {'n', 'l'}};

char trans(char c){
    char r=' ';
    for(int i=0; i<19; i++){
        if(table[i][1] == c)
            r = table[i][0];
    }
    if(r == ' ')
        r = c;
    return r;
}

int main(){
    string input;
    getline(cin, input);
    const char* s = input.c_str();
    for(unsigned int i=0; i<input.length(); i++)
        cout << trans(s[i]);
    return 0;
}
