#include<iostream>
#include<cstring>
using namespace std;

class Stock{
private:
    char* company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){
        total_val = shares * share_val;
    }
public:
    static bool printblank;
    Stock();
    Stock(const char* co, long n=0, double pr=0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    friend ostream& operator<<(ostream &os, const Stock &st);
    const Stock& topval(const Stock &s) const;
};

bool Stock::printblank = true;

Stock::Stock(){
    company = new char[7];
    strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr){
    company = new char[strlen(co)];
    strcpy(company, co);
    if (n < 0){
        cout << "Number of shares can't be negative; "
            << company << " shares set to 0.\n";
            shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock(){
    delete[] company;
}

void Stock::buy(long num, double price){
    if (num < 0){
        cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted.\n";
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    if (num < 0){
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted.\n";
    }
    else if (num > shares){
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

ostream& operator<<(ostream &os, const Stock &st){
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = os.precision(3);

    os << "Company: " << st.company
        << " Shares: " << st.shares << '\n';
    os << "Share Price: $" << st.share_val;

    os.precision(2);
    os << " Total Worth: $" << st.total_val;
    if (Stock::printblank)
        os << ' ';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}

const Stock& Stock::topval(const Stock &s) const{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

const int STKS = 4;
int main(){
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout << "Stock holdings:\n";
    int st;
    for (st=0; st < STKS; st++){
        if (st == STKS-1)
            Stock::printblank = false;
        cout << stocks[st];
    }
    const Stock* top = &stocks[0];
    for (st=1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    
    cout << "\n\nMost valuable holding:\n";
    cout << *top;
    return 0;
}