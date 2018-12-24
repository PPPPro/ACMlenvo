#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 100000;
int n,k;
bool vis[maxn]; 
struct Step{
	int x;int steps;
	Step(int xx,int s):x(xx),steps(s){}
};
int mian(){
	cin >> n >> k;
	queue<Step> q;
	memset(vis,false,sizeof(vis));
	q.push(Step(n,0));
	vis[n] = 1;
	while(!q.empty()){
		Step s = q.front();
		if(s.x == k){
			cout << s.steps;
			return 0;
		}
		else{
			if(s.x - 1 >= 0 && !vis[s.x-1]){
				q.push(Step(s.x-1,s.steps+1));
				vis[s.x-1] = true;
			}
			if(s.x +1 <= maxn && !vis[s.x+1]){
				q.push(Step(s.x+1,s.steps+1));
				vis[s.x+1] = true;
			}
			if(s.x *2  <= maxn && !vis[s.x*2]){
				q.push(Step(s.x*2,s.steps+1));
				vis[s.x*2] = true;
			}
			q.pop();
		}
	}
	return 0;
}
