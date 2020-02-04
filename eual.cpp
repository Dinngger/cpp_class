#include<iostream>
using namespace std;

int main()
{
	int a, b, gcd, lcm;
	cin >> a >> b; //input
	int i, j;
	i=a; j=b;
	while(j != 0)
	{
		if(i > j)
		{
			int c = i;
			i = j;
			j = c;
		}
		j = j%i;
	}
	gcd = i;
	lcm = a*b/i;
	cout << gcd << " " << lcm;	//output
	return 0;
}
