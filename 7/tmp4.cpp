
#include<iostream>
using namespace std;
int main(){
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d,k;
    cin >>y>>m>>d>>k;
    if(d + k <= a[m-1]){
    	printf("%d - %d - %d",y,m,d+k);
    }
    else{
    	k-=(a[m-1])
    	m++;
    	while(true){
    		if(((y%4 == 0 && y%100 != 0) || y%400==0 )&&m==2)m[1] = 29;
    		if(m)
    	}
    }

    return 0;
}