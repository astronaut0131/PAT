#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map <int,int> mapp;
int Tree[10000];
int Right[25];
int Left[25];
int maxx=0;
void build(int root,int index){
	Tree[index]=root;
	if(index>maxx){
		maxx=index;
	}
	if(Left[root]!=-1){
		build(Left[root],index*2);
	}
	if(Right[root]!=-1){
		build(Right[root],index*2+1);
	}
}
int main(){
	fill(Tree,Tree+10000,-1);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string x,y;
		int a,b;
		cin>>x>>y;
		if(x!="-"){
           int temp = x[0]-'0';
           if(x.length()==2){
           	  temp=temp*10+x[1]-'0';
		   }
		   Left[i]=temp;
		   mapp[temp]=1;
		}
		else{
			Left[i]=-1;
		}
		if(y!="-"){
           int temp = y[0]-'0';
           if(y.length()==2){
           	temp=temp*10+y[1]-'0';
		   }
		   Right[i]=temp;
		   mapp[temp]=1;
		}
		else{
			Right[i]=-1;
		}
	}
	int root;
	for(int i=0;i<N;i++){
		if(mapp[i]==0){
			root=i;
			break;
		}
	}
	build(root,1);
	int flag=0;
	for(int i=1;i<=maxx;i++){
		if(Tree[i]==-1){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("YES %d",Tree[maxx]);
	}
	else{
		printf("NO %d",root);
	}
	return 0;
}
