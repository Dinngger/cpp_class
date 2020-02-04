#include<iostream>
#define ull unsigned long long
using namespace std;

ull factorial(ull i){
				ull result;
				if(i < 2)
								result = 1;
				else
								result = i*factorial(i-1);
				return result;
}

int main(){
				ull x;
				cin >> x;
				cout << factorial(x);
				return 0;
}
