#include <stdio.h>
#include <algorithm>
using namespace std;
int score[100005];
int main(){
	fill(score,score+100005,0);
	int N;
	int max_index=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int code,mark;
		scanf("%d%d",&code,&mark);
		score[code]+=mark;
		if(code>max_index){
			max_index=code;
		}
	}
	int max=0;
	int u;
	for(int i=1;i<=max_index;i++){
		if(score[i]>max){
			max=score[i];
			u=i;
		}
	}
	printf("%d %d",u,max);
	return 0;
}
