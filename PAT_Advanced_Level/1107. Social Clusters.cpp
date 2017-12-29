#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <int,int> cnt;
map <int,int> mapp;
vector <int> result;
const int MAXN = 1005;
int pre[MAXN];
int size[MAXN];
bool cmpDec(int a,int b){
	return cnt[a] > cnt[b];
}
int find(int x){
	while(pre[x] != x){
		pre[x] = pre[pre[x]];
		x = pre[x];
	}
	return x;
}
void Union(int x,int y){
	int x_root = find(x);
	int y_root = find(y);
	if(x_root == y_root) return;
	if(size[x_root] > size[y_root]){
		pre[y_root] = x_root;
		size[x_root] += size[y_root];
	}
	else{
		pre[x_root] = y_root;
		size[y_root] += size[x_root];
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		pre[i] = i;
		size[i] = 1;
	}
	for(int i=1;i<=N;i++){
		int num;
		scanf("%d: ",&num);
		for(int j=0;j<num;j++){
			int x;
			scanf("%d",&x);
			if(mapp[x] == 0) mapp[x] = i;
			else Union(mapp[x],i); 
		}
	}
	for(int i=1;i<=N;i++){
		int temp = find(i);
		if(cnt[temp] == 0) result.push_back(temp);
		cnt[temp]++;
	}
	sort(result.begin(),result.end(),cmpDec);
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++){
		printf("%d",cnt[result[i]]);
		if(i!=result.size()-1) printf(" ");
	}
	return 0;
}
