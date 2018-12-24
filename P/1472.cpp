#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string a,b;
int main(){
	while(cin >> a){
		if(a.size() == 1)return 0;
		int k = 1;
		for(int i = a.size()-1; i >= 0; i--){
				if(a[i] == '0' && a[i-1] != '.' && k){
						continue;
				}
				else {
					cout << a[i] ;
					k = 0;
				}
		}cout << endl;
	}
	return 0;
}
