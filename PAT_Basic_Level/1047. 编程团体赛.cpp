#include <stdio.h>
#include <algorithm>
using namespace std;
int num[1005];
int main(){
	fill(num,num+1005,0);
	int n;
	int max=0;
	int max_team_id=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d-%d %d",&a,&b,&c);
		num[a]+=c;
		if(a>max_team_id){
			max_team_id=a;
		}
	}
	int u;
	for(int i=1;i<=max_team_id;i++){
		if(num[i]>max){
			max=num[i];
			u=i;
		}
	}
	printf("%d %d",u,max);
	return 0;
}
