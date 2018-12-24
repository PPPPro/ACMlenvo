#include<iostream>
#include<set>
using namespace std;
set<string> s;
int main(){
	s.insert("bowl");
	s.insert("knife");
	s.insert("fork");
	s.insert("chopsticks");
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			if(s.count(tmp))cout << tmp << " "; 
		}cout << endl;
	}
}
