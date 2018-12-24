#include<iostream>
#include<cstdio>
#include<cmath>
using nam espace std;
int cnt = 0;
struct Point{
	int x,y;
}point[10005];
int main(){
	int k;
	while(cin >> k){
		cnt =0;
		for(int y = k+1; y <=2*k; y++){ 
			if((k*y)%(y-k) == 0){
				point[cnt].x = (k*y)/(y-k);
				point[cnt].y = y;
				cnt++;
			}
	 		
	 	}
	 	for(int i = 0; i < cnt; i++){
	 		printf("1/%d = 1/%d + 1/%d\n",k,point[i].x,point[i].y);
	 	}
	}

 	
	return 0;
}