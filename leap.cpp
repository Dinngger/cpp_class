#include<iostream>
int main()
{
				using namespace std;
				int year;
				cin >> year;
				if((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0)
								cout << "Y";
				else
								cout << "N";
				return 0;
}
