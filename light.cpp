#include<iostream>
using namespace std;

int main(){
				int n, k;
				cin >> n >> k;
				bool light[n];
				for(int i=0; i<n; i++)
								light[i] = true;
				for(int i=2; i<=k; i++){
								for(int j=i-1; j<n; j+=i){
												if(light[j] == true)
																light[j] = false;
												else
																light[j] = true;
								}
				}
				bool black = false;
				for(int i=0; i<n; i++){
								if(light[i] == true){
												if(black == true)
																cout << " ";
												cout << i+1;
												black = true;
								}
				}
				return 0;
}
