#include<iostream>
using namespace std;

int main(){
				int n;
				float result=0;
				cin >> n;
				float *a = new float[n];
				float *b = new float[n];
				for(int i=0; i<n; i++)
								cin >> a[i];
				for(int i=0; i<n; i++)
								cin >> b[i];
				for(int i=0; i<n; i++)
								result += a[i]*b[i];
				cout << result;
				delete[] a;
				delete[] b;
				return 0;
}
