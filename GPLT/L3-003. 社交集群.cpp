#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <int,int> pre;
map <int,int> common;
vector <int> result;
map <int,int> cnt;
bool cmp(int A,int B){
	return cnt[A] > cnt[B];
}
int find(int x){
	while(pre[x] != 0){
		x = pre[x];
	}
	return x;
}
void merge(int x,int y){
	int root_x = find(x);
	int root_y = find(y);
	if(root_x == root_y)
		return;
	pre[root_x] = root_y;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int K;
		scanf("%d: ",&K);
		for(int j=0;j<K;j++){
			int x;
			scanf("%d",&x);
			if(common[x] != 0){
				merge(i,common[x]);
			}

			else 
				common[x] = i;
		}
	}
	for(int i=1;i<=N;i++){
		int root = find(i);
		if(cnt[root] == 0)
			result.push_back(root);
		cnt[root]++;
	}
	sort(result.begin(),result.end(),cmp);
	printf("%lu\n",result.size());
	for(int i=0;i<result.size();i++){
		printf("%d%c",cnt[result[i]],i!=result.size()-1?' ':'\0');
	}
	return 0;
}