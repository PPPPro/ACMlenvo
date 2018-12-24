#include<iostream>
using namespace std;
int main(){
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d,k,tmp;
    cin >>y>>m>>d>>k;
    if(((y % 4 == 0 && y%100!=0)||y%400 == 0)&&m == 2)a[1] = 29;
    if(k + d<=a[m-1]){
            cout<<y<<"-";
            if(m<10)cout<<"0";
            cout<<m<<"-";
            if(d+k<10)cout<<"0";
            cout<<d+k;
            return 0;}
    else{
        k -= (a[m-1] - d);
        m++;
        while(1){
            a[1] = 28;
	
            if(((y % 4 == 0 && y%100!=0)||y%400 == 0)&&m == 2)a[1] = 29;
            if( k > a[m-1]){k -= a[m-1];m= m+1;}
            if(m>12){m = 1;y++;}	
            if(k <= a[m-1]){
                cout<<y<<"-";
                if(m<10)cout<<"0";
                cout<<m<<"-";
                if(k<10)cout<<"0";
                cout<<k;
                return 0;
            }
        }
    }

    return 0;
}