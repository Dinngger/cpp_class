#include<iostream>
#include<string>
using namespace std;

typedef char strtype[20];

class Person{
    struct infotype{
        strtype IdPerson,
                Name,
                Sex,
                Birthday,
                HomeAddress;
    }info;
public:
    int Print() const{
        const strtype* pinfo = &(this->info.IdPerson);
        for(int i=0; i<5; i++){
            cout << *pinfo;
            if(i != 4)
                cout << ' ';
            pinfo++;
        }
        return 0;
    }
    static infotype Input(strtype in[5]){
        infotype out;
        strtype* pinfo = &(out.IdPerson);
        for(int i=0; i<5; i++){
            for(int j=0; j<20; j++)
                (*pinfo)[j] = in[i][j];
            pinfo++;
        }
        return out;
    }
    Person(){
        static const infotype infoinit = {"610111788664369950", "张三",
            "男", "1992.03.12", "西安交通大学"};
        this->info = infoinit;
    }
    Person(infotype _info){
        this->info = _info;
    }
    Person& operator =(const Person& _person){
        this->info = _person.info;
        return *this;
    }
};

int main(){
    strtype cinput[5]={"",};
    string sinput;
    for(int i=0; i<5; i++){
        cin >> sinput;
        const char* csinput = sinput.c_str();
        for(unsigned int j=0; j<sinput.length(); j++)
            cinput[i][j] = csinput[j];
    }
    Person myperson(Person::Input(cinput));
    myperson.Print();
    return 0;
}
