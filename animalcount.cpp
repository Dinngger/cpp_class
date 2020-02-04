#include<iostream>
#include<string>
using namespace std;

struct animal{
    string name;
    int num;
};

animal* list;
int noflist=0;

int find(string name){
    int id=-1;
    for(int i=0; i<noflist; i++){
        if(name == list[i].name)
            id = i;
    }
    return id;
}

int add(string name){
    int i = find(name);
    if(i != -1)
        list[i].num++;
    else{
        list[noflist].name = name;
        list[noflist].num = 1;
        noflist++;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    list = new animal[n];
    string input;
    for(int i=0; i<n; i++){
        cin >> input;
        add(input);
    }
    animal max=list[0];
    for(int i=1; i<noflist; i++){
        if(list[i].num > max.num)
            max = list[i];
    }
    cout << max.name << ' ' << max.num;
    return 0;
}
