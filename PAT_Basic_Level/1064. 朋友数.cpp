#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[100];
int sum[10005];
int result[10005];
int main(){
	fill(sum,sum+10005,0);
	fill(visit,visit+100,false);
	int N;
    int count=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char ch[5];
		scanf("%s",ch);
		for(int j=0;j<strlen(ch);j++){
			sum[i]+=ch[j]-'0';
		}
		if(visit[sum[i]]==false){
			result[count]=sum[i];
			count++;
			visit[sum[i]]=true;
		}
	}
	sort(result,result+count);
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%d",result[i]);
		if(i!=count-1){
			printf(" ");
		}
	}
	return 0;
}
