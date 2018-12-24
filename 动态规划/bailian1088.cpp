#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int map[110][110];
int dp[110][110];
int xx[4] = {1,0,0,-1};
int yy[4] = {0,1,-1,0};
int R,C; 
bool judge(int x,int y){
	for(int i = 0; i < 4; i++)
		if(x+xx[i] > 0 && x+xx[i] <= R && y+yy[i] > 0 && y+yy[i] <= C)
			if(map[x+xx[i]][y+yy[i]] < map[x][y])
				return false;

	return true;
}
void dfs(int x,int y,int cur){
	if(x < 1 || x > R || y < 1 || y > C)
		return;
	if(cur > dp[x][y]){
		dp[x][y] = cur;
	}else{
		return;
	}
	for(int i = 0; i < 4; i++){
		if(map[x+xx[i]][y+yy[i]] > map[x][y] && dp[x+xx[i]][y+yy[i]] < dp[x][y])
			dfs(x+xx[i],y+yy[i],cur+1);
	}
}
int main(){
	cin >> R >> C;
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cin >> map[i][j];
		}       
	}
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			if(judge(i,j)){
				dfs(i,j,1);
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			if(dp[i][j] > res)
				res = dp[i][j];
		}
	}
	cout << res << endl;
	return 0;
}