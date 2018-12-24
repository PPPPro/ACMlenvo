#include<iostream>
#include<cstring> 
#include<queue>
#include<vector>  
using namespace std;
const int maxn = 1000;
bool map[maxn+10][maxn+10];
bool vst[maxn+10];
int n,m,cnt = 0;
void init(){
	memset(vst,0,sizeof(vst));
	memset(map,0,sizeof(map));
}
void dfs(int x){
	
	for(int i = 1; i <= n; i++){
//		cout << "fo "<< x <<" " <<i<<endl;
		if(map[x][i] && !vst[i]){
//			cout <<"fi"<<x<<" "<< i  << endl;
			vst[i] = true;
			dfs(i);
			
			
		}
	} 
} 
int main(){
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i++){
		int x,y;
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}
/*	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << map[i][j];
		}cout << endl;
	}*/
	for(int i = 1; i <= n; i++){
//		cout<<"out"<<endl;
		if(!vst[i]){
//			cout << "fffffffffffin     "<<i<<endl;
			vst[i] = true;
			cnt++;
			dfs(i);
		}
	}
	cout << cnt-1; 
}
