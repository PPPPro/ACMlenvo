#include<iostream>
using namespace std; 
const int maxn = 50000;
int s[maxn * 4];
int n;
int res = 0;
void up(int p){
	s[p] = s[p*2] + s[p*2+1];
}
void modify(int p,int l,int r,int x,int v){
	if(l == r){
		s[p] += v;
		return;
	}
	int mid = (l+r)/2;
	if(x <= mid){
		modify(p*2,l,mid,x,v);
	}
	else{
		modify(p*2+1,mid+1,r,x,v);
	}
	up(p);
}
int query(int p,int l,int r,int x,int y){
	if(x <= l && r <= y){
		return s[p];
	}
	int mid = (r+l)/2,res = 0;
	if(x <= mid){
		res += query(p*2,l,mid,x,y);
	}
	if(y > mid){
		res += query(p*2+1,mid+1,r,x,y);
	}
	return res;
}
int main(){
	cin >>  n;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		modify(1,1,n,i,t);
	}
	string a;
	int x,y;
	while(cin >> a){
		if(a == "End")return 0;
		cin >> x >> y;
		res = 0;
		if(a == "Query"){
			cout << query(1,1,n,x,y) <<endl;
		}
		else if(a == "Add"){
			modify(1,1,n,x,y);
		}
		else if(a == "Sub"){
			y = y*(-1);
			modify(1,1,n,x,y);
		}
	}
	return 0;	
}
