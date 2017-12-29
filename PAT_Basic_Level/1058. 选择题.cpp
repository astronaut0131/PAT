#include <stdio.h>
#include <algorithm>
using namespace std;
struct cnt{
	int pos;
	int count;
};
struct question{
	int score;
	int right_num;
	char answer[5];
};
bool cmpDec(struct cnt a,struct cnt b){
	if(a.count!=b.count){
		return a.count>b.count;
	}
	else{
		return a.pos<b.pos;
	}
}
int main(){//本题关键：scanf中的%d和%c之间一定要有分隔符的主动scanf输入，否则可能接收成空格或者空值 
	int N,M;
	scanf("%d %d",&N,&M);
	struct question a[M];
	int mark[N];
	struct cnt counter[M];
	for(int i=0;i<M;i++){
		counter[i].count=0;
	} 
	fill(mark,mark+N,0);
	for(int i=0;i<M;i++){
		int max_num;
		scanf("%d %d %d",&a[i].score,&max_num,&a[i].right_num);
		for(int j=0;j<a[i].right_num;j++){
			scanf(" %c",&a[i].answer[j]);
		}
	}
	for(int i=0;i<N;i++){
		scanf("\n");
		for(int j=0;j<M;j++){
			if(j!=0){
				scanf(" ");
			}
			int flag=0;
			int num;
			scanf("(%d",&num);
			for(int k=0;k<num;k++){
				char temp;
				scanf(" %c",&temp);
				if(temp!=a[j].answer[k]){
					flag=1;
				}
			}
			if(flag==0){
				mark[i]+=a[j].score;
			}
			else{
				counter[j].count++;
				if(i==0){
					counter[j].pos=j;
				}
			}
			scanf(")");
		}
	}
	sort(counter,counter+M,cmpDec);
	for(int i=0;i<N;i++){
		printf("%d\n",mark[i]);
	}
	if(counter[0].count==0){
		printf("Too simple");
	}
	else{
		printf("%d",counter[0].count);
	    for(int i=0;counter[i].count==counter[0].count;i++){
    		printf(" %d",counter[i].pos+1); 
    	}
	}
	return 0;
}
