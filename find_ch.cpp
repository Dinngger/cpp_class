#include<iostream>
#include<string>
using namespace std;

int main(){
				string str;
				char ch;
				int num = -1;
				getline(cin, str);
				cin.get(ch);
				for(unsigned int i=0; i<str.length(); i++){
								if(str[i] == ch){
												num = i+1;
												break;
								}
				}
				if(num == -1)
								cout << 0;
				else
								cout << num;
				return 0;
}
