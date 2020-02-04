#include<iostream>
#include<iomanip>
#define max 1000
using namespace std;

int main(){
				bool num[max];
				int print=0;
				for(int i=0; i<max; i++)
								num[i] = true;
				for(int i=2; i<=max; i++){
								if(num[i-1] == true){
												for(int j=2; i*j<=max; j++)
																num[i*j-1] = false;
												print += 1;
												cout << setw(5) << i;
												if(print == 5){
																cout << endl;
																print = 0;
												}
								}
				}
				return 0;
}
