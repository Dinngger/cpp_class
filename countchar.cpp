#include<iostream>
using namespace std;

int main(){
				char str[20];
				for(int i=0; i<20; i++)
								str[i] = 0;
				cin.getline(str, 20);
				int digits=0, letters=0, blank=0;
				for(int i=0; i<20; i++){
								char n = str[i];
								if(n >='0' && n <='9')
												digits += 1;
								else if(n == ' ')
												blank += 1;
								else if((n >='A' && n <='Z')||(n >= 'a' && n <= 'z'))
												letters += 1;
				}
				cout << digits << " " << letters << " " << blank;
				return 0;
}

