#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int maxn = 1000000;

typedef int State[9];

State st[maxn],goal;
int dist[maxn]={0};
set<int> vis;//查重集合
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool try_to_insert(int key){
	int v = 0;
	for(int i = 0; i < 9; i++)v = v*10 + st[key][i];
	if(vis.count(v)){
		return 0;
	}
	vis.insert(v);
	return 1;
}
int bfs(){
	int front=1,rear=2;
	vis.clear();

	while(front < rear){
		State& s = st[front];
		if(memcmp(goal, s, sizeof(s)) == 0)return front;

		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break;//寻找'0'的位置
		int x = z/3,y = z%3;//转换成行列编号
		
		for(int i = 0; i < 4; i++){

			int newx = x + dx[i];
			int newy = y + dy[i];
			int newz = newx*3+newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy <3){
				State& t = st[rear];
				memcpy(&t,&s,sizeof(s));
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front]+1;
				if(try_to_insert(rear))rear++;
			}
		}front++;
	}
	return 0;
}


int main(int argc, char * argv[]) 
{
   	for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
	for(int i = 0; i < 9; i++) scanf("%d", &goal[i]);
	int ans = bfs();//返回目标状态的下标
	if(ans > 0)printf("%d\n", dist[ans]);
	else printf("-1\n");
	return 0;
}