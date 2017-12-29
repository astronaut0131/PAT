#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map <int,int> mapp;
struct student{
	int ID;
	int mark[4];
	int rank[4];
};
bool cmp1(struct student A,struct student B){
	return A.mark[0]>B.mark[0];
}
bool cmp2(struct student A,struct student B){
	return A.mark[1]>B.mark[1];
}
bool cmp3(struct student A,struct student B){
	return A.mark[2]>B.mark[2];
}
bool cmp4(struct student A,struct student B){
	return A.mark[3]>B.mark[3];
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	struct student s[N];
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&s[i].ID,&s[i].mark[0],&s[i].mark[1],&s[i].mark[2]);
		s[i].mark[3]=(s[i].mark[0]+s[i].mark[1]+s[i].mark[2])/3;
	}
	for(int i=0;i<4;i++){
		if(i==0){
			sort(s,s+N,cmp1);
		}
		else if(i==1){
			sort(s,s+N,cmp2);
		}
		else if(i==2){
			sort(s,s+N,cmp3);
		}
		else{
			sort(s,s+N,cmp4);
		}
		int temp=s[0].mark[i];
		int rank=1;
		s[0].rank[i]=1;
		for(int j=1;j<N;j++){
			if(s[j].mark[i]!=temp){
				temp=s[j].mark[i];
				s[j].rank[i]=j+1;
				rank=j+1;
			}
			else{
				s[j].rank[i]=rank;
			}
		}
	}
	for(int i=0;i<N;i++){
		mapp[s[i].ID]+=i+1;
	}
	for(int i=0;i<M;i++){
		int id;
		scanf("%d",&id);
		if(mapp[id]==0){
			printf("N/A\n");
			continue;
		}
		int minn=999999;
		int u;
		if(s[mapp[id]-1].rank[3]<minn){
			minn=s[mapp[id]-1].rank[3];
			u=3;
		}
		for(int j=0;j<3;j++){
			if(s[mapp[id]-1].rank[j]<minn){
				minn=s[mapp[id]-1].rank[j];
				u=j;
			}
		}
		printf("%d ",minn);
		if(u==0){
			printf("C\n");
		}
		else if(u==1){
			printf("M\n");
		}
		else if(u==2){
			printf("E\n");
		}
		else{
			printf("A\n");
		}
	}
	return 0;
}
