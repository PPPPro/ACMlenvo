//城堡问题
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 50;
int map[maxn][maxn];
int vis[maxn][maxn];
int cnt = 0;
int roomsum = 0,maxroom = 0;
int n,m;
void dfs(int x,int y){
	//可以不用判断数组越界，因为四周都是有墙的
	//if(x < 0 || y < 0 || x >= n || y >= m)
	//	return;
	vis[x][y] = cnt;
	roomsum++;
	if(!(map[x][y] & 1) && !vis[x][y-1]){dfs(x,y-1);}
	if(!(map[x][y] & 2) && !vis[x-1][y]){dfs(x-1,y);}
	if(!(map[x][y] & 4) && !vis[x][y+1]){dfs(x,y+1);}
	if(!(map[x][y] & 8) && !vis[x+1][y]){dfs(x+1,y);}

}
int main(){
	cin >> n >> m;
	memset(vis,false,sizeof(vis));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> map[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j]){
				cnt++;
				roomsum = 0;
				dfs(i,j);
				maxroom = max(roomsum,maxroom);
				/*cout << "xy: " << i << " " << j << endl;
				for(int k = 0; k < n; k++){
					for(int l = 0; l < m; l++){
						cout << vis[k][l] << " ";
					}cout << endl;
				}
				cout << endl;*/
			}
		}
	}
	
	cout << cnt << endl << maxroom << endl;
}