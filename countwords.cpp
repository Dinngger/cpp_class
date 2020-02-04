#include<iostream>
using namespace std;

bool haveletter(char* str){
    bool result=false;
    for(int i=0; i<20; i++){
        char n = str[i];
        if((n >='A' && n <='Z')||(n >= 'a' && n <= 'z'))
            result = true;
    }
    return result;
}

bool notdone(char* str){
    bool realdone = true;
    if(str[0]=='d' && str[1]=='o' && str[2]=='n' && str[3]=='e')
    {
        realdone = false;
    }
    return realdone;
}

int main(){
    char str[20];
    int counter=0;
    do{
        for(int i=0; i<20; i++)
                        str[i] = 0;
        cin >> str;
        if(haveletter(str))
            counter ++;
    }while(notdone(str));
    cout << "You entered a total of "<<counter-1<<" words." ;
    return 0;
}
