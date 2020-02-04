#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

void mygetline(std::istream& input,char *p,int len)
{
    char ch1;
    ch1 = cin.peek();
    while (ch1 == '\n' || ch1 == '\r')
    {
        cin.get();
        ch1 = cin.peek();
    }
    cin.getline(p,len);
    if(p[strlen(p)-1] == '\r'){
        p[strlen(p)-1] = 0;
        p.resize(p.size()-1);
    }
}

class String{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIN = 80;
public:
    String(const char* s);
    String();
    String(const String&);
    ~String();
    int length() const{return len;}

    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int i);
    const char& operator[](int i) const;
    String& stringlow();
    String& stringup();
    int has(char c) const;

    friend String& operator+(const String &st1, const String &st2);
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream& operator<<(ostream &os, const String &st);
    friend istream& operator>>(istream &is, String &st);

    static int HowMany();
};

int String::num_strings = 0;

int String::HowMany(){
    return num_strings;
}

String::String(const char* s){
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st){
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String(){
    --num_strings;
    delete[] str;
}

String& String::operator=(const String &st){
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String& String::operator=(const char* s){
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char& String::operator[](int i){
    return str[i];
}

const char& String::operator[](int i) const{
    return str[i];
}

bool operator<(const String &st1, const String &st2){
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2){
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2){
    return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream &os, const String &st){
    os << st.str;
    return os;
}

istream& operator>>(istream &is, String &st){
    char temp[String::CINLIN];
    mygetline(is, temp, String::CINLIN);
    st = temp;
    return is;
}

String& operator+(const String &st1, const String &st2){
    char* plus = new char[st1.len + st2.len];
    for(int i=0; i<(st1.len+st2.len); i++){
        if(i<st1.len)
            plus[i] = st1[i];
        else
            plus[i] = st2[i-st1.len];
    }
    String* stplus = new String(plus);
    return *stplus;
}

String& String::stringlow(){
    for(int i=0; i<len; i++){
        str[i] = tolower(str[i]);
    }
    return *this;
}

String& String::stringup(){
    for(int i=0; i<len; i++){
        str[i] = toupper(str[i]);
    }
    return *this;
}

int String::has(char c) const{
    int times=0;
    for(int i=0; i<len; i++){
        if(str[i] == c)
            times++;
    }
    return times;
}

int main(){
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name:\n";
    String s3;
    cout << s2;              // overloaded << operator
    cin >> s3;               // overloaded >> operator
    s2 = "My name is " + s3; // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase
    cout << "The string " << s2 << "\ncontains " << s2.has('A')
         << " 'A' characters in it.\n";
    s1 = "red"; // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light:\n";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}