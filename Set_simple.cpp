#include<iostream>
#define uint unsigned int
#define MAXSIZE 100
using namespace std;
class Set{
public:
    int* set_array;
    uint size;
    Set(){
        set_array = new int[MAXSIZE];
        for(uint i=0; i<MAXSIZE; i++){
            set_array[i] = 0;
        }
        size = 0;
    }
    int Find(int num){
        int result = -1;
        for(uint i=0; i<size; i++){
            if(set_array[i] == num)
                result = i;
        }
        return result;
    }
    int Add(int num){
        if(Find(num) == -1){
            set_array[size] = num;
            size++;
        }
        return 0;
    }
    int DelId(uint i){
        set_array[i] = set_array[size-1];
        size--;
        set_array[size] = 0;
        return 0;
    }
    int DelNum(int num){
        int i = Find(num);
        if(i != -1){
            DelId(i);
        }
        return i;
    }
    int Check(){
        for(uint i=0; i<size-1; i++){
            for(uint j=i+1; j<size; j++){
                if(set_array[i] == set_array[j])
                    DelId(j);
            }
        }
        return 0;
    }
    Set* Union(Set b){
        Set* unionset = new Set;
        for(uint i=0; i<this->size; i++)
            unionset->Add(this->set_array[i]);
        for(uint i=0; i<b.size; i++)
            unionset->Add(b.set_array[i]);
        return unionset;
    }
    Set* Intersect(Set b){
        Set* intersection = new Set;
        for(uint i=0; i<this->size; i++){
            if(b.Find(this->set_array[i]) != -1)
                intersection->Add(this->set_array[i]);
        }
        return intersection;
    }
    int Print(){
        for(uint i=0; i<size; i++){
            cout << set_array[i];
            if(i != size-1)
                cout << " ";
        }
        cout << endl;
        return 0;
    }
};
Set Input(){
    cout << "Please enter the size\n";
    uint sizea;
    cin >> sizea;
    Set a;
    cout << "Please enter the set\n";
    for(uint i=0; i<sizea; i++){
        int num;
        cin >> num;
        a.Add(num);
    }
    return a;
}
uint Which(){
   cout << "Which set? (0) or (1)\n";
   uint i;
   cin >> i;
   return i;
}
int What(){
   cout << "What number?\n";
   int i;
   cin >> i;
   return i;
}
int main(){
    int op=0;
    Set myset[2];
    cout << "Please enter the first set\n";
    myset[0] = Input();
    cout << "Please enter the second set\n";
    myset[1] = Input();
    while(op!=5){
        cout << "Please enter the number of your operation:\n(0)Print the set\n(1)Add number to a set\n(2)Check if there is a number in a set\n(3)Print the union set\n(4)Print the intersection set\n(5)Quit\n";
        cin >> op;
        switch(op){
            case 0:myset[Which()].Print();break;
            case 1:myset[Which()].Add(What());break;
            case 2:if(myset[Which()].Find(What())!=-1) cout<<"True\n";else cout<<"False\n";break;
            case 3:myset[0].Union(myset[1])->Print();break;
            case 4:myset[0].Intersect(myset[1])->Print();break;
            default:break;
        }
    }
    return 0;
}
