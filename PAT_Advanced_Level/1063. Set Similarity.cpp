#include <stdio.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector< set <int> > v(N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		set<int> s;
		for(int j=0;j<x;j++){
			int temp;
			scanf("%d",&temp);
			s.insert(temp);
		}
		v[i]=s;
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		map <int,int> mapp;
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		int nt=0,nc=v[v2-1].size();
		for(set<int>::iterator j = v[v1-1].begin();j!=v[v1-1].end();j++){
			if(v[v2-1].find(*j)==v[v2-1].end()){
				nc++;
			}
			else{
				nt++;
			}
		}
		printf("%.1f%%\n",nt*1.0/nc*100);
	}
	return 0;
}
