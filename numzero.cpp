#include<iostream>
#define ul unsigned long
using namespace std;

ul zero(ul x){
				ul result;
				if(x < 5)
								result = 0;
				else
								result = x/5 + zero(x/5);
				return result;
}

int main(){
				ul n;
				cin >> n;
				cout << zero(n);
				return 0;
}
