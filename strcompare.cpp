#include<iostream>
#include<string>
using namespace std;

string strcompare(string s_a, string s_b){
    string result = s_b;
    string::iterator a = s_a.begin(), b = s_b.begin(),
        a_end = s_a.end(), b_end = s_b.end();
    for(; a!=a_end && b!=b_end; ++a, ++b){
        if(*a != *b){
            if(*a > *b)
                result = s_a;
            break;
        }
    }
    return result;
}

int main(){
    string str[3];
    for(int i=0; i<3; i++)
        getline(cin, str[i]);
    cout << strcompare(strcompare(str[0], str[1]), str[2]);
    return 0;
}
