#include <iostream>
#include <string.h>
using namespace std;
int Next[1110];
void get_Next(char *p){
    int m = strlen(p);
    Next[0] = Next[1] = 0;
    for(int i = 1; i < m/2; i++){
    	
        int j = Next[i];
        while(j && p[i] != p[j]){
        	cout <<" while and "<< j<<endl; 
            j = Next[j];
        }
        Next[i+1] = p[i] == p[j]? j+1 : 0;
    	
	}
}
int kmp(char *T, char *s){
    int n = strlen(T), m = strlen(s);
    get_Next(s);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && T[i] != s[j]){
            j = Next[j];
        }
        if(s[j] == T[i]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }
    return -1;
}

int main() {
	char s[1100],T[1100];
    cin  >> s;
    for(int i = 0; i < strlen(s); i++){
    	get_Next(s+i);
    }
//    cout << kmp(T,s) << endl;
	for(int i = 0; i <= strlen(s); i++){
		cout << Next[i]<<" ";
	}
    return 0;
}
