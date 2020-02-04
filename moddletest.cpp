#include<iostream>
#include<string>
using namespace std;

void mygetline(std::istream& input, string &p)
{
    char ch1;
    ch1 = cin.peek();
    while (ch1 == '\n' || ch1 == '\r')
    {
        cin.get();
        ch1 = cin.peek();
    }
    getline(input, p);
    if(p[p.length()-1] == '\r'){
        p[p.length()-1] = 0;
        p.resize(p.size()-1);
    }
}

int main(){
    string input;
    for(int i=0; i<4; i++){
        mygetline(cin, input);
        if(!input.empty()){
            cout << input << endl;
            //cin.get();
        }
    }
    return 0;
}
