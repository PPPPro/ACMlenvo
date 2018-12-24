#include<iostream> 
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100000;
int size;
struct Point{
	string a;
	string b;
}p[maxn];
bool cmp(Point x,Point y){
	return x.b < y.b;
}
string res;
void bs(int l,int r,string key){
	int mid = l+(r-l)/2;
	cout << "  mid:" << mid << endl;
	if(l >= r){
		if(p[r].b  == key){
			res = p[r].a;
			return;
		}
		else{
			res = "eh";
			return;
		}	
	}
	if(key == p[mid].b){
		res = p[mid].a;
		return;
	}
	else if(key < p[mid].b){ 
//		cout << " s " <<p[mid].b; 
		bs(l,mid,key);
	}
	else if( key > p[mid].b){
//		cout <<key<< " b " <<p[mid].b;
		bs(mid+1,r,key); 
	}
}
int main(){
	int i,mid;
	for(i = 0; i < maxn; i++){
		cin >> p[i].a >> p[i].b;
		cin.get();
		if(cin.peek() == '\n')break;
	}
	size = i;
	sort(p,p+size+1,cmp);
	
	/*for(int i = 0; i <= size; i++){
		cout << p[i].a << " " << p[i].b << endl;
	}*/
	string tmp;
	cout << "size : " << size << endl;
	while(cin >> tmp){
	//	tmp = "eh";
		bs(0,size,tmp);
		cout << res << endl;
	}
	return 0;
} 
