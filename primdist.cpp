#include<iostream>
#include<iomanip>
#define uint unsigned int
#define max 1000000
using namespace std;

int main(){
				bool num[max];
				for(uint i=0; i<max; i++)
								num[i] = true;
				num[0] = false;
				for(uint i=2; i<=max; i++){
								if(num[i-1] == true){
												for(uint j=2; i*j<=max; j++)
																num[i*j-1] = false;
								}
				}
				uint m, a, b, dista=0, distb=0;
				cin >> m;
				a = m;
				b = m;
				while(num[a-1] == false){
								a += 1;
								dista += 1;
				}
				while(num[b-1] == false){
								b -= 1;
								distb += 1;
				}
				if(dista < distb)
								cout << a << " " << dista;
				else
								cout << b << " " << distb;
				return 0;
}
