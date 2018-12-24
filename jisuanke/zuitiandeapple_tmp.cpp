#include<iostream>
using namespace std;
const int maxn = 200000;
int s[maxn];
int n,m;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		int t;
		cin >> t;
		s[i] = t;
	}
	for(int i = 1;i <= m; i++){
		char c;
		int x,y;
		cin >> c >> x >> y;
		if(c == 'Q'){
			int tv = 0;
			for(int i = x; i <= y; i++){
				if(tv <s[i]){
					tv  = s[i];
				}
			}
			cout << tv;
		}
		else if(c == 'U'){
			s[x] = y; 
		}
	}
}
