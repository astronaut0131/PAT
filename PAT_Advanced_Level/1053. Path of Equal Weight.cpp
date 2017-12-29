#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node{
	vector <int> child;
	int weight;
};
int N,M,S;
map <int,node> pointer;
bool cmp(int A,int B){
	return pointer[A].weight > pointer[B].weight;
}
vector <int> path(100);
void dfs(int index,int nodeNum,int sum){
	if(sum > S) return;
	else if(sum == S){
		if(pointer[index].child.size() != 0) return;
		for(int i=0;i<nodeNum;i++){
			printf("%d",path[i]);
			if(i!=nodeNum-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	else{
		if(pointer[index].child.size() == 0) return;
		for(int i=0;i<pointer[index].child.size();i++){
			int temp = pointer[index].child[i];
			path[nodeNum] = pointer[temp].weight;
			dfs(temp,nodeNum+1,sum+pointer[temp].weight);	
		}
	}
}
int main(){
	scanf("%d %d %d",&N,&M,&S);
	struct node nodes[N];
	for(int i=0;i<N;i++){
		scanf("%d",&nodes[i].weight);
		pointer[i] = nodes[i];
	}
	
	for(int i=0;i<M;i++){
		int temp,num;
		scanf("%d %d",&temp,&num);
		pointer[temp].child.resize(num);
		for(int j=0;j<num;j++){
			scanf("%d",&pointer[temp].child[j]);
		}
		sort(pointer[temp].child.begin(),pointer[temp].child.end(),cmp);
	}
	path[0] = pointer[0].weight; 
	dfs(0,1,pointer[0].weight);
	return 0;
}
