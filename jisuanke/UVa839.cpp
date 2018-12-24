#include<iostream>
#include<algorithm>
using namespace std;
const int maxn  = 10;

bool input(int &w){
	int w1,w2,d1,d2;
	cin >> w1 >> d1 >> d2 >> w2;
	bool b1 = true,b2 = true;
	if(!w1){
		b1 = input(w1);
	} 
	if(!w2){
		b2 = input(w2);
	}
	w = w1 + w2;
	
	if(b1 && b2 && (w1*d1 == w2*d2)){
		return 1;
	}
}
int main(){
	int w,t;
	cin >> t;
	while(t--){
		if(input(w)){
			cout<<"yes";
		}
		else{
			cout << "no";
		}
		if(t)cout << endl;
	}
	
	return 0;
}
