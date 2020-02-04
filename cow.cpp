#include<iostream>
#include<string>
using namespace std;

char* newstr(const char* str){
    size_t len;
    for(len=0; str[len]; len++);
    char* newstr = new char[len];
    for(size_t i=0; i<len; i++)
        newstr[i] = str[i]=='\r' ? '\0':str[i];
    return newstr;
}

class Cow{
    char name[20];
    char* hobby;
    double weight;
public:
    Cow(){
        hobby = NULL;
    }
    Cow(const char* nm, const char* ho, double wt){
        for(int i=0; i<20; i++){
            if(nm[i]){
                name[i] = nm[i]=='\r' ? '\0':nm[i];
            }
            else
                name[i] = '\0';
        }
        hobby = newstr(ho);
        weight = wt;
    }
    Cow(const Cow& c){
        for(int i=0; i<20; i++)
            name[i] = c.name[i];
        hobby = newstr(c.hobby);
        weight = c.weight;
    }
    ~Cow(){
        if(hobby != NULL){
            delete hobby;
            hobby = NULL;
        }
    }
    Cow& operator=(const Cow& c){
        for(int i=0; i<20; i++)
            name[i] = c.name[i];
        hobby = newstr(c.hobby);
        weight = c.weight;
        return *this;
    }
    void ShowCow() const{
        cout << name << ' ' << hobby << ' ' << weight << endl;
    };
};

int main(){
    string name, hobby, badthing;
    double weight;
    getline(cin, name);
    getline(cin, hobby);
    cin >> weight;
    getline(cin, badthing);
    Cow a(name.c_str(), hobby.c_str(), weight);
    getline(cin, name);
    getline(cin, hobby);
    cin >> weight;
    getline(cin, badthing);
    Cow b(name.c_str(), hobby.c_str(), weight);
    Cow c(a);
    Cow d;
    d = b;
    c.ShowCow();
    d.ShowCow();
    return 0;
}
