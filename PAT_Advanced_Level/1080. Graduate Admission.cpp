#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct student{
	int Ge,Gi,id;
	float grade;
	vector <int> quota_list;
	int rank;
};
map <int,vector<int> > admitted_stu;
map <int,int> admit;
bool cmp(student A,student B){
	if(A.grade != B.grade) return A.grade > B.grade;
	else return A.Ge > B.Ge;
}
bool cmp2(int A,int B){
	return A<B;
}
int main(){
	int M,N,K;
	scanf("%d %d %d",&M,&N,&K);
	int quota[N];
	for(int i=0;i<N;i++){
		scanf("%d",&quota[i]);
	}
	vector <student> stu(M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&stu[i].Ge,&stu[i].Gi);
		stu[i].grade = (stu[i].Ge + stu[i].Gi)*0.5;
		stu[i].quota_list.resize(K);
		stu[i].id = i;
		for(int j=0;j<K;j++){
			scanf("%d",&stu[i].quota_list[j]);
		}
	}
	sort(stu.begin(),stu.end(),cmp);
	int temp_rank = 1;
	float last_grade = -1;
	int last_Ge = -1;
	for(int i=0;i<stu.size();i++){
		if(not((stu[i].grade == last_grade and stu[i].Ge == last_Ge) or last_Ge == -1)){
			temp_rank++;
		}
		stu[i].rank = temp_rank;
		last_grade = stu[i].grade;
		last_Ge = stu[i].Ge;
		for(int j=0;j<stu[i].quota_list.size();j++){
			int school = stu[i].quota_list[j]; 
			if(quota[school]>0 or admit[school] == stu[i].rank){
				admitted_stu[school].push_back(stu[i].id);
				admit[school] = stu[i].rank;
				quota[school]--;
				break;
			}
		}
	}
	/*for(int i=0;i<M;i++){
		printf("stu:%d rank:%d ",stu[i].id,stu[i].rank);
		for(int j=0;j<stu[i].quota_list.size();j++){
			printf("%d ",stu[i].quota_list[j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<N;i++){
		sort(admitted_stu[i].begin(),admitted_stu[i].end(),cmp2);
		for(int j=0;j<admitted_stu[i].size();j++){
			if(j!=0) printf(" ");
			printf("%d",admitted_stu[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
