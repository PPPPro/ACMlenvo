#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100;

int next[maxn];
int n;
void f(char fail[maxn]){
	for(int i = 0; i < n; i++){
		printf("%c",fail[i]);
	}
}
int main(){
	char fail[maxn];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> fail[i];
	}
	memset(fail,-1,sizeof(fail));
	if(1){
		f(fail);
	}
	f(fail);
}
