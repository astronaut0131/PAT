#include <stdio.h>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct node{
	int val;
	int next;
};
map <int,node> link;
map <int,bool> visit;
int main(){
	int head,N;
	vector <int> res;
	vector <int> res_del;
	scanf("%d %d",&head,&N);
	for(int i=0;i<N;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d %d",&link[addr].val,&link[addr].next);
	}
	for(int i=head;i!=-1;i = link[i].next){
		if(not visit[abs(link[i].val)]){
			visit[abs(link[i].val)] = true;
			res.push_back(i);
		}
		else{
			res_del.push_back(i);
		}
	}
	for(int i=0;i<res.size()-1;i++){
		printf("%05d %d %05d\n",res[i],link[res[i]].val,res[i+1]);
	}
	if(res.size()>=1){
		printf("%05d %d -1\n",res[res.size()-1],link[res[res.size()-1]].val);
	}
	for(int i=0;i<res_del.size()-1;i++){
		printf("%05d %d %05d\n",res_del[i],link[res_del[i]].val,res_del[i+1]);
	}
	if(res_del.size()>=1){
		printf("%05d %d -1",res_del[res_del.size()-1],link[res_del[res_del.size()-1]].val);
	}
	return 0;
}
