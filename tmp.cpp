//������
/*2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2*/
#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
typedef int State[9];//����״̬����
const int maxstate = 1000000;
State st[maxstate], goal;//״̬���飬���е�״̬������������
int dist[maxstate];//��������

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
//�����б�����������һ�����еı���ͽ��뺯������0~8��ȫ���к�0~262879������һһ��Ӧ����
/*
int vis[362880],fact[9];
void init_lookup_table(){
	fact[0] = 1;
	for(int i = 1; i < 9; i++) fact[i] = fact[i-1] * i;
	for(int i = 1; i < 9; i++) cout << fact[i] << " ";
		cout << endl;
}
int try_to_insert(int s){
	int code = 0;
	for(int i = 0; i < 9; i++){
		int cnt = 0; 
		for(int j = i+1; j < 9; j++) if(st[s][j] <st[s][i]) cnt++;
		code += fact[8-i] * cnt;
	}
	if(vis[code]) return 0;
	return vis[code] = 1;
}*/

const int hashsize = 1000003;
int head[hashsize],next[maxstate];
void init_lookup_table(){memset(head,0,sizeof(head));}

int hash(State& s){
	int v = 0; 
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];
	return v % hashsize;
}

int try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0)return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}
//����Ŀ��״̬��st�����±�
int bfs(){
	init_lookup_table();//��ʼ�����ұ�
	int front = 1,rear = 2;
	while(front < rear){
		State& s = st[front];//ʹ��s����st�����ͷ
		if(memcmp(goal, s, sizeof(s)) == 0) return front;//�Ƚ��Ƿ񵽴�Ŀ��ڵ�

		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break;//Ѱ��'0'��λ��
		int x = z/3,y = z%3;//ת�������б��


		for(int d = 0; d < 4; d++){//���������ƶ�

			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){//���ת�ƺϷ�
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s));//��չ�½ڵ�
				t[newz] = s[z];//����0���������ֵ�λ��
				t[z] = s[newz];
				dist[rear] = dist[front] + 1;//���� �½ڵ����ֵ
				if(try_to_insert(rear)) rear++;//����ɹ�������ұ��޸Ķ�βָ��
			}
		}

		front++;//��չ��Ϻ����޸Ķ���ָ��

	}
	return 0;
}
int main(){
	for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]);
	for(int i = 0; i < 9; i++) scanf("%d", &goal[i]);
	int ans = bfs();//����Ŀ��״̬���±�
	if(ans > 0)printf("%d\n", dist[ans]);
	else printf("-1\n");
	return 0;
}
