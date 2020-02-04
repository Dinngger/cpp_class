#include<iostream>
#include<string>
using namespace std;

class Account{
    string name, number;
    float balance;
public:
    Account(float balance=0){
        this->balance = balance;
    }
    int display(){
        cout << name << number << balance;
        return 0;
    }
    int depositing(float money){
        balance += money;
        return balance;
    }
    int withdrawing(float money){
        int enough=-1;
        if(balance >= money){
            balance -= money;
            enough = balance;
        }
        return enough;
    }
};

int main(){
    float money;
    Account myaccount;
    for(int i=0; i<2; i++){
        cin >> money;
        cout << myaccount.depositing(money) << endl;
    }
    cin >> money;
    float left = myaccount.withdrawing(money);
    if(left>=0)
        cout << left;
    else
        cout << "no enough balance!" << endl;
    return 0;
}
