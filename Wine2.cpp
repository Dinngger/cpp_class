#include <valarray>
#include <iostream>
#include <string>
#include <cstring>
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
    if(p[strlen(p)-1] == '\r')
        p[strlen(p)-1] = 0;
}

template<class T1, class T2>
class Pair
{
  private:
    T1 a;
    T2 b;
  public:
    T1& first();
    T2& second();
    T1 first() const{
        return a;
    }
    T2 second() const{
        return b;
    }
    Pair(const T1 &aval, const T2 &bval) :a(aval), b(bval) {}
    Pair(){}

    template<class T1, class T2>
   // Pair<T1, T2>& operator=(Pair<T1, T2>);
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}

template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

//PairArray::operator=(PairArray(ArrayInt(),ArrayInt()));

class Wine : private PairArray
{
  private:
    string lab;
    int yrs;
  public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    Wine& GetBottles();
    void Show() const;
    string Label() const;
    int sum() const;
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
    lab = l;
    yrs = y;
    first().resize(y);
    second().resize(y);
    for(int i=0; i<y; i++){
        first()[i] = yr[i];
        second()[i] = bot[i];
    }
}

Wine::Wine(const char* l, int y)
{
    lab = l;
    yrs = y;
    first().resize(y, 0);
    second().resize(y, 0);
}

Wine& Wine::GetBottles()
{
    cout << "Enter " << lab << " data for " << yrs << " year(s): \n";
    int input;
    for(int i=0; i<yrs; i++){
        cout << "Enter year: \n";
        cin >> input;
        first()[i] = input;
        cout << "Enter bottles for that year: \n";
        cin >> input;
        second()[i] = input;
    }
    return *this;
}

void Wine::Show() const
{
    cout << "Wine: " << lab << endl;
    cout << "        Year    Bottles\n";
    for(int i=0; i<yrs; i++){
        cout << "        " << first()[i] << "    " << second()[i] << endl;
    }
}

string Wine::Label() const
{
    return lab;
}

int Wine::sum() const
{
    return second().sum();
}

int main(void)
{
    cout << "Enter name of wine: \n";
    char lab[50];
    mygetline(cin, lab, 50);
    cout << "Enter number of years: \n";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};

    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
        << ": " << more.sum() << endl;
    cout << "Bye\n";
    return 0;
}