#include <stdio.h>
#include <map>
using namespace std;
map <int,int> mapp;
int main(){
	int N,M;
	int max=0;
	int u;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int x;
			scanf("%d",&x);
			mapp[x]++;
			if(mapp[x]>max){
				max=mapp[x];
				u=x;
			}
		}
	}
	printf("%d",u);
	return 0;
}
