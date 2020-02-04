#include<iostream>
using namespace std;

int main(){
				long seconds;
				long days, hours, mins, secs;
				const int hour=24, min=60, sec=60;
				cin >> seconds;
				mins = seconds/sec;
				secs = seconds%sec;
				hours = mins/min;
				mins = mins%min;
				days = hours/hour;
				hours = hours%hour;
				cout << seconds << " seconds = " << days << " days, "
								<< hours << " hours, " << mins << " minutes, " << secs << " seconds";
				return 0;
}
