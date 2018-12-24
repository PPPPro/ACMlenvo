#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N];
void up(int p){//合并左右两个子节点的区间
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void modify(int p, int l, int r, int x, int v){//修改区间上某个单点值
    //p、l、r为当前更新到的节点，左右端点，x为需要修改的叶子节点左端点，v为要增加的值
    if(l == r){
        //若当前更新的左右端点相等即到叶子结点时，直接更新信息并返回
    	s[p] += v;//
        return;    
    }
    int mid = (l+r) / 2;
	if(x <= mid){
        modify(p*2, l, mid, x, v);
    }else{
        modify(p*2+1, mid + 1, r, x, v);
    }
    up(p);
}
int query(int p,int l,int r,int x,int y){
    //p、l、r为当前更新到的结点、左右端点、x,y为要查询的区间
    if(x <= l &&r <= y){
        return s[p];
    }
    int mid = (l+r) / 2,res = 0;
    if(x <= mid){
        res += query(p*2, l, mid, x, y);
    }
    if(y > mid){
        res += query(p*2+1, mid + 1, r, x, y);
    }
    return res;
}
int main() {
	int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        modify(1, 1, n, i, d);
    }
    int q;
    cin >> q;//查询
    while(q--){
        int d, x, y;
        cin >> d >> x >> y;
        if(d == 0){
            modify(1,1,n,x,y);
        }else{
            cout << query(1,1,n,x,y) << endl;
        }
    }
    return 0;
}
