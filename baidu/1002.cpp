#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 1e5+10;
int tree[maxn*4];
void up(int p){
	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
void modify(int p, int l, int r,int x,int v){
	if( l == r){
		tree[p] += v;
		return;
	} 
	int mid = (l+r)/2;
	if( x <= mid){
		modify(p*2, l, mid, x, v);
	}else{
		modify(p*2+1, mid+1, r, x, v);
	}
	up(p);
}
int query(int p,int l,int r,int x,int y){
	if( x <= l && r <= y){
		return tree[p];   
	}
	int mid = (l+r)/2,res = 0;
	if(x <= mid){
		res += query(p*2,l,mid,x,y);
	}
	if(y > mid){
		res += query(p*2+1,mid+1,r,x,y); 
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++){
		int n,q;
		char s[maxn];
		cin >> n >> q;
		int mins = 'Z'+5;
		vector<int> StringPt;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			if(s[i] < mins){
				StringPt.clear();
				mins = s[i];
				StringPt.push_back(i);
			}
			else if(s[i] == mins){
				StringPt.push_back(i);
			}
		}
		
		
		for(int i = 0; i < StringPt.size(); i++){
			modify(1,1,n,StringPt[i],1);
		}
		
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << query(1,1,n,l,r) << endl;
		}
		
	}
	return 0;
} 
