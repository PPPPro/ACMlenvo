#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Point{
	int h;
	int c,r;
	bool operator <(const Point & P)const{
		return h < P.h;
	}
}point[110*110];
int map[110][110];
int L[110][110]; 
int R,C;
int main(){
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> map[i][j];
 			point[i*C+j].h = map[i][j];
			point[i*C+j].c = j;
			point[i*C+j].r = i;
		}
	}
	std::sort(point,point+R*C);
//	memset(L,1,sizeof(L));
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			L[i][j] = 1;
		}
	}
	for(int i = 0; i < R*C; i++){
		int tr = point[i].r;
		int tc = point[i].c;
		if(map[tr][tc] < map[tr-1][tc] && tr > 0){
			L[tr-1][tc] = max(L[tr][tc]+1,L[tr-1][tc]);
		}
		if(map[tr][tc] < map[tr+1][tc] && tr < R-1){
			L[tr+1][tc] = max(L[tr][tc]+1,L[tr+1][tc]);
		}
		if(map[tr][tc] < map[tr][tc-1] && tc > 0){
			L[tr][tc-1] = max(L[tr][tc]+1,L[tr][tc-1]);
		}
		if(map[tr][tc] < map[tr][tc+1] && tc < C-1){
			L[tr][tc+1] = max(L[tr][tc]+1,L[tr][tc+1]);
		} 
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cout << L[i][j]<<" "; 
			}cout << endl;
		}cout << endl;
	}
	return 0;
}
/*5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9*/
