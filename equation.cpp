#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int print(float num)
{
	if (num * 1e6 - int(num * 1e6) == 0)
	{
		cout.unsetf(ios_base::fixed);
		cout << num;
	}
	else
		cout << setprecision(6) << num;
	return 0;
}

int main()
{
	float a, b, c;
	float delta, x1, x2;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		cout << "no root";
	else if (delta == 0)
	{
		x1 = 0 - b / a / 2;
		print(x1);
	}
	else
	{
		x1 = 0 - (b + sqrt(delta)) / a / 2;
		x2 = (sqrt(delta) - b) / a / 2;
		print(x1);
		cout << " ";
		print(x2);
	}
	return 0;
}
