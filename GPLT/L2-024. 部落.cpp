#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
map <int,int> pre;
set <int> people;
set <int> units;
int find(int x){
	vector <int> v;
	while(pre[x]!=0){
		v.push_back(x);
		x = pre[x];
	}
	for(int i=0;i<v.size();i++)
		pre[v[i]] = x; 
	return x;
}
void Union(int x,int y){
	int root_x = find(x);
	int root_y = find(y);
	if(root_x == root_y) return;
	pre[root_x] = root_y;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		int parent;
		scanf("%d",&parent);
		people.insert(parent);
		for(int j=1;j<num;j++){
			int x;
			scanf("%d",&x);
			people.insert(x);
			Union(parent,x);
		}
	}
	int Q;
	scanf("%d",&Q);
	int cnt = 0;
	for(set <int>::iterator it=people.begin();it!=people.end();it++){
		if(pre[*it] == 0)
			cnt++;
	}
	printf("%lu %d\n",people.size(),cnt);
	for(int i=0;i<Q;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		if(find(v1) == find(v2))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}