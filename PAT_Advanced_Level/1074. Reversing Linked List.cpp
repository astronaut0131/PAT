#include <stdio.h>
#include <algorithm>
using namespace std;
struct Link{
	int val;
	int next;
};
Link node[100000];
int main(){
	int head,N,K;	
	scanf("%d %d %d",&head,&N,&K);
	int addr_list[N];
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d %d",&node[temp].val,&node[temp].next);
	}
	int cnt = 0;
	for(int i = head;i != -1;i = node[i].next){
		addr_list[cnt++] = i;
	}
	N = cnt; // 注意 给的节点不一定都在链表上，此乃大坑 
	if(K != 1){
		for(int i=0;i<N/K;i++){
			reverse(addr_list+i*K,addr_list+i*K+K);
		}
	}
    for(int i=0;i<N-1;i++){
    	printf("%05d %d %05d\n",addr_list[i],node[addr_list[i]].val,addr_list[i+1]);
	}
	printf("%05d %d -1",addr_list[N-1],node[addr_list[N-1]].val);
	return 0;
}
