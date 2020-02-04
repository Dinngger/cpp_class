#include<iostream>
#include<iomanip>
#define max 1000
using namespace std;

int main(){
				bool num[max];
				for(int i=0; i<max; i++)
								num[i] = true;
				num[0] = false;
				for(int i=2; i<=max; i++){
								if(num[i-1] == true){
												for(int j=2; i*j<=max; j++)
																num[i*j-1] = false;
								}
				}
				int n;
				cin >> n;
				int *test = new int[n];
				int sum=0;
				for(int i=0; i<n; i++){
								cin >> test[i];
								if(num[test[i]-1] == true)
												sum += test[i];
				}
				cout << sum;
				delete[] test;
				return 0;
}
