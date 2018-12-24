#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 20;

	int n;
	
int a[maxn+5];
int maxline[maxn+5] = {1};
void dp(){
	for(int i = 2; i <= n; i++){
		int tmp = 0;
		for(int j = 1; j < i; j++){
			if(a[i] > a[j]){
				if(tmp < maxline[j]){
					tmp = maxline[j];
					cout << "in"<<endl;
				}
			}
		}
		if(tmp!=0)maxline[i] = tmp+1;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)maxline[i] = 1;
	dp();
	for(int i = 1; i <= n; i++)cout << maxline[i];
	cout << endl << endl;
	int tmp = 0;
	for(int i = 1; i <= n; i++){
		if(maxline[i] > tmp){
			tmp = maxline[i];
			
		}
	}
	cout << tmp;
	return 0;
}
