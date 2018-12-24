#include<iostream>
#include<cstring>
using namespace std;
const int Max = 110;
int n;
struct area{
	int l;
	int h;
}E[Max];
bool map[Max][Max];
int res[Max];
bool is_edge(area a,area b){
	if((a.l < b.l && a.h < b.h) || (a.l < b.h && a.h < b.l))return 1;
	return 0;
} 

int dp(int s){
	int& tmp = res[s];
	if(tmp > 0)return tmp;
	
	tmp = 1;
	
	for(int i = 1; i <= n; i++){
		if(map[s][i])tmp = max(tmp,dp(i)+1);
	}
	
	return tmp;
}

int main(){
	
	while(cin >> n){
		memset(map,false,sizeof(map));
		for(int i = 1; i <= n; i++){
			int ll,hh;
			cin >> ll >> hh;
			E[i].l = ll;
			E[i].h = hh;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j)continue;
				
				if(is_edge(E[i],E[j]))map[i][j] = true;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << map[i][j] << " ";
			}cout << endl;
		}
		memset(res,-1,sizeof(res));
		int MaxRes = 0;
		for(int i = 1; i <= n; i++){
			res[i] = dp(i);
			if(MaxRes < res[i]){
				MaxRes = res[i]; 
			}
		}
		cout << MaxRes;
	}
	return 0;
} 
