#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#define LINKFOR for(nope* i=head.next; i!=0; i=i->next)
#define NUMF 6
#define NUMS 2
#define IID 0
#define INAME 1
#define ICLASS 0
#define IGRADE 1
#define ISUM 4
#define IFOUND 5
using namespace std;

template<typename T>
int numSwap(T &a, T &b){
    T c;
    c = a;
    a = b;
    b = c;
    return 0;
}

class Student{
public:
    string stus[NUMS];
    float stuf[NUMF];
    int printFun(){
        cout << fixed;
        cout.precision(0);
        cout << stus[IID] << ",";
        cout << stuf[ICLASS] << ",";
        cout << stus[INAME] << ",";
        cout.precision(1);
        for(int j=IGRADE; j<=(IGRADE+3); j++){
            cout << stuf[j];
            if(j != IGRADE+3)
                cout << ',';
        }
        cout << endl;
        return 0;
    }
};

template<typename T>
class Base{
public:
    struct nope{
        T data;
        nope* next;
    }head;
    int numofnope;
    Base(){
        head.next = 0;
        numofnope = 0;
    }
    nope* linkFindLast(nope* _this){
        nope* i = &head;
        for(; i->next!=_this; i=i->next)
            if(_this != 0 && i->next == 0)
                return 0;
        return i;
    }
    nope* linkNew(){
        nope* i = linkFindLast(0);
        i->next = new nope;
        i->next->next = 0;
        numofnope++;
        return i->next;
    }
    nope* linkNew(nope* a){
        nope* i = linkFindLast(0);
        i->next = a;
        numofnope++;
        return i->next;
    }
    int linkDel(nope* _del){
        numofnope--;
        if(_del != &head){
            linkFindLast(_del)->next = _del->next;
            delete _del;
            return 0;
        }
        else
            return -1;
    }
    int linkSwap(nope* a, nope* b){
        nope* last_of_b = linkFindLast(b);
        linkFindLast(a)->next = b;
        last_of_b->next = a;
        numSwap(a->next, b->next);
        return 0;
    }
    ~Base(){
        while(head.next)
            linkDel(head.next);
    }

/****************************************************************/
    virtual float sortNum(nope* inope)=0;
    int printFun(){
        LINKFOR
            i->data.printFun();
        return 0;
    }
    int sortFun(){
        for(int i=0; i<numofnope-1; i++){
            nope* n = head.next;
            for(int j=0; j<numofnope-1-i; j++){
                if(sortNum(n) > sortNum(n->next))
                    linkSwap(n, n->next);
                n = n->next;
            }
        }
        return 0;
    }

    virtual bool searchMain(int in)=0;
    virtual int stuDelete(string name)=0;
};

class StuClass: public Base<Student>{
    float sortNum(nope* inope){
        return (100 - inope->data.stuf[ISUM]);
    }
public:
    float classid;
    StuClass():Base() {}
    nope* inputFun(){
        nope* i = linkNew();
        cout << "Id ";
        cin >> i->data.stus[IID];
        cout << "class ";
        cin >> i->data.stuf[ICLASS];
        cout << "name ";
        cin >> i->data.stus[INAME];
        cout << "score1 ";
        cin >> i->data.stuf[IGRADE];
        cout << "score2 ";
        cin >> i->data.stuf[IGRADE+1];
        cout << "score3 ";
        cin >> i->data.stuf[IGRADE+2];
        return i;
    }
    int searchInit(){
        LINKFOR
            i->data.stuf[IFOUND] = 0;
        return 0;
    }
    int searchClass(int _class){
        LINKFOR{
            if(i->data.stuf[ICLASS] == _class)
                i->data.stuf[IFOUND] = 1;
        }
        return 0;
    }
    int searchId(int _id){
        int id;
        stringstream _ss;
        LINKFOR{
            _ss << i->data.stus[IID];
            _ss >> id;
            _ss.clear();
            if(id == _id)
                i->data.stuf[IFOUND] = 1;
        }
        return 0;
    }
    bool searchMain(int in){
        searchInit();
        searchId(in);
        searchClass(in);
        bool havefound = false;
        LINKFOR{
            if(i->data.stuf[IFOUND]){
                i->data.printFun();
                havefound = true;
            }
        }
        return havefound;
    }

    nope* Delfind(string name){
        nope* stu = 0;
        LINKFOR{
            for(int j=0; j<NUMS; j++){
                if(i->data.stus[j] == name)
                    stu = i;
            }
        }
        return stu;
    }
    int stuDelete(string name){
        nope* pfind;
        pfind = Delfind(name);
        if(pfind != 0)
            linkDel(pfind);
        return 0;
    }
};

class StuGrade: private Base<StuClass>{
    float sortNum(nope* inope){
        return inope->data.classid;
    }

    StuClass leadin;
    int inputFun(){
        Base<Student>::nope* newstu = leadin.inputFun();
        float _classid = newstu->data.stuf[ICLASS];
        newstu->data.stuf[ISUM] = 0;
        for(int j=0; j<3; j++)
            newstu->data.stuf[ISUM] += newstu->data.stuf[IGRADE+j];
        nope* yourclass;
        bool havefound=false;
        LINKFOR{
            if(i->data.classid == _classid){
                yourclass = i;
                havefound = true;
            }
        }
        if(!havefound){
            yourclass = linkNew();
            yourclass->data.classid = _classid;
        }
        yourclass->data.linkNew(newstu);
        leadin.head.next = 0;
        return 0;
    }

    bool searchMain(int in){
        bool havefound = false;
        LINKFOR{
            if(i->data.searchMain(in))
                havefound = true;
        }
        if(!havefound)
            cout << " there is no eligible student \n";
        return 0;
    }

    int stuDelete(string name){
        LINKFOR
            i->data.stuDelete(name);
        return 0;
    }
    int stuSort(){
        sortFun();
        LINKFOR
            i->data.sortFun();
        return 0;
    }
public:
    int interfaceFun(){
        cout << "1.input\n2.delete\n3.select\n4.order\n5.output\n6.quit\nplease input your option\n";
        int i;
        cin >> i;
        return i;
    }
    int menuFun(int sw){
        switch(sw){
            case 1:inputFun();break;
            case 2:{string name;cin>>name;stuDelete(name);printFun();}break;
            case 3:{int in;cin>>in;searchMain(in);}break;
            case 4:stuSort();printFun();break;
            case 5:printFun();break;
        }
        return 0;
    }
};

int main(){
    string yes;
    StuGrade manager;
    while(1){
        int sw = manager.interfaceFun();
        if(sw == 6)
            break;
        do{
            manager.menuFun(sw);
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
