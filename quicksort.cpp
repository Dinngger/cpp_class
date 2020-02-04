#include<iostream>
#define n 5
using namespace std;

int main(){
    float grades[n];
    int rank[n];
    for(int i=0; i<n; i++){
        cin >> grades[i];
        rank[i] = i+1;
    }
    for(int i=1; i<n; i++){
        int max=1, min=n;
        for(int j=0; j<i; j++){
            if(grades[i] > grades[j])
                min = min>rank[j] ? rank[j]:min;
            else
                max = max<rank[j] ? rank[j]:max;
        }
        for(int j=0; j<i; j++){
            if(rank[j] >= min)
                rank[j] += 1;
        }
        rank[i] = min==n ? max+1:min;
    }
    for(int i=0; i<n; i++){
        cout << rank[i];
        if(i!=n-1)
            cout << ' ';
    }
    return 0;
}