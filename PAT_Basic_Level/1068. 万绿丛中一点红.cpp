#include <stdio.h>
#include <map>
#include <cmath>
using namespace std;
map <int,int> mapp;
int G[1005][1005];
int TOL;
int M,N;
bool judge(int x,int y){
	int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	for(int i=0;i<8;i++){
		int a=x+dir[i][0];
		int b=y+dir[i][1];
		if(abs(G[a][b]-G[x][y])<=TOL&&a>=0&&a<N&&b>=0&&b<M){
			return false;
		}
	}
	return true;
}
int main(){

	int v1,v2,cnt=0;
	scanf("%d %d %d",&M,&N,&TOL);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&G[i][j]);
			mapp[G[i][j]]++;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(mapp[G[i][j]]==1){
				if(judge(i,j)){
					v1=i;
					v2=j;
					cnt++;
				}
			}
		}
	}
	if(cnt==0){
	    printf("Not Exist");	
	}
	else if(cnt==1){
		printf("(%d, %d): %d",v2+1,v1+1,G[v1][v2]);
	}
	else if(cnt>1){
		printf("Not Unique");
	}
	return 0;
}
