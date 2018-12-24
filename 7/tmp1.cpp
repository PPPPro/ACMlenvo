#include<cstdio>
#include<queue>
using namespace std;
int main(){
	queue<int> q;
	for(int i = 1; i <= 999; i++){
		q.push(i);
	}
	while(q.size()>1){
		for(int i = 1; i < 4; i++){
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	printf("%d",q.front());
}