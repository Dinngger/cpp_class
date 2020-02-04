#include <iostream>
#include <cstring>
using namespace std;

class Cd
{
  private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

  public:
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd &d);
    Cd(){}
    ~Cd(){}
    virtual void Report() const;
    virtual Cd& operator=(const Cd &d);
};

Cd::Cd(const char* s1, const  char* s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    cout << performers << ','
        << label << ','
        << selections << ','
        << playtime << endl;
}

Cd& Cd::operator=(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

class Classic :public Cd
{
  private:
    char primary_work[80];

  public:
    Classic(const char* s0, const  char* s1, const  char* s2, int n, double x);
    Classic(const Classic &d);
    Classic(){}
    ~Classic(){}
    void Report() const;
    Classic& operator=(const Classic &d);
};

Classic::Classic(const char* s0, const char* s1, const  char* s2, int n, double x) : Cd(s1, s2, n, x)
{
    strcpy(primary_work, s0);
}

Classic::Classic(const Classic &d) : Cd(d)
{
    strcpy(primary_work, d.primary_work);
}

void Classic::Report() const
{
    cout << primary_work << ',';
    Cd::Report();
}

Classic& Classic::operator=(const Classic &d)
{
    strcpy(primary_work, d.primary_work);
    Cd::operator=(d);
    return *this;
}

void Bravo(const Cd &disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    cout << "Using object directly:\n";
            c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

void Bravo(const Cd &disk)
{
    disk.Report();
}