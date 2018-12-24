#include<iostream>
#include<cstring>
using namespace std;
const int max_n = 1010;
const int max_m = 100010;
//bool map[max_n][max_n];
int n,m;
int vst[max_n];
/*void insert(int u,int v){
	map[u][v] = true;
	map[v][u] = true;
}*/
int main(){
	memset(vst,0,sizeof(vst));
//	memset(map,false,sizeof(map));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		//insert(u,v);
		vst[u]++;
		vst[v]++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(vst[i]%2 != 0)cnt++;
	}
	if(cnt % 2 != 0)cout << "0";
	else cout << "1";
}
