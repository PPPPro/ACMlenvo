#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int res = 0;
	int tmp = (a+b)*c;
	if(tmp > res)res = tmp;
	tmp = a*(b+c);
	if(tmp > res)res = tmp;
	tmp = a*b*c;
	if(tmp > res)res = tmp;
	tmp = a+b+c;
	if(tmp > res)res = tmp;
	cout << res;
}
