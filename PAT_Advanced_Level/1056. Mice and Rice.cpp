#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct mouse{
	int index;
	int weight;
	int rank;
	int index_2;
};
bool cmp(mouse A,mouse B){
	return A.index_2 < B.index_2;
}
bool cmp_index(mouse A,mouse B){
	return A.index < B.index;
}
int main(){
	int NP,NG;
	scanf("%d %d",&NP,&NG);
	vector <mouse> mice;
	mice.resize(NP);
	for(int i=0;i<NP;i++){
		mice[i].index = i;
		scanf("%d",&mice[i].weight);
	}
	queue <int> q;
	for(int i=0;i<NP;i++){
		int temp;
		scanf("%d",&temp);
		q.push(temp);
	}
	int cnt = 0;
	int max_weight = -1;
	int max_mouse;
	while(1){
		int temp = q.front();
		if(NP == 1){
			mice[temp].rank = 1;
			break;
		}
		mice[temp].rank = (NP%NG == 0?NP/NG:NP/NG+1)+1;
		q.pop();
		if(mice[temp].weight > max_weight){
			max_weight = mice[temp].weight;
			max_mouse = temp;
		}
		cnt++;
		if(cnt % NG == 0 or cnt == NP){
			q.push(max_mouse);
			max_weight = -1;
			if(cnt == NP){
				NP = NP%NG == 0?NP/NG:NP/NG+1;
				cnt = 0;
			}
		}
	}
	sort(mice.begin(),mice.end(),cmp_index);
	for(int i=0;i<mice.size();i++){
		if(i!=0) printf(" ");
		printf("%d",mice[i].rank);
	}
	return 0;
}
