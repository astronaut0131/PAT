#include <stdio.h>
#include <algorithm>
using namespace std;
const int bound = 100000;
struct Node{
	int address;
	int key;
	int next;
	int judge;
};
Node node[bound];
bool exist[bound];
bool cmpInc(Node A,Node B){
	return A.judge<B.judge;
}
int main(){
	for(int i=0;i<bound;i++){
		node[i].judge = 2*bound;
	}
	int start,N,cnt = bound,low_cnt = 0;
	scanf("%d%d",&start,&N);
	for(int i=0;i<N;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d%d",&node[addr].key,&node[addr].next);
		node[addr].address = addr;
	}
	for(int i=start;i!=-1;i = node[i].next){
		if(exist[abs(node[i].key)]==false){
			exist[abs(node[i].key)] = true;
			node[i].judge = low_cnt++;
		}
		else{
			node[i].judge = cnt++;
		}
	}
	sort(node,node+bound,cmpInc);
	int total = low_cnt + cnt -bound;
	for(int i=0;i<total;i++){
		printf("%05d %d ",node[i].address,node[i].key);
		if(i==low_cnt-1 or i==total-1 ){
			printf("-1\n");
		}
		else{
			printf("%05d\n",node[i+1].address);
		}
	}
	return 0;
}
