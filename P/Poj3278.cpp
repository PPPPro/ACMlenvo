#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 100000;
int n,k;
int map[maxn];
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int step = q.front();
		q.pop();
		if(step == k){
			cout << map[step];
			return;
		}
		else{
			int tmp = step - 1;
			if(!map[tmp] && tmp >= 0 && tmp <= maxn){
				q.push(tmp);map[tmp] = map[step]+1;
			}
			tmp = step + 1;
			if(!map[tmp] && tmp <= maxn){
				q.push(tmp);map[tmp] = map[step]+1;
			}
			
			tmp = step * 2;
			if(!map[tmp] && tmp <= maxn){
				q.push(tmp);map[tmp] = map[step]+1;
			}
		}
		
	}
}

int main(){
	memset(map,0,sizeof(map));
	cin >> n >> k;
	bfs(n);
	return 0;
}
