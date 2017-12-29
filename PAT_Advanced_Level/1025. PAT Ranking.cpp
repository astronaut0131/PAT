#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
	long long int reg_num;
	int rank;
	int location;
	int local_rank;
	int mark;
};
int cmp(student A,student B){
	if(A.mark != B.mark)
		return A.mark > B.mark;
	else
		return A.reg_num < B.reg_num;
}
int main(){
	int N;
	scanf("%d",&N);
	vector <student> res;
	for(int i=1;i<=N;i++){
		int K;
		scanf("%d",&K);
		vector <student> temp(K);
		for(int j=0;j<K;j++){
			temp[j].location = i;
			scanf("%lld %d",&temp[j].reg_num,&temp[j].mark);
		}
		sort(temp.begin(),temp.end(),cmp);
		int temprank = 1;
		int last_mark = -1;
		int cnt = 0;
		for(int j=0;j<K;j++){
			if(last_mark != -1 and temp[j].mark != last_mark){
				temprank+=cnt;
				cnt = 0;
			}
			temp[j].local_rank = temprank;
			last_mark = temp[j].mark;
			res.push_back(temp[j]);
			cnt++;
		}
	}
	printf("%d\n",res.size());
	sort(res.begin(),res.end(),cmp);
	int temprank = 1;
	int last_mark = -1;
	int cnt = 0;
	for(int i=0;i<res.size();i++){
		if(last_mark != -1 and res[i].mark != last_mark){
			temprank += cnt;
			cnt = 0;
		}
		res[i].rank = temprank;
		last_mark = res[i].mark;
		cnt++;
	}
	for(int i=0;i<res.size();i++){
		printf("%013lld %d %d %d\n",res[i].reg_num,res[i].rank,res[i].location,res[i].local_rank);
	}
	return 0;
}
