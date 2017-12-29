#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
queue <int> Q;
int left[105],right[105],Tree[105],arr[105];
int cnt=0;
bool cmpDec(int A,int B){
	return A<B;
}
void InOrderTraversal(int root){
	if(left[root]==-1&&right[root]==-1){
		Tree[root]=arr[cnt++];
		return ;
	}
	if(left[root]!=-1){
		InOrderTraversal(left[root]);
	}
	Tree[root]=arr[cnt++];
	if(right[root]!=-1){
		InOrderTraversal(right[root]);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&left[i],&right[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N,cmpDec);
	InOrderTraversal(0);
	Q.push(0);
	while(!Q.empty()){
		int v=Q.front();
		Q.pop();
		if(v!=0){
			printf(" ");
		}
		printf("%d",Tree[v]);
		if(left[v]!=-1){
			Q.push(left[v]);
		}
		if(right[v]!=-1){
			Q.push(right[v]);
		}
	}
	return 0;
}
