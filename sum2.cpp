#include<iostream>
using namespace std;

int main()
{
				int n;
				float in, out=0;
				cin >> n;
				for(int i=0; i<n; i++)
				{
								cin >> in;
								out += in;
				}
				cout << out;
				return 0;
}
