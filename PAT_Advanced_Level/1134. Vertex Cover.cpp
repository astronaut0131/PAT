#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map <int,int> mapp;
struct edge{
	int v1;
	int v2;
};
vector <edge> v;
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		struct edge temp;
		scanf("%d %d",&temp.v1,&temp.v2);
		v.push_back(temp);
	}
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<N;j++){
			mapp[j] = 0;
		}
		for(int j=0;j<x;j++){
			int temp;
			scanf("%d",&temp);
			mapp[temp] = 1;
		}
		int flag = 0;
		for(int j=0;j<v.size();j++){
			if (not (mapp[v[j].v1] or mapp[v[j].v2])){
				flag = 1;
				break;
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
