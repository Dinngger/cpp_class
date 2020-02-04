#include<iostream>
#include<iomanip>
#include<string>
#define n 4
#define m 6
#define NUMNAME 2
#define ICLASS 0
#define IGRADE 1
#define ISUM 4
#define IOTHER 5
using namespace std;

string stusname[n][NUMNAME]={
{"10001","Zhang"},
{"10002","Yang"},
{"10003","Liang"},
};

float stus[n][m]={
{11,99.5,88.5,89.5,0,0},
{12,77.9,56.5,87.5,0,0},
{11,92.5,99.0,60.5,0,0},
{}};

int numofstus = 3;

int sumgrades(){
    for(int i=0; i<numofstus; i++){
        stus[i][ISUM] = stus[i][IGRADE]+stus[i][IGRADE+1]+stus[i][IGRADE+2];
    }
    return 0;
}

template<typename T>
int numswap(T &a, T &b){
				T c;
				c = a;
				a = b;
				b = c;
				return 0;
}

int stuswap(int a, int b){
		for(int i=0; i<m; i++)
						numswap(stus[a][i], stus[b][i]);
		for(int i=0; i<NUMNAME; i++)
						numswap(stusname[a][i], stusname[b][i]);
    return 0;
}

int stusort(){
		sumgrades();
    for(int i=0; i<numofstus-1; i++){
        for(int j=0; j<numofstus-1-i; j++){
            if(stus[j][ICLASS]>stus[j+1][ICLASS])
                stuswap(j,j+1);
            else if(stus[j][ICLASS]==stus[j+1][ICLASS] && stus[j][ISUM]<stus[j+1][ISUM])
                stuswap(j,j+1);
        }
    }
    return 0;
}

int find(string name){
				int stu = -1;
				for(int i=0; i<numofstus; i++){
								for(int j=0; j<NUMNAME; j++){
												if(stusname[i][j] == name)
																stu = i;
								}
				}
				return stu;
}

int input(){
				cin >> stusname[numofstus][0] >> stus[numofstus][ICLASS]
								>> stusname[numofstus][1] >> stus[numofstus][IGRADE]
								>> stus[numofstus][IGRADE+1] >> stus[numofstus][IGRADE+2];
				return 0;
}

int inserte(){
				input();
				numofstus ++;
				return 0;
}

int studelete(int i){
				stuswap(i, numofstus-1);
				numofstus --;
				return 0;
}

int change(){
				input();
				int cfind;
				cfind = find(stusname[numofstus][0]);
				if(cfind != -1){
							stuswap(cfind, numofstus);
							stus[cfind][IOTHER] = 1;
				}
				return 0;
}

int print(){
				stusort();
				cout << fixed;
				for(int i=0; i<numofstus; i++){
								cout.precision(0);
								if(i != 0){
												if(stus[i][ICLASS] == stus[i-1][ICLASS])
																cout << "   ";
												else
																cout << stus[i][ICLASS] << " ";
								}
								else
												cout << stus[i][ICLASS] << " ";
								for(int j=0; j<NUMNAME; j++)
												cout << stusname[i][j] << " ";
								cout.precision(1);
								for(int j=IGRADE; j<(IGRADE+3); j++){
												cout << stus[i][j];
												if(j != IGRADE+2)
																cout << ' ';
								}
								if(stus[i][IOTHER] == 1)
												cout << " modified";
								cout << endl;
				}
				return 0;
}

int deletemain(){
				string name;
				int ifind;
				cin >> name;
				ifind = find(name);
				if(ifind != -1){
						studelete(ifind);
						print();
						cout << "Are you sure(yes/no)?" << endl;
						char input;
						cin >> input;
						if(input == 'n'){
										numofstus ++;
										print();
						}
				}
				else
						print();
				return 0;
}

int main(){
				change();
				print();
				return 0;
}
