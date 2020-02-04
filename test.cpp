#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
        float grades[3];
            int rank[3];
                for(int i=0; i<3; i++){
                            cin >> grades[i];
                                    rank[i] = i+1;
                                        }
                    for(int i=1; i<3; i++){
                                int max=1, min=3;
                                        for(int j=0; j<i; j++){
                                                        if(grades[i] > grades[j])
                                                                            min = min>rank[j] ? rank[j]:min;
                                                                    else
                                                                                        max = max<rank[j] ? rank[j]:max;
                                                                            }
                                                for(int j=0; j<i; j++){
                                                                if(rank[j] > max)
                                                                                    rank[j] += 1;
                                                                        }
                                                        rank[i] = max;
                                                            }
                        for(int i=0; i<3; i++){
                                    cout << rank[i];
                                            if(i!=2)
                                                            cout << ' ';
                                                }
                            return 0;
}
