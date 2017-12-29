#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int v_index = 0;
vector <int> tree;
int N;
bool cmpInc(int a,int b){
	return a<b;
} 
void build(int index){
	if(index > N) return;
	build(index<<1);
	tree[index] = v[v_index++];
	build((index<<1)+1);
}
int main(){
	scanf("%d",&N);
	v.resize(N);
	tree.resize(N+1);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end(),cmpInc);
	build(1);
	for(int i=1;i<=N;i++){
		if(i!=1) printf(" ");
		printf("%d",tree[i]);
	}
	return 0;
}
