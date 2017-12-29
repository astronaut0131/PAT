#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct stu{
	int ID;
	char name[10];
	int grade;
};
bool cmp1(struct stu A,struct stu B){
	return A.ID<B.ID;
}
bool cmp2(struct stu A,struct stu B){
	if(A.name!=B.name){
		return strcmp(A.name,B.name)<=0;
	}
	else{
		return A.ID<B.ID;
	}
}
bool cmp3(struct stu A,struct stu B){
	if(A.grade!=B.grade){
		return A.grade<B.grade;
	}
	else{
		return A.ID<B.ID;
	}
}
int main(){
	int N,C;
	scanf("%d %d",&N,&C);
	struct stu s[N];
	for(int i=0;i<N;i++){
		scanf("%d %s %d",&s[i].ID,s[i].name,&s[i].grade);
	}
	if(C==1){
		sort(s,s+N,cmp1);
	}
	else if(C==2){
		sort(s,s+N,cmp2);
	}
	else{
		sort(s,s+N,cmp3);
	}
	for(int i=0;i<N;i++){
		printf("%06d %s %d\n",s[i].ID,s[i].name,s[i].grade);
	}
	return 0;
}
