#include<iostream>
using namespace std;
string s[4] = {"fork","bowl","knife","chopsticks"};
int main(){
	int n;
	while(cin >> n){
		for(int i = 0;i < n ; i++){
			string t;
			cin >> t;
			bool key = 0;
			for(int j = 0; j < 4; j++){
				if(t == s[j]){
					key = 1;
					break;
				} 
			}
			if(key){
				cout << t <<" ";
			}
		}
		cout << endl;
	}
} 
