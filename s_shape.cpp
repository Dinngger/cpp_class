#include<iostream>
using namespace std;

int main(){
				int n, i=0, j, m=1, di=1, dj=0;
				cin >> n;
				int **s;
				s = new int*[n];
				for(int a=0; a<n; a++)
								s[a] = new int[n];
				j = n-1;
				while(m < n*n){
								s[i][j] = m;
								i += di;
								j += dj;
								if(i>=n || i<0 || j<0 || j>=n || s[i][j] != 0){
												i -= di;
												j -= dj;
												int w = dj;
												dj = -di;
												di = w;
												i += di;
												j += dj;
								}
								m += 1;
				}
				s[i][j] = n*n;
				for(int a=0; a<n; a++){
								for(int b=0; b<n; b++){
												cout << s[a][b];
												if(b<n-1)
																cout << " ";
												if(b==n-1 && a!= n-1)
																cout << endl;
								}
				}
				delete []s;
				return 0;
}
