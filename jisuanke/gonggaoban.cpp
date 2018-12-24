#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 200000;
int s[maxn];
int h,w,n;
int main(){
	memset(s,0,sizeof(s));
	cin >> h >> w >> n;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t; 
		bool key = 0;
		for(int j = 1; j <= h; j++){
			if(5-s[j] >= t){
				s[j]+=t;
				key = 1;
				cout<<j<<endl;
				break;
			}
		}
		if(!key)cout<<"-1"<<endl;
	}
	return 0;
}
