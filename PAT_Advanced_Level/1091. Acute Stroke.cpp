#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;
int arr[1286][128][60];
bool visit[1286][128][60];
int M,N,L,T;
struct node{
	int x,y,z;
};
int a[6] = {-1,1,0,0,0,0};
int b[6] = {0,0,-1,1,0,0};
int c[6] = {0,0,0,0,-1,1};
bool judge(int x,int y,int z){
	if(x>=N or x <0 or y>=M or y<0 or z>=L or z<0) return false;
	if(not visit[x][y][z] and arr[x][y][z] == 1) return true;
	return false;
}
int bfs(int x,int y,int z){
	queue <node> q;
	struct node root = {
		x,y,z
	};
	q.push(root);
	int cnt = 0;
	while(not q.empty()){
		struct node v = q.front();
		q.pop();
		visit[v.x][v.y][v.z] = true;
		cnt++;
		for(int i=0;i<6;i++){
			if(judge(v.x+a[i],v.y+b[i],v.z+c[i])){
				visit[v.x+a[i]][v.y+b[i]][v.z+c[i]] = true;
				struct node temp={
					v.x+a[i],v.y+b[i],v.z+c[i]
				};
				q.push(temp);
			}
		}
	} 
	return (cnt>=T)?cnt:0;
}
int main(){
	scanf("%d %d %d %d",&M,&N,&L,&T);
	for(int z=0;z<L;z++){
		for(int y=0;y<M;y++){
			for(int x=0;x<N;x++){
				scanf("%d",&arr[x][y][z]);
			}
		}
	}
	int cnt = 0;
	for(int z=0;z<L;z++){
		for(int y=0;y<M;y++){
			for(int x=0;x<N;x++){
				if(not visit[x][y][z] and arr[x][y][z] == 1){
					cnt += bfs(x,y,z);	
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
