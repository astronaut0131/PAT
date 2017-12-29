#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
map <int,int> mapp;
int left[10],right[10];
int flag=0;
void InOrderTraversal(int root){
	if(right[root]!=-1){
		InOrderTraversal(right[root]);
	}
	if(flag==0){
		printf("%d",root);
	}
	if(flag==1){
		printf(" %d",root);
	}
	flag = 1;
	if(left[root]!=-1){
		InOrderTraversal(left[root]);
	}
}
int main(){
	int N;
	scanf("%d",&N);getchar();
	fill(left,left+10,-1);
	fill(right,right+10,-1);
	for(int i=0;i<N;i++){
		char c1,c2;
		scanf("%c %c",&c1,&c2);
		getchar();
		if(c1!='-'){
			left[i]=c1-'0';
			mapp[c1-'0']++;
		}
		else{
			left[i]=-1;
		}
		if(c2!='-'){
			right[i]=c2-'0';
			mapp[c2-'0']++;
		}
		else{
			right[i]=-1;
		}
	}
	int root;
	for(int i=0;i<N;i++){
		if(mapp[i]==0){
			root=i;
			break;
		}
	}
	queue <int> Q;
	Q.push(root);
	while(!Q.empty()){
		int temp = Q.front();
		if(temp!=root){
			printf(" ");
		}
		printf("%d",temp);
		Q.pop();
		if(right[temp]!=-1){
			Q.push(right[temp]);
		}
		if(left[temp]!=-1){
			Q.push(left[temp]);
		}
	}
	printf("\n");
	InOrderTraversal(root);
	return 0;
}
