#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max = 1010;
struct p{
	string s;
	int aver;
	int num;
}E[Max];

bool cmp(p a,p b){
	return a.aver>b.aver;
}

int main(){
	int n;
	int m,t;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> E[i].s >> E[i].aver >> E[i].num;
		}
		cin >> m >> t;
		sort(E,E+n,cmp);
		for(int i = 0; i < m; i++){
			if(E[i].num < t){
				m++;
				continue;
			}
			cout << E[i].s<<endl;
		}
	}
}
