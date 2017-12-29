#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct process{
	int time_point;
	int duration;
};
vector <process> single_process;
vector <int> in_process;
bool cmp(process A,process B){
	return A.time_point<B.time_point;
}
bool cmpInc(int A,int B){
	return A<B;
}
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		int h,m,s,dur;
		scanf("%d:%d:%d %d",&h,&m,&s,&dur);
		process p;
		p.time_point = h*3600+m*60+s;
		p.duration = dur*60;
		if(p.time_point < 17*3600)
			single_process.push_back(p);
	}
	sort(single_process.begin(),single_process.end(),cmp);
	int tot_wait_time = 0;
	for(int i=0;i<single_process.size();i++){
		if(in_process.size()<K){
			if(single_process[i].time_point < 8*3600){
				tot_wait_time += 8*3600 - single_process[i].time_point;
				in_process.push_back(8*3600+single_process[i].duration);
			}
			else{
				in_process.push_back(single_process[i].time_point + single_process[i].duration);
			}
		}
		else{
			sort(in_process.begin(),in_process.end(),cmpInc);
			if(in_process[0] < single_process[i].time_point){
				in_process[0] = single_process[i].time_point + single_process[i].duration;
			}
			else{
				tot_wait_time += in_process[0] - single_process[i].time_point;
				in_process[0] += single_process[i].duration;
			}
		}
	}
	printf("%.1f",tot_wait_time/60.0/single_process.size());
}
