#include <bits/stdc++.h>
using namespace std;
bool test1()
{
    int  a = 4;
    int  b = 3;
    return a||b;
}
bool test2()
{
    bool a = 1;
    bool b = 1;
    return a&&b;
}
int test3() 
{
    int a = 1;
    int b = 2;
    int c = 3;
    return a,b,c;
}
int main()
{
    cout << test1() << endl;//true->1
    cout << test2() << endl;//false->0
    cout << test3() << endl;//3
    return 0;
}