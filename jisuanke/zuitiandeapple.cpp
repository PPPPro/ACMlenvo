#include<iostream>
using namespace std;
const int maxn = 200000;
int s[maxn*4];
int n,m;
void up(int p){
	s[p] = s[p*2]+s[p*2+1];
}
void modify(int p, int l, int r, int x, int v){
	if( l == r ){
		s[p] += v;
		return;
	}
	int mid = (l+r)/2;
	if(x <= mid){
		modify(p*2,l,mid,x,v);
	}
	else if(y > mid){
		modify(p*2+1,mid+1,r,x,v);
	}
	up(p);
} 
int query(int p, int l, int r, int x, int y){
	if(x >= l && y <= l){
		res += s[p];
		return res;
	}
	int mid = (l+r)/2;
	if(x <= mid){
		res += query(p*2, l, mid, x, y);
	}
	if(y > mid){
		res += query(p*2+1, mid, r, x, y);
	}
	return res;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i <= n; i++){
		int t;
		cin >> t;
		modify(1,1,n,i,t);
	}
	for(int i = 1; i <= m; i++){
		int x,y;
		char c;
		cin >> c >> x >> y;
		if(c == 'Q'){
			
		}
		else if(c == 'U'){
			
		}
	}
	return 0;
} 
