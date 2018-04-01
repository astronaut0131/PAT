#include <stdio.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
map <int,vector <int> > edge;
int main(){
	int V,E,K;
	scanf("%d %d %d",&V,&E,&K);
	for(int i=0;i<E;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		map <int,int> color;
		set <int> diff_color;
		for(int j=1;j<=V;j++){
			scanf("%d",&color[j]);
			diff_color.insert(color[j]);
		}
		if(diff_color.size() > K){
			printf("No\n");
			continue;
		}
		bool correct_solution = true;
		for(int j=1;j<=V;j++){
			for(int k=0;k<edge[j].size();k++){
				int vertex = edge[j][k];
				if(color[vertex] == color[j]){
					correct_solution = false;
					break;
				}
			}
			if(not correct_solution)
				break;
		}
		if(correct_solution)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}