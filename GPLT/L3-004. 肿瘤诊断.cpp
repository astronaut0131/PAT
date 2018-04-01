#include <stdio.h>
#include <queue>
using namespace std;
int matrix[1286][128][60];
bool visit[1286][128][60];
typedef struct position{
	int x,y,z;
} pos;
int M,N,L,T;
bool valid(int x,int y,int z){
	return x>=0 and x<N and y>=0 and y<M and z>=0 and z<L and matrix[x][y][z] == 1;
}
int bfs(int x,int y,int z){
	int _x[] = {-1,1,0,0,0,0};
	int _y[] = {0,0,-1,1,0,0};
	int _z[] = {0,0,0,0,-1,1};
	pos temp={
		x,y,z
	};
	queue <pos> Q;
	Q.push(temp);
	visit[x][y][z] = true;
	int cnt = 0;
	while(not Q.empty()){
		pos v = Q.front();
		Q.pop();
		cnt += 1;
		for(int i=0;i<6;i++){
			int new_x = v.x+_x[i];
			int new_y = v.y+_y[i];
			int new_z = v.z+_z[i];
			if(valid(new_x,new_y,new_z) and not visit[new_x][new_y][new_z]){
				pos temp_pos={
					new_x,new_y,new_z
				};
				Q.push(temp_pos);
				visit[new_x][new_y][new_z] = true;
			}
		}
	}
	if(cnt >= T)
		return cnt;
	else 
		return 0;
}
int main(){
	scanf("%d %d %d %d",&M,&N,&L,&T);
	for(int z=0;z<L;z++){
		for(int y=0;y<M;y++){
			for(int x=0;x<N;x++){
				scanf("%d",&matrix[x][y][z]);
			}
		}
	}
	int cnt = 0;
	for(int z=0;z<L;z++){
		for(int y=0;y<M;y++){
			for(int x=0;x<N;x++){
				if(not visit[x][y][z] and matrix[x][y][z]){
					cnt += bfs(x,y,z);
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}