#include<iostream>
int swap(int &numa, int&numb)
{
				numa += numb;
				numb = numa - numb;
				numa = numa - numb;
				return 0;
}

int compare(int &numa, int &numb)
{
				if(numa > numb)
								swap(numa, numb);
				return 0;
}

int main()
{
				const int i[7] = {0, 1, 2, 3, 2, 1, 0};
				using namespace std;
				int num[5];
				for(int j=0; j<5; j++)
								cin >> num[j];
				for(int j=0; j<7; j++)
								compare(num[i[j]], num[i[j] + 1]);
				cout << num[0] << " " << num[4];
				return 0;
}
