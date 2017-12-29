#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
struct Link{
	int data;
	int next;
	int addr;
}node[100005];
vector <Link> left_K;
vector <Link> inside_K;
vector <Link> right_K;
vector <Link> total;
int main(){
	int start,N,K;
	scanf("%d %d %d",&start,&N,&K);
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d %d",&node[temp].data,&node[temp].next);
        node[temp].addr = temp;
	}
	for(int i = start;i!=-1;i = node[i].next){
		int temp = node[i].data;
		if(temp < 0){
			left_K.push_back(node[i]);
		}
		else if(temp <= K and temp >= 0){
			inside_K.push_back(node[i]);
		}
		else{
			right_K.push_back(node[i]);
		}
	}
	for(int i=0;i<left_K.size();i++){
		total.push_back(left_K[i]);
	}
	for(int i=0;i<inside_K.size();i++){
		total.push_back(inside_K[i]);
	}
	for(int i=0;i<right_K.size();i++){
		total.push_back(right_K[i]);
	}
	for(int i=0;i<total.size()-1;i++){
		printf("%05d %d %05d\n",total[i].addr,total[i].data,total[i+1].addr);
	}
	printf("%05d %d -1",total[total.size()-1].addr,total[total.size()-1].data);
	return 0;
}
