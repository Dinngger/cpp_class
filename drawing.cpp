#include<iostream>
using namespace std;

int main(){
				int n;
				cin >> n;
				for(int i=0; i<n; i++){
								for(int k=0; k<n; k++){
												if(k < n-i-1)
																cout << ".";
												else
																cout << "*";
												if(k == n-1)
																cout << endl;
								}
				}
}
