#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
map <int, vector <int> > childs;
map <int,int> special_number; //如果是得到者存储放大倍数，通过判断是不是0来判断是不是得道者，是的话可以得到倍数
map <int,int> level;//记录结点在哪一层
void bfs(float Z,float decrease_percent){
	float cnt = 0;//记录得道者功力总和
	queue <int> Q;
	Q.push(0);
	level[0] = 0;
	while(not Q.empty()){
		int v = Q.front();
		if(special_number[v] != 0){
			cnt += Z*pow(decrease_percent,level[v])*special_number[v]*1.0; 
			printf("编号：%d 得道者功力 %f\n",v,Z*pow(decrease_percent,level[v])*special_number[v]*1.0);
		}
		Q.pop();
		if(childs[v].size()!=0){
			for(int i=0;i<childs[v].size();i++){
				int node = childs[v][i];
				Q.push(node);
				level[node] = level[v] + 1;
			}
		}
	}
	printf("%d",(int)cnt);
}
int main(){
	int N;
	float Z,r;
	scanf("%d %f %f",&N,&Z,&r);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		if(num != 0){
			for(int j=0;j<num;j++){
				int child_num;
				scanf("%d",&child_num);
				childs[i].push_back(child_num);
			}
		}
		else{
			int temp;
			scanf("%d",&temp);
			special_number[i] = temp;
		} 
	}
	bfs(Z,(100.0-r)/100);
	return 0;
}