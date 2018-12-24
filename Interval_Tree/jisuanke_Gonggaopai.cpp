#include <stdio.h>
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
	int L,R;
	int full;
	int mid(){
		return (L+R)/2;
	}
};
Node tree[800000];
int res = 0;
int h,w,n;
void build(int p,int L,int R){
	tree[p].L = L;
	tree[p].R = R;
	tree[p].full = 0;
	if( L != R){
		build(p*2+1,L,tree[p].mid());
		build(p*2+2,tree[p].mid()+1,R);
	}
}
void insert(int p,int s){
	if(tree[p].L == tree[p].R){
		tree[p].full += s;
		res = tree[p].L;
		return;
	}
	if(w-tree[p*2+1].full >= s){
		insert(p*2+1,s);
	}else if(w-tree[p*2+2].full >= s){
		insert(p*2+2,s);
	}else{
		res = -1;
	}
	tree[p].full = min(tree[p*2+1].full,tree[p*2+2].full);
}
int main(int argc, char * argv[]) 
{
    cin >> h >> w >> n;
    build(0,1,h);
    for(int i = 1; i <= n; i++){
    	res = 0;
    	int t;
    	scanf("%d",&t);
    	insert(0,t);
    	printf("%d\n",res);
    }
    // cout << endl << "begin " << endl;
    // for(int i = 0; i < w*4; i++){
    // 	cout << tree[i].L << " " << tree[i].R << " " << tree[i].full << endl;
    // }
    return 0;
}