#include<iostream>
using namespace std;

float nums[10];
float target;
int le=0, ri=9;

int middle(){
				return ((le + ri + 0.5)/2);
}

int search(){
				int result = 1;
				if((ri - le)>2){
								if(nums[middle()] == target){
												result = 0;
												ri = le = middle();
								}
								else if(nums[middle()] > target)
												ri = middle();
								else
												le = middle();
				}
				else{
								if(nums[le] == target){
												ri = le;
												result = 0;
								}
								else if(nums[ri] == target){
												le = ri;
												result = 0;
								}
								else
												result = -1;
				}
				return result;
}

int main(){
				for(int i=0; i<10; i++)
								cin >> nums[i];
				cin >> target;
				while(search() == 1);
				if(ri != le)
								cout << -1;
				else 
								cout << le;
				return 0;
}
