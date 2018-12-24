#include<iostream>
#include<set>
#include<map>
#include<cstring>
using namespace std;
const int maxn = 10005;
bool is_p[maxn];
int n;
void prime(){
	memset(is_p,true,sizeof(is_p));
	/*for(int i = 2; i*i < x; i++){
		if(x%i == 0)return false;
	}
	return true;*/
	for(int i = 2; i*i <= n; i++){
		if(is_p[i]){
			for(int j = i*i; j <= n; j+=i){
				is_p[j] = false;
			}
		}
	}
}
int main(){
	string id[maxn];
	bool vis[maxn];
	memset(vis,true,sizeof(vis));
    int m;
    cin >> n;
	prime();
    for(int i = 1; i <= n; i++){
    	cin >> id[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
    	string search;
    	bool key = false;
    	cin >> search;
    	for(int j= 1; j <= n; j++){
    		if(id[j] == search){
    			key = true;
    			if(!vis[j])cout<<search<<": Checked"<<endl;
    			else if(j == 1){
    				cout <<search<<": Mystery Award"<<endl;
   					vis[j] = false;
    			}
    			else if(is_p[j]){
    				cout <<search<<": Minion"<<endl;
    				vis[j] = false;
    			}
    			else{
    				cout << search<<": Chocolate"<<endl;
    				vis[j] = false;
    			}

    		}
    	}
    	if(!key)cout<<search<<": Are you kidding?"<<endl;
    }

	return 0;
}