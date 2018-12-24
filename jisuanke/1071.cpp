#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	string s;
	int cnt  = 0;
	while(getline(cin,s)){
	//	if(cin.eof())break;
		bool key1,key2,key3;
		key1 = key2 = key3 = 0;
		int a = 0,b = 0,c = 0;
		int i = 1;
		int j = 1; 
		int k = 1;
		for(int i = 0; i < s.size(); i++){
			
			if(s[i] == '+' ){
				key1 = 1;
				i++;
			}
			
			else if(s[i] == '-'){
				key3 = 1;
				i++;
			}
			else if(s[i]=='='){
				key2 = 1;
				i++;
			}
		//	cout<<"i:"<<i<<"    "<<a<<" " << b <<" " << c<<endl; 
			if(!key1 && !key3 && !key2){
				if(s[i+1] != '+' && s[i+1] != '-'){
					a = int(s[i]-'0')*10 + int(s[i+1]-'0');
					i++;
				}
				else{
					a = int(s[i]-'0');
				}
			}
			else if((key1 && !key3 && !key2) || (!key1 && key3 && !key2)){
				if(s[i+1] != '='){
					b = int(s[i]-'0')*10 + int(s[i+1]-'0');
					i++;
				}
				else{
					b = int(s[i]-'0');
				}
			}
			else if((key1 && key2) || (key3 && key2)){
				int t = s.size()-i;
				if(t == 1){
					c = int(s[i]-'0');
					break;
				}
				else if(t == 2){
					c = int(s[i] - '0')*10 + int(s[i+1]-'0');
					break;
				}
				else if(t == 3){
					c = 100+int(s[i+1]-'0')*10+(s[i+2]-'0'); 
					break;
				}
			}
			
		}
		cout<<"o:  "<<a<<" " << b <<" " << c<<endl; 
		if(s[i] != '?'){
			if(a + b == c && key1){
				cnt ++;
			}
			else if(a-b==c && key3){
				cnt++;
			}
		}
			
		cout << cnt<<endl;
	}
	cout << cnt<<endl;
	return 0;
}
