#include <stdio.h>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
char name[40005][5];
map <int,vector <int> > course;
bool cmp(int A,int B){
	return strcmp(name[A],name[B]) < 0;
}
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		int num;
		scanf("%s %d",name[i],&num);
		for(int j=0;j<num;j++){
			int course_id;
			scanf("%d",&course_id);
			course[course_id].push_back(i);
		}
	}
	for(int i=1;i<=K;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
