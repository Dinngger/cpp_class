#include<iostream>
using namespace std;

int main(){
				float nums[10];
				float a;
				for(int i=0; i<10; i++)
								cin >> nums[i];
				for(int i=9; i>0; i--){
								for(int j=0; j<i; j++){
												if(nums[j] < nums[j+1]){
																a = nums[j+1];
																nums[j+1] = nums[j];
																nums[j] = a;
												}
								}
				}	
				for(int i=0; i<10; i++){
								cout << nums[i];
								if(i < 9)
												cout << " ";
				}
				return 0;
}
