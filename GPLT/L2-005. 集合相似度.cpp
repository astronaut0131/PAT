#include <stdio.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
map <int, map <int,int> > exist;
int main(){
	int N;
	scanf("%d",&N);
	set <int> s[N];
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int temp;
			scanf("%d",&temp);
			s[i].insert(temp);
			exist[i][temp] = 1;
		}
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		set <int> common;
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		v1-=1;
		v2-=1;
		int size1 = s[v1].size();
		int size2 = s[v2].size();
		if(s[v1].size() < s[v2].size()){
			for(set <int>::iterator it = s[v1].begin();it != s[v1].end();it++){
				if(exist[v2][*it]){
					common.insert(*it);
					size1--;
				}
			}	
		}
		else{
			for(set <int>::iterator it = s[v2].begin();it != s[v2].end();it++){
				if(exist[v1][*it]){
					common.insert(*it);
					size2--;
				}
			}	
		}
		printf("%.2f%%\n",common.size()*1.0/(size1+size2)*100);
	}
	return 0;
}