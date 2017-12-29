#include <stdio.h>
#include <algorithm>
using namespace std;
int Tree[10000];
int post[30];
int in[30];
int N;
int maxx=0;
void Traversal(int root,int start,int end,int index){
	if(start>end){
		return ;
	}
	Tree[index]=post[root];
	if(index>maxx){
		maxx=index;
	}
	int i=start;
	while(i<end&&in[i]!=post[root]) i++;
	Traversal(root-(end-i)-1,start,i-1,2*index);
	Traversal(root-1,i+1,end,2*index+1);
}
int main(){
	fill(Tree,Tree+10000,0);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
    }
    for(int i=0;i<N;i++){
    	scanf("%d",&in[i]);
	}
	Traversal(N-1,0,N-1,1);
	int count=0;
	for(int i=1;i<=maxx;i++){
		if(Tree[i]!=0){
			printf("%d",Tree[i]);
			count++;
	    	if(count!=N){
	    		printf(" ");
	    	}
		}
	}
	return 0;
}
