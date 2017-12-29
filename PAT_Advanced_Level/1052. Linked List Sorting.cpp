#include <stdio.h>
#include <algorithm>
using namespace std;
struct Link{
	int key;
	int next;
}node[100005];
bool cmpKey(int A,int B){
	return node[A].key < node[B].key;
}
int main(){
	int N,head;
	scanf("%d %d",&N,&head);
	int address[N];
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d %d",&node[temp].key,&node[temp].next);
	}
	int cnt = 0;
	for(int i=head;i!=-1;i = node[i].next){
		address[cnt++] = i;
	}
	sort(address,address+cnt,cmpKey);
	if(cnt!=0){
		printf("%d %05d\n",cnt,address[0]);
	}
	else{
		printf("0 -1\n");//注意没有节点的情况 最后一个测试点一分通不过就是这个问题 
	}
	for(int i=0;i<cnt;i++){
		if(i != cnt - 1){
			printf("%05d %d %05d\n",address[i],node[address[i]].key,address[i+1]);
		}
		else{
			printf("%05d %d -1",address[i],node[address[i]].key);
		}
	}
	return 0;
}
