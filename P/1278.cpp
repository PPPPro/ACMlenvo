#include<iostream>
#include<algorithm>
using namespace std;
const int day = 60*60*24;
const int hour = 60*60;
const int minu = 60;
int main(){
	int n;
	while(cin >> n){
		cout << n/day<<" days ";
		n = n%day;
		cout << n/hour <<" hours ";
		n = n%hour;
		cout << n/minu <<" minutes ";
		n = n%minu;
		cout << n << " seconds"<<endl;
	}
}
