#include <iostream>
using namespace std;
const int MAX_N = 10010;
int s[4 * MAX_N];
void up(int p){//�ϲ����������ӽڵ������
    s[p] = s[p * 2] + s[p * 2 + 1];
}
void modify(int p, int l, int r, int x, int v){//�޸�������ĳ������ֵ
    //p��l��rΪ��ǰ���µ��Ľڵ㣬���Ҷ˵㣬xΪ��Ҫ�޸ĵ�Ҷ�ӽڵ���˵㣬vΪҪ���ӵ�ֵ
    if(l == r){
        //����ǰ���µ����Ҷ˵���ȼ���Ҷ�ӽ��ʱ��ֱ�Ӹ�����Ϣ������
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
    //p��l��rΪ��ǰ���µ��Ľ�㡢���Ҷ˵㡢x,yΪҪ��ѯ������
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
    cin >> q;//��ѯ
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
