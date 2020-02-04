#include<iostream>
using namespace std;

int main(){
				int a,b,c,n,result=0;
				cin >> a >> b >> c;
				n = c+7;
				while(result == 0){
								if(n%3==a && n%5==b)
												result = n;
								if(n >100)
												result = -1;
								n += 7;
				}
				if(result == -1)
								cout << "No answer";
				else
								cout << result;
				return 0;
}
