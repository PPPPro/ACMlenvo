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
int dp[maxn][maxw];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> items[i].w >> items[i].v;
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(items[i].w <= j){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-items[i].w]+items[i].v);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << dp[i][j] <<"   ";
		}cout << endl;
	}
} 
