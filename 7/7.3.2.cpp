// 位向量法
#include<cstdio>
#include<iostream>
using namespace std;

void print_subset(int n,int* B,int cur){

	if(cur == n){
		for(int i = 0; i < cur; i++)
			if(B[i]) 
				printf("%d ",i);
			else
				printf("  ");
			printf("\n");
			return;
	}

	B[cur] = 1;
	print_subset(n, B, cur+1);
	B[cur] = 0;
	print_subset(n, B, cur+1);
	
}
int main(){
	int B[10];
	print_subset(5,B,0);
}