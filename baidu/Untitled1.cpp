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
struct Node
{
	int L;int R;
	Node *pLeft,*pRight;
	long long nSum;
	long long Inc;
};
Node Tree[200010];
int nCount = 0;
int Mid(Node *pRoot){
	return (pRoot->L + pRoot->R)/2;
}
void BuildTree(Node * pRoot,int L,int R){
	pRoot->L = L;
	pRoot->R = R;
	pRoot->nSum = 0;
	pRoot->Inc = 0;
	if(L == R){
		return;
	}
	nCount++;
	pRoot->pLeft = Tree + nCount;
	nCount++;
	pRoot->pRight = Tree + nCount;
	BuildTree(pRoot->pLeft,L,(L+R)/2);
	BuildTree(pRoot->pRight,(L+R)/2+1,R);
}
void insert(Node * pRoot,int i,int v){
	if(pRoot->L == i && pRoot->R == i){
		pRoot->nSum = v;
		return;	
	}
	pRoot->nSum += v;
	if(i <= Mid(pRoot))
		insert(pRoot->pLeft,i,v);
	else
		insert(pRoot->pRight,i,v);
}
void Add(Node *pRoot,int a,int b,long long c){
	if(pRoot->L == a && pRoot->R == b){
		pRoot->Inc += c;
		return;
	}
	pRoot->nSum += c*(b-a+1);
	if(b <= (pRoot->L + pRoot->R)/2)
		Add(pRoot->pLeft,a,b,c);
	else if(a >= pRoot->L + pRoot->R/2 + 1)
		Add(pRoot->pRight,a,b,c);
	else{
		Add(pRoot->pLeft,a,(pRoot->L,pRoot->R)/2,c);
		Add(pRoot->pRight,(pRoot->L + pRoot->R)/2+1,b,c);
	}
}
long long QuerynSum(Node * pRoot,int a,int b){
	if( pRoot->L == a && pRoot->R == b)
	   return pRoot->nSum + (pRoot->R - pRoot->L + 1) * pRoot->Inc ; 
 
 	pRoot->nSum += (pRoot->R - pRoot->L + 1) * pRoot->Inc ;
 	Add( pRoot->pLeft,pRoot->L,Mid(pRoot),pRoot->Inc);
	Add( pRoot->pRight,Mid(pRoot) + 1,pRoot->R,pRoot->Inc);
    pRoot->Inc = 0; 
 
 	if( b <= Mid(pRoot))
 	    return QuerynSum(pRoot->pLeft,a,b);
    else if( a >= Mid(pRoot) + 1) 
        return QuerynSum(pRoot->pRight,a,b);
    else {   
    	return QuerynSum(pRoot->pLeft,a,Mid(pRoot)) + QuerynSum(pRoot->pRight,Mid(pRoot) + 1,b);
     } 
}
int main(int argc, char * argv[])
{
	int n,q,a,b,c;
	char cmd[10];
	scanf("%d%d",&n,&q);
	int i,j,k;
	nCount = 0;
	BuildTree(Tree,1,n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a);
		insert(Tree,i,a);
	}
	for(int i = 1; i <= 2*n; i++){
		cout << "[L,R]: " << Tree[i].L << " " << Tree[i].R 
		<< " [*L,*R]: " << Tree[i].pLeft << Tree[i].pRight
		<< " nsum,inc: " << Tree[i].nSum << Tree[i].Inc << endl;
	}
	// for(int i = 0; i < q; i++){
	// 	scanf("%s",cmd);
	// 	if(cmd[0] == 'C'){
	// 		scanf("%d%d%d,&a,&b,&c");
	// 		Add(Tree,a,b,c);
	// 	}else{
	// 		scanf("%d%d%d",&a,&b,&c);
	// 		printf("%l64d\n",QuerynSum(Tree,a,b));
	// 	}
	// }
    return 0;
}
