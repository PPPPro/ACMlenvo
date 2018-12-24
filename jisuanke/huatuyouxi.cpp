#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 16;

int map[maxn][maxn];
struct Point{
	int num;
	
	int mxx;
	int now;
}point[maxn];
int n = 0;
int cnt;
void init(){
	for(int i = 1; i <= n; i++){
		point[i].num = i;
	}
	for(int i = 1; i <= n ;i++){
		 point[i].now = 0;
	}
	memset(map,0,sizeof(map));
	cnt = 0;
}
bool cmp (Point a,Point b){
	return a.mxx > b.mxx;
}
int find(int s){
	for(int i = 1; i <= n ;i++){
		if(s == point[i].num){
			return i;
		}
	}
}
void f(int x){
	int p = point[x].num;
	for(int i = 1; i <= n; i++){
		if(i == p){
			continue;
		}
		if(point[x].now >= point[x].mxx)break;
		
		if(map[p][i] == 0 && point[find(i)].now < point[find(i)].mxx){
			map[p][i] = 1;
			map[i][p] = 1;
			cnt+=2;
			point[x].now++;
			point[find(i)].now++;
		}
	}
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << map[i][j] << " ";
		} 
		cout << endl;
	}*/
} 
int main(){
	
	cin >> n;
	int all = 0;
	init();
	for(int i = 1; i <= n ; i++){
		cin >> point[i].mxx;
		all += point[i].mxx;
	}
	sort(point+1,point+n,cmp);
	for(int i = 1; i <= n; i++){
//		cout << "num"<< i<<": "<<point[i].num<<endl;
		f(i);
	}
/*	if(all != cnt){
		cout <<"None";
		return 0;
	}*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << map[i][j] << " ";
		} 
		cout << endl;
	}
	return 0;
} 
