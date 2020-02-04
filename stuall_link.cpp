#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#define NUMF 6
#define NUMS 2
#define IID 0
#define INAME 1
#define ICLASS 0
#define IGRADE 1
#define ISUM 4
#define IFOUND 5
using namespace std;
/**************************************************/
template<typename T>
int Numswap(T &a, T &b){
    T c;
    c = a;
    a = b;
    b = c;
    return 0;
}
/**************************************************/
struct node{
    string stus[NUMS];
    float stuf[NUMF];
    node* next;
}head;
int Linkinit(){
    head.next = 0;
    return 0;
}
node* Linkfindlast(node* _this){
    node* i = &head;
    for(; i->next!=_this; i=i->next)
        if(_this != 0 && i->next == 0)
            return 0;
    return i;
}
node* Linknew(){
    node* i = Linkfindlast(0);
    i->next = new node;
    i->next->next = 0;
    return i->next;
}
int Linkdel(node* _del){
    if(_del != &head){
        if(_del->next == 0)
            delete _del;
        else{
            Linkfindlast(_del)->next = _del->next;
            delete _del;
        }
        return 0;
    }
    else
        return -1;
}
int Linkswap(node* a, node* b){
    Linkfindlast(a)->next = b;
    Linkfindlast(b)->next = a;
    Numswap(a->next, b->next);
    return 0;
}
/**************************************************/
int numofstus = 0;

int Stuprint(node* i){
    cout << fixed;
    cout.precision(0);
    cout << i->stus[IID] << ",";
    cout << i->stuf[ICLASS] << ",";
    cout << i->stus[INAME] << ",";
    cout.precision(1);
    for(int j=IGRADE; j<=(IGRADE+3); j++){
        cout << i->stuf[j];
        if(j != IGRADE+3)
            cout << ',';
    }
    cout << endl;
    return 0;
}
int Printall(){
    for(node* i=head.next; i!=0; i=i->next)
        Stuprint(i);
    return 0;
}
/**************************************************/
int Stusort(){
    for(int i=0; i<numofstus-1; i++){
        node* n = head.next;
        for(int j=0; j<numofstus-1-i; j++){
            if(n->stuf[ICLASS]>n->next->stuf[ICLASS])
                Linkswap(n, n->next);
            else if(n->stuf[ICLASS]==n->next->stuf[ICLASS] && n->stuf[ISUM]<n->next->stuf[ISUM])
                Linkswap(n, n->next);
            n = n->next;
        }
    }
    Printall();
    return 0;
}
/**************************************************/
node* Input(){
    node* i = Linknew();
    cout << "Id ";
    cin >> i->stus[IID];
    cout << "class ";
    cin >> i->stuf[ICLASS];
    cout << "name ";
    cin >> i->stus[1];
    cout << "score1 ";
    cin >> i->stuf[IGRADE];
    cout << "score2 ";
    cin >> i->stuf[IGRADE+1];
    cout << "score3 ";
    cin >> i->stuf[IGRADE+2];
    return i;
}
int Sumgrades(node* i){
    i->stuf[ISUM] = i->stuf[IGRADE]+i->stuf[IGRADE+1]+i->stuf[IGRADE+2];
    return 0;
}
int Inserte(){
    Sumgrades(Input());
    numofstus++;
    return 0;
}
/**************************************************/
int Searchinit(){
    for(node* i=head.next; i!=0; i=i->next)
        i->stuf[IFOUND] = 0;
    return 0;
}
int Searchclass(int _class){
    for(node* i=head.next; i!=0; i=i->next){
        if(i->stuf[ICLASS] == _class)
            i->stuf[IFOUND] = 1;
    }
    return 0;
}
int Searchid(int _id){
    int id;
    stringstream _ss;
    for(node* i=head.next; i!=0; i=i->next){
        _ss << i->stus[IID];
        _ss >> id;
        _ss.clear();
        if(id == _id)
            i->stuf[IFOUND] = 1;
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
    for(node* i=head.next; i!=0; i=i->next){
        if(i->stuf[IFOUND]){
            havefound = true;
            break;
        }
    }
    if(!havefound)
        cout << " there is no eligible student \n";
    else{
        for(node* i=head.next; i!=0; i=i->next){
            if(i->stuf[IFOUND])
                Stuprint(i);
        }
    }
    return 0;
}
/**************************************************/
node* Delfind(string name){
    node* stu = 0;
    for(node* i=head.next; i!=0; i=i->next){
        for(int j=0; j<NUMS; j++){
            if(i->stus[j] == name)
                stu = i;
        }
    }
    return stu;
}
int Studelete(node* i){
    Linkdel(i);
    numofstus --;
    return 0;
}
int Deletemain(){
    string name;
    node* pfind;
    cin >> name;
    pfind = Delfind(name);
    if(pfind != 0){
        Studelete(pfind);
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
