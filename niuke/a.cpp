#include<iostream>
#include<cstring>
using namespace std;
int m[10];
int main(){
	memset(m,0,sizeof(m));
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;	 
	m[a]++;
	m[b]++;
	m[c]++;
	m[d]++;
	m[e]++;
	m[f]++;
	bool k1 = false,k2 = false,k4 = false,k5 = false,k6 = false;
	for(int i = 1; i <= 9; i++){
        if(m[i] == 0){
            continue;
        }
		else if(m[i] == 1){
			k1 = true;
		}
		else if(m[i] == 2)
		{
			k2 = true;
		}
		else if(m[i] == 4){
			k4 = true;
		}
        else if(m[i] == 6){
            k6 = true;
        }
        else if(m[i] == 5){
            k5 = true;
        }
	} 
	if((k4 && k2) || k6){
		cout << "Elephant";
	}
    
	else if((k1 && k4) || k5 ){
		cout << "Bear";
	}else{ 
		cout << "Hernia";
	}
	return 0;
} 
