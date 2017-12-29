#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int main(){
	int N;
	scanf("%d",&N);
	v.resize(N+1);
	fill(v.begin(),v.end(),0);
	int total_dis = 0;
	for(int i=2;i<=N;i++){
		int temp;
		scanf("%d",&temp);
		v[i] = temp + total_dis;
		total_dis += temp;
	}
	int last;
	scanf("%d",&last);
	total_dis += last;
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		if(v1>v2) swap(v1,v2);
		int dis = v[v2] - v[v1];
		printf("%d\n",(total_dis - dis>dis)?dis:(total_dis-dis));
	}
	return 0;
}
