#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max = 1010;
struct stu{
    string name;
    int aver;
    int num;
};

bool cmp(stu a,stu b){
    if(a.aver > b.aver){
    	return 1;
    }
	else if(a.aver == b.aver){
		return a.name < b.name;
	}
    else return 0;
}
int main(){
    int n; 
    int m,t;
    while(cin >> n){
    	stu E[Max];
        for(int i = 0; i < n; i++){
            cin >> E[i].name >> E[i].aver >> E[i].num;
        }
        sort(E,E+n,cmp);
        cin >> m >> t;
        for(int i = 0; i < m; i++){
        	if(E[i].num <  t){
        		m++;
        		continue;
        	}
        	else 
            cout << E[i].name;
        	cout << endl;
		}
    }
    return 0;
}
