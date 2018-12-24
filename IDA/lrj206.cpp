#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	int res = 0;
	if(n < 3)cout << 1;
	else {
		for(int i = 3; i <= n; i++){
			res = (a+b)%10007;
			b = a;
			a = res;
		}
		cout << res;
	}
	
}