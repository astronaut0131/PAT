#include <stdio.h>
#include <algorithm>
using namespace std;
int dis[100005];
bool comp(int a,int b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&dis[i]);
	}
	sort(dis+1,dis+n+1,comp);
	int i;
	for(i=1;i<=n;i++){
		if(!(dis[i]>i)){
			break;
		}
	}
	printf("%d",i-1);
    return 0;
}
