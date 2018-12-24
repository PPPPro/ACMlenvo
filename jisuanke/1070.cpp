#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(n == 0)return 0;
		int cnt = 0;
		int a = n/3;
		int b = n%3;
		//	cout << "a " << a <<"b "<<b<<endl; 
		while(true){
		//	cout << "a " << a <<"b "<<b<<endl; 
			cnt += a;
			a += b;
		//	cout << "a " << a <<"b "<<b<<endl<<endl; 
			if( a <= 3){
				if(a == 3){
					cout << ++cnt<<endl;
					break;
				}
				else if(a == 2){
		//			cout<<"+"<<endl;
					cout << ++cnt<<endl;
					
					break;
				}
				else{
				//	cout <<"n"<<endl;
					cout << cnt << endl;
					break;
				}
			}
			b = a%3;
			a/=3;
			
			
		}
	}
	return 0;
} 
