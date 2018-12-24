#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL

struct Node
{
	int L;
	int R;
	int Max;
	int mid(){
		return (L+R)/2;
	}
};
Node tree[800000];
int res=0;
void build(int p,int L,int R){
	tree[p].L = L;
	tree[p].R = R;
	tree[p].Max = 0;
	if(L != R){
		build(p*2+1,L,tree[p].mid());
		build(p*2+2,tree[p].mid()+1,R);
	}
}
void insert(int p,int i,int v){
	if( tree[p].L == tree[p].R ){
		tree[p].Max = v;
		return;
	}
	if(i <= tree[p].mid())
		insert(p*2+1,i,v);
	else
		insert(p*2+2,i,v);

	tree[p].Max = max(tree[p*2+1].Max, tree[p*2+2].Max );
}
void query(int p,int L,int R){
	//	cout << p << ": " << tree[p].L << " " << tree[p].R << " " << tree[p].Max << endl; 
		if(tree[p].L >= L && tree[p].R <= R){
		res = max(tree[p].Max,res);
		return;		
	}
	if(tree[p].mid() >= R){
		query(p*2+1,L,R);
	}else if(tree[p].mid() < L){
		query(p*2+2,L,R);
	}else{
		query(p*2+1,L,tree[p].mid());
		query(p*2+2,tree[p].mid()+1,R);
	}
}
int main(int argc, char * argv[]) 
{
	int n,q;
	cin >> n >> q;
	build(0,1,n);
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		insert(0,i,t);
	}
	  
	for(int i = 1; i <= q; i++){
		char c;
		int a,b;
		//scanf("%c %d %d",&c,&a,&b);
		cin >> c >> a >> b;
		if(c == 'Q')   {
			res = 0;
			query(0,a,b);
			cout << res << endl;
		}else{
			insert(0,a,b);
		}
	}
	// for(int i = 0; i < 4*n; i++){
	//   	cout << i << ": "<< tree[i].L << " " << tree[i].R << " " << tree[i].Max << endl;
	// }cout << endl;
    return 0;
}