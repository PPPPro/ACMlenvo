#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
int Left_max = 0,Right_max = 0;
const int maxn = 10005;
int a[maxn];
bool l[maxn];
bool r[maxn];


int main(int argc, char * argv[]) 
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    l[0] = 1;
    for(int i = 1; i < n; i++){
    	Left_max=max(Left_max,a[i-1]);
    	if(a[i]>Left_max){
    		l[i]=true;
    	}
    }
    r[n-1] = 1;
    for(int i = n-1; i >= 0; i--){
    	Right_max=max(Right_max,a[i+1]);
    	if(a[i]>Right_max){
    		r[i]=true;
    	}
    }
    int res[maxn];
    int t = 0;
    for(int i = 0; i < n; i++){
    	if(l[i]==true&&r[i]==true){
    		res[t++] = a[i];
    	}
    }
    sort(res,res+t);
    for(int i = 0; i < t; i++){
    	cout << res[i] << " ";
    }

    return 0;
}