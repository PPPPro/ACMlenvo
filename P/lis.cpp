#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 20;
int n;
int a[maxn+5];
int maxline[maxn+5];
void dp(){
	for(int i = 2; i <= n; i++){
		
		for(int j = 1; j < i; j++){
			if(a[i] > a[j]){
				if(maxline[i] < maxline[j]){
					maxline[i] = maxline[j] + 1;
				}
			}
		}
	}
}
int mian(){
	memset(maxline,1,sizeof(maxline));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp();
	int tmp = 0;
	for(int i = 1; i <= n; i++){
		if(maxline[i] > tmp){
			tmp = maxline[i];
		}
	}
	return 0;
} 
