#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#define n 7
#define m 6
#define NUMNAME 2
#define IID 0
#define INAME 1
#define ICLASS 0
#define IGRADE 1
#define ISUM 4
#define IOTHER 5
using namespace std;

string stusname[n][NUMNAME]={
    {"10001","Zhang"},
    {"10002","Yang"},
    {"10003","Liang"},
    {"10004","Cai"},
    {"10005","Fu"},
    {"10006","Mao"},
    {"10007","Zhan"}
};
float stus[n][m]={
    {11,99.5,88.5,89.5,0,0},
    {12,77.9,56.5,87.5,0,0},
    {11,92.5,99.0,60.5,0,0},
    {11,89.6,56.9,90.5,0,0},
    {14,55.6,67.9,98.9,0,0},
    {12,22.1,45.9,99.2,0,0},
    {13,35.6,67.9,88.0,0,0}
};
int numofstus = 0;

int Stuprint(int _i){
    cout << fixed;
    cout.precision(0);
    cout << stusname[_i][IID] << ",";
    cout << stus[_i][ICLASS] << ",";
    cout << stusname[_i][INAME] << ",";
    cout.precision(1);
    for(int j=IGRADE; j<=(IGRADE+3); j++){
        cout << stus[_i][j];
        if(j != IGRADE+3)
            cout << ',';
    }
    cout << endl;
    return 0;
}
int Printall(){
    for(int i=0; i<numofstus; i++)
        Stuprint(i);
    return 0;
}
/**************************************************/
template<typename T>
int Numswap(T &a, T &b){
    T c;
    c = a;
    a = b;
    b = c;
    return 0;
}
int Stuswap(int a, int b){
    for(int i=0; i<m; i++)
        Numswap(stus[a][i], stus[b][i]);
    for(int i=0; i<NUMNAME; i++)
        Numswap(stusname[a][i], stusname[b][i]);
    return 0;
}
int Stusort(){
    for(int i=0; i<numofstus-1; i++){
        for(int j=0; j<numofstus-1-i; j++){
            if(stus[j][ICLASS]>stus[j+1][ICLASS])
                Stuswap(j,j+1);
            else if(stus[j][ICLASS]==stus[j+1][ICLASS] && stus[j][ISUM]<stus[j+1][ISUM])
                Stuswap(j,j+1);
        }
    }
    Printall();
    return 0;
}
/**************************************************/
int Input(){
    cout << "Id ";
    cin >> stusname[numofstus][IID];
    cout << "class ";
    cin >> stus[numofstus][ICLASS];
    cout << "name ";
    cin >> stusname[numofstus][1];
    cout << "score1 ";
    cin >> stus[numofstus][IGRADE];
    cout << "score2 ";
    cin >> stus[numofstus][IGRADE+1];
    cout << "score3 ";
    cin >> stus[numofstus][IGRADE+2];
    return 0;
}
int Sumgrades(){
    for(int i=0; i<numofstus; i++){
        stus[i][ISUM] = stus[i][IGRADE]+stus[i][IGRADE+1]+stus[i][IGRADE+2];
    }
    return 0;
}
int Inserte(){
    Input();
    numofstus ++;
    Sumgrades();
    return 0;
}
/**************************************************/
int Searchinit(){
    for(int i =0; i<numofstus; i++)
        stus[i][IOTHER] = 0;
    return 0;
}
int Searchclass(int _class){
    for(int i=0; i<numofstus; i++){
        if(stus[i][ICLASS] == _class)
            stus[i][IOTHER] = 1;
    }
    return 0;
}
int Searchid(int _id){
    int id;
    stringstream _ss;
    for(int i=0; i<numofstus; i++){
        _ss << stusname[i][IID];
        _ss >> id;
        _ss.clear();
        if(id == _id)
            stus[i][IOTHER] = 1;
    }
    return 0;
}
int Searchmain(){
    int in;
    cin >> in;
    Searchinit();
    Searchid(in);
    Searchclass(in);
    bool havefound = false;
    for(int i=0; i<numofstus; i++){
        if(stus[i][IOTHER]){
            havefound = true;
            break;
        }
    }
    if(!havefound)
        cout << " there is no eligible student \n";
    else{
        for(int i=0; i<numofstus; i++){
            if(stus[i][IOTHER])
                Stuprint(i);
        }
    }
    return 0;
}
/**************************************************/
int Delfind(string name){
    int stu = -1;
    for(int i=0; i<numofstus; i++){
        for(int j=0; j<NUMNAME; j++){
            if(stusname[i][j] == name)
                stu = i;
        }
    }
    return stu;
}
int Studelete(int i){
    Stuswap(i, numofstus-1);
    numofstus --;
    return 0;
}
int Deletemain(){
    string name;
    int ifind;
    cin >> name;
    ifind = Delfind(name);
    if(ifind != -1){
        Studelete(ifind);
        Printall();
    }
    else
        Printall();
    return 0;
}
/**************************************************/
int Interface(){
    cout << "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n";
    int i;
    cin >> i;
    return i;
}
int Domenu(int sw){
    switch(sw){
        case 1:Inserte();break;
        case 2:Deletemain();break;
        case 3:Searchmain();break;
        case 4:Stusort();break;
        case 5:Printall();break;
    }
    return 0;
}
int main(){
    string yes;
    while(1){
        int sw = Interface();
        if(sw == 6)
            break;
        do{
            Domenu(sw);
            if(sw < 4){
                cout << "continue?" << endl;
                cin >> yes;
            }
            else
                yes = "no";
        }while(yes == "yes");
    }
    return 0;
}
