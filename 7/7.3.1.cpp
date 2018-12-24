//增量构造法
#include<cstdio>
#include<iostream>
using namespace std;
void print_subset(int n,int* A,int cur){
	cout << " //cur: " << cur << endl;
	for(int i = 0; i < cur; i++)printf("A[%d]=%d ",i,A[i]);
		printf("\n");
	int s = cur ? A[cur-1]+1 : 0; //确定当前元素最小可能值

	cout << " //s: " << s << endl;
	for(int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n,A,cur+1);
	}
}
int main(){
	int n;
	int A[10];
	cin >> n;
	print_subset(n,A,0);
}