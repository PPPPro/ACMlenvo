#include<iostream>
#include<cstring>
using namespace std;
int Next[1000005];
void get_array(char *s){
	int m = strlen(s);
	for(int i = 1; i < m; i++){
		int j = Next[i];
		while(j && s[i] != s[j]){
			j = Next[j];
		}
		Next[i+1] = s[i] == s[j] ? j+1 : 0;
	}
}
int main(){
	int n;
	cin >> n;
	char s[1000005];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	get_array(s);
	int m = strlen(s);
	cout << m - Next[m];
	return 0;
}