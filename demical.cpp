#include <iostream>
#include <sstream>
#include <string>
#define uint unsigned int
using namespace std;

inline int toint(char c) { stringstream ss; ss << c; int a; ss >> a; return a; }
inline char tochar(int i) { stringstream ss; ss << i; char c; ss >> c ; return c; }

class demical
{
  private:
    string num="0";
  public:
    demical() {}
    demical(string s) { num = s; }
    demical(int i) { stringstream ss; ss << i; ss >> num; }
    ~demical() {}
    string get() const { return num; }
    demical operator=(const demical &d) { num = d.num; return *this; }
    friend demical operator+(const demical &a, const demical &b);
    //friend demical operator-(const demical &a, const demical &b);
    //friend demical operator*(const demical &a, const demical &b);
    //friend demical operator/(const demical &a, const demical &b);
};

demical operator+(const demical &da, const demical &db)
{
    bool issort = da.get().length() >= db.get().length();
    string a = issort ? da.get() : db.get();
    string b = issort ? db.get() : da.get();
    string result(a.length(), '0');
    bool up = false;
    for(uint i=0; i<result.length(); i++)
    {
        int plus;
        if(i < b.length())
        {
            plus = toint(a[a.length()-i-1]) + toint(b[b.length()-i-1]) + up;
            if(plus > 9)
            {
                plus -= 10;
                up = true;
            }
            else
                up = false;
        }
        else
            plus = toint(a[a.length()-i-1]) + up;
        result[result.length()-i-1] = tochar(plus);
    }
    if(up)
        result = "1" + result;
    return demical(result);
}

int main()
{
    string input;
    cin >> input;
    demical d1(input);
    cin >> input;
    demical d2(input);
    cout << (d1 + d2).get() << endl;
    return 0;
}
