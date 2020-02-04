#include<iostream>
using namespace std;
int printspace()
{
				for(int i=0; i<30; i++)
								cout << " ";
				return 0;
}
int main()
{
				char in;
				printspace();
				cout << "1.Input" << endl;
				printspace();
				cout << "2.Output" << endl;
				printspace();
				cout << "3.Order" << endl;
				printspace();
				cout << "4.Quit" << endl;
				cin >> in;
				switch(in)
				{
								case 'i':
												cout << "You are trying to Input info";
												break;
								case 'o':
												cout << "You are trying to Output info";
												break;
								case 'm':
												cout << "You are trying to Make things ordered";
												break;
								case 'q':
												cout << "You are about to Quit";
												break;
								default:
												cout << "Wrong input";
				}
				return 0;
}
