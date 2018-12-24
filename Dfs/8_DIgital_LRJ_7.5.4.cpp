//八数码
/*2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2*/
#include<iostream>
#include<cstring>
using namespace std;
typedef int State[9];//定义状态类型
const int maxstate = 1000000;
State st[maxstate], goal;//状态数组，所有的状态都保存在这里
int dist[maxstate];//距离数组

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
//把排列变成整数，设计一套排列的编码和解码函数，把0~8的全排列和0~262879的整数一一对应起来
/*
int vis[362880],fact[9];
void init_lookup_table(){
	fact[0] = 1;
	for(int i = 1; i < 9; i++) fact[i] = fact[i-1] * i;
	for(int i = 1; i < 9; i++) cout << fact[i] << " ";
		cout << endl;
}
int try_to_insert(int s){
	int code = 0;
	for(int i = 0; i < 9; i++){
		int cnt = 0; 
		for(int j = i+1; j < 9; j++) if(st[s][j] <st[s][i]) cnt++;
		code += fact[8-i] * cnt;
	}
	if(vis[code]) return 0;
	return vis[code] = 1;
}*/

const int hashsize = 1000003;
int head[hashsize],next[maxstate];
void init_lookup_table(){memset(head,0,sizeof(head));}

int hash(State& s){
	int v = 0; 
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];
	return v % hashsize;
}

int try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0)return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}
//返回目标状态在st数组下标
int bfs(){
	init_lookup_table();//初始化查找表
	int front = 1,rear = 2;
	while(front < rear){
		State& s = st[front];//使用s引用st数组的头
		if(memcmp(goal, s, sizeof(s)) == 0) return front;//比较是否到达目标节点

		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break;//寻找'0'的位置
		int x = z/3,y = z%3;//转换成行列编号

		for(int d = 0; d < 4; d++){//上下左右移动

			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){//如果转移合法
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s));//扩展新节点
				t[newz] = s[z];//交换0和四周数字的位置
				t[z] = s[newz];
				dist[rear] = dist[front] + 1;//更新 新节点距离值
				if(try_to_insert(rear)) rear++;//如果成功插入查找表，修改队尾指针
			}
		}

		front++;//扩展完毕后再修改队首指针

	}
	return 0;
}
int main(){
	for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
	for(int i = 0; i < 9; i++) scanf("%d", &goal[i]);
	int ans = bfs();//返回目标状态的下标
	if(ans > 0)printf("%d\n", dist[ans]);
	else printf("-1\n");
	return 0;
}