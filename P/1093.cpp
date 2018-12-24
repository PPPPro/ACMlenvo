#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int max_n = 1010;
vector< vector<int> > map(max_n);
int n;
int indegree[max_n];
int res[max_n];

void topu(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!indegree[i]){
			q.push(i);
			res[i] = 1;	
		} 
	}
	while(!q.empty()){
		int point = q.front();
		q.pop();
		for(int i = 0; i < map[point].size(); i++){
			int tmp = map[point][i];
			indegree[tmp]--;
			res[tmp] = res[point]+1;
			if(!indegree[tmp]){
				q.push(tmp);
			}
		}
	}
}

int main(){
	while(cin >> n){	
	//	memset(indegree,0,sizeof(indegree));
		for(int i = 1; i <= n; i++)indegree[i] = 0;
		memset(res,0,sizeof(res));
		n++;
		for(int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			map[v].push_back(u);
			indegree[u]++;
		}
	
		topu();
	
		if(res[1] > res[2])cout << "You are my elder"<<endl;
		else if(res[1] < res[2])cout << "You are my younger"<<endl;
		else if(res[1] == res[2])cout << "You are my brother"<<endl;
	
	}
	return 0;
}
