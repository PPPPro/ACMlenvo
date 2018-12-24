#include<iostream>
using namespace std; 
const int maxn = 2000;
int fa[maxn+10];
void init(){
	for(int i = 1; i <= maxn; i++){
		fa[i] = i;
	}
}
int find(int s){
	int cnt = 0; 
	if(fa[s] == s){
		return 0;
//		cout <<s<< endl;
	}
	cnt++;
	cnt += find(fa[s]);
//	cout <<s<<endl;
	return cnt;
}
int main(){
	int n;
	while(cin >> n){
		init(); 
		for(int i = 1; i <= n; i++){
			int a,b;
			cin >> a >> b;
			fa[a] = b;
		}
//		cout <<" ta"<<endl;
		int cnt1 = find(1);
//		cout << " tb"<<endl;
		int cnt2 = find(2);
		cout << cnt1 << endl << cnt2;
	}
	return 0;
} 
