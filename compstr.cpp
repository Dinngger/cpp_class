#include<iostream>
#include<string>
using namespace std;

int max(int a, int b){
				int result;
				if(a > b)
								result = a;
				else
								result = b;
				return result;
}

int main(){
				string dst, src;
				int num=0;
				getline(cin, dst);
				getline(cin, src);
				for(int i=0; i<max(dst.length(), src.length()); i++){
								if(dst[i] != src[i]){
												num = i+1;
												break;
								}
				}
				cout << num;
				return 0;
}
