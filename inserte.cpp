#include<iostream>
#include<iomanip>
#define n 4
#define m 7
using namespace std;

//id, class, 3 grades, sum, other
float stus[n][m]={
{10001,11,99.5,88.5,89.5,0,0},
{10002,12,77.9,56.5,87.5,0,0},
{10003,11,92.5,99.0,60.5,0,0},
{}};

int sumgrades(){
    for(int i=0; i<n; i++){
        stus[i][5] = stus[i][2]+stus[i][3]+stus[i][4];
    }
    return 0;
}

int numswap(float &a, float &b){
				b += a;
				a = b - a;
				b -= a;
				return 0;
}

int stuswap(int a, int b){
		for(int i=0; i<m; i++){
						numswap(stus[a][i], stus[b][i]);
		}
    return 0;
}

int stusort(){
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            if(stus[j][1]>stus[j+1][1])
                stuswap(j,j+1);
            else if(stus[j][1]==stus[j+1][1] && stus[j][5]<stus[j+1][5])
                stuswap(j,j+1);
        }
    }
    return 0;
}

int inserte(){
    float newstu[m];
		for(int i=0; i<5; i++)
						cin >>newstu[i];
		for(int i=0; i<n-1; i++)
						if(stus[i][0] == newstu[0])
										newstu[0] = 10000;
		newstu[6] = 1;
		for(int i=0; i<m; i++)
						stus[n-1][i] = newstu[i];
		return 0;
}

int print(){
				cout << fixed;
				for(int i=0; i<n; i++){
								for(int j=0; j<5; j++){
												if(j==0)
																cout.precision(0);
												if(j==2)
																cout.precision(1);
												cout << stus[i][j];
												if(j<4)
																cout << ' ';
								}
								if(stus[i][6] == 1)
												cout << " inserted";
								cout << endl;
				}
				return 0;
}

int main(){
		inserte();
		sumgrades();
		stusort();
		print();
		return 0;
}
