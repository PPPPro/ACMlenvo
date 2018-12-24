#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxw = 13000;
const int maxn = 3500;
int n,m;
struct item{
	int w,v;
};
item items[maxn];
int dp[maxw];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> items[i].w >> items[i].v;
	}
	for(int j = 0; j <= m; j++){
		if(items[1].w<=j){
			dp[j] = items[1].v;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = m; j >= 0; j--){
			if(items[i].w <= j){
				dp[j] = max(dp[j],dp[j-items[i].w]+items[i].v);
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << dp[i] <<"   ";
	}
} 
