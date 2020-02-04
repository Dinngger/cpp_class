#include<iostream>
using namespace std;

int main()
{
				float deg, min, sec, out;
				cin >> deg >> min >> sec;
				out = deg + (min + sec/60)/60;
				cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << out << " degrees";
				return 0;
}
