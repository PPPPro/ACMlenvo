#include<stdio.h>
#define max1 20
#define max2 20
int n,m;
char a[max1],b[max2];
int maxline[max1][max2]={0};
void dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j])
			maxline[i][j]=maxline[i-1][j-1]+1;
			else{
				maxline[i][j]=maxline[i][j-1]>maxline[i-1][j]?maxline[i][j-1]:maxline[i-1][j];
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",a);
	scanf("%s",b);
	for(int i = n-1; i >= 0; i--){
		a[i+1] = a[i];
	}
	for(int i = m-1; i >= 0; i--){
		b[i+1] = b[i];
	}
	dp();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%d",maxline[i][j]);
		
		}
		printf("\n");
	} 
	printf("%d",maxline[n][m]);
	
}
