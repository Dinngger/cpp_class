#include<iostream>
#include<iomanip>
using namespace std;

int printspace()
{
				for(int i=0; i<30; i++)
								cout << " ";
				return 0;
}

struct idsum
{
				int iid;
				int iclas;
				float isum;
};

int swap(idsum &idsuma,idsum &idsumb)
{
				idsum idsumc;
				idsumc = idsumb;
				idsumb = idsuma;
				idsuma = idsumc;
				return 0;
}

int compare(idsum &idsuma, idsum &idsumb)
{
				if(idsuma.iclas < idsumb.iclas)
								swap(idsuma, idsumb);
				else if(idsuma.iclas == idsumb.iclas)
				{
								if(idsuma.isum > idsumb.isum)
												swap(idsuma, idsumb);
				}
				return 0;
}

class stu
{
				private:
				int id;
				float math, physics, english;
				public:
				static idsum idsums[3];
				static int sort()
				{
								const int i[3] = {0, 1, 0};
								for(int j=0; j<3; j++)
												compare(idsums[i[j]], idsums[i[j] + 1]);
								return 0;
				}

				int clas;
				float sum;
				int stuinit(int _id, int _clas, float _math, float _phy, float _eng)
				{
								id = _id;
								clas = _clas;
								math = _math;
								physics = _phy;
								english = _eng;
								sum = math + physics + english;
								return 0;
				}
				int print(int flag)
				{
								cout.precision(0);
								if(flag < 2)
												cout << clas << ",";
								cout << id;
								cout << fixed;
								cout.precision(1);
								cout << "," << sum;
								if(flag == 1 || flag == 2)
												cout << ";";
								else
												cout << endl;
								return 0;
				}
};

idsum stu::idsums[3] =
{
				{0, 0, 0.0},
				{0, 0, 0.0},
				{0, 0, 0.0}
};
int input();

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
												input();
												break;
/*								case 'o':
												cout << "You are trying to Output info";
												break;*/
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

int input()
{
				cout << "Please input info of the three students:" << endl;
				stu stus[3];
				for(int i=0; i<3; i++)
				{
								int id, clas;
								float math, physice, english;
								cin >> id >> clas >> math >> physice >> english;
								stus[i].stuinit(id, clas, math, physice, english);
								stu::idsums[i] = {i, stus[i].clas, stus[i].sum};
				}
				stu::sort();
				int flags[3];
				for(int i=0; i<3; i++)
								flags[i] = 0;
				if(stu::idsums[0].iclas == stu::idsums[1].iclas)
								flags[0]=1;
				if(stu::idsums[1].iclas == stu::idsums[2].iclas)
								flags[1]=1;
				if(flags[0] == 1 && flags[1] == 0)
								flags[1] = 3;
				if(flags[0] == 0 && flags[1] == 1)
								flags[2] = 3;
				if(flags[0] == 1 && flags[1] == 1)
				{
								flags[1] = 2;
								flags[2] = 3;
				}
				for(int i=0; i<3; i++)
								stus[stu::idsums[i].iid].print(flags[i]);
				return 0;
}
