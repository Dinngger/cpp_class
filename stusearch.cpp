#define _GLIBCXX_USE_CXX11_ABI 0
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

int numofstus = 7;

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
//    sumgrades();
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

int searchinit(){
    for(int i =0; i<numofstus; i++)
        stus[i][IOTHER] = 1;
    return 0;
}

int* intstring(string s){
    int i = s.find('-');
    int* result = new int[2];
    stringstream _ss;
    _ss << s.substr(0, i);
    _ss >> result[0];
    _ss.clear();
    _ss << s.substr(i+1);
    _ss >> result[1];
    return result;
}

int searchstus(int _m, float low, float high=300){
    for(int i=0; i<numofstus; i++){
        if(stus[i][_m] < low || stus[i][_m] > high)
            stus[i][IOTHER] = 0;
    }
    return 0;
}

int searchid(int low, int high){
    int id;
    stringstream _ss;
    for(int i=0; i<numofstus; i++){
        _ss << stusname[i][IID];
        _ss >> id;
        _ss.clear();
        if(id < low || id > high)
            stus[i][IOTHER] = 0;
    }
    return 0;
}

int searchname(string namehead){
    for(int i=0; i<numofstus; i++){
        string::iterator j = stusname[i][INAME].begin();
        for(string::iterator k = namehead.begin(); k != namehead.end(); ++k){
            if(*k != *j || j == stusname[i][INAME].end()){
                stus[i][IOTHER] = 0;
                break;
            }
            ++j;
        }
    }
    return 0;
}

int searchmain(){
    int sw;
    cin >> sw;
    sumgrades();
    searchinit();
    switch(sw){
        case 1:{
                   string s_classrange;
                   cin >> s_classrange;
                   int* classrange = intstring(s_classrange);
                   searchstus(ICLASS, classrange[0], classrange[1]);
                   break;
               }
        case 2:{
                   string s_idrange;
                   cin >> s_idrange;
                   int* idrange = intstring(s_idrange);
                   searchid(idrange[0], idrange[1]);
                   break;
               }
        case 3:{
                   string s_namehead;
                   cin >> s_namehead;
                   int i = s_namehead.find('*');
                   s_namehead.erase(i);
                   searchname(s_namehead);
                   break;
               }
        case 4:{
                   float lowsum;
                   cin >> lowsum;
                   searchstus(ISUM, lowsum);
                   break;
                }
        case 5:{
                   string s_in, s_idrange;
                   int int_class;
                   cin >> s_in;
                   int i = s_in.find('.');
                   stringstream ss;
                   ss << s_in.substr(0, i);
                   ss >> int_class;
                   searchstus(ICLASS, int_class, int_class);
                   s_idrange = s_in.substr(i+1, s_in.length()-i-1);
                   int* idrange = intstring(s_idrange);
                   searchid(idrange[0], idrange[1]);
                   break;
               }
        default:
               break;
    }
    return 0;
}

int print(){
    stusort();
    cout << fixed;
    bool havefound = false;
    for(int i=0; i<numofstus; i++){
        if(stus[i][IOTHER] == 0)
            continue;
        havefound = true;
        cout.precision(0);
        cout << stusname[i][IID] << " ";
        cout << stus[i][ICLASS] << " ";
        cout << stusname[i][INAME] << " ";
        cout.precision(1);
        for(int j=IGRADE; j<(IGRADE+3); j++){
            cout << stus[i][j];
            if(j != IGRADE+2)
                cout << ' ';
        }
        cout << endl;
    }
    if(havefound == false)
        cout << endl;
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
    searchmain();
    print();
    return 0;
}
