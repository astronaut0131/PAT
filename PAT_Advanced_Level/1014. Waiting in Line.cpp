#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct line{
	int poptime;
	int endtime;
	queue <int> Q;
};
int main(){
	int N,M,K,Q,index = 1;
	scanf("%d %d %d %d",&N,&M,&K,&Q);
	vector <line> window(N+1);
	vector <int> time(K+1);
	vector <int> result(K+1);
	vector <bool> sorry(K+1,false);
	for(int i=1;i<=K;i++){
		scanf("%d",&time[i]);
	}
	for(int i=1;i<=N;i++){
		window[i].poptime = 0;
		window[i].endtime = 0;
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(index <= K){
				if(i == 1) window[j].poptime = time[index];
				window[j].Q.push(time[index]);
				if(window[j].endtime >= 9*60) sorry[index] = true;
				window[j].endtime += time[index];
				result[index] = window[j].endtime;
				index++;
			}
		}
	}
	while(index <= K){
		int min_pop = window[1].poptime,min_win = 1;
		for(int i=2;i<window.size();i++){
			if(window[i].poptime < min_pop){
				min_pop = window[i].poptime;
				min_win = i;
			}
		}
		window[min_win].Q.pop();
		window[min_win].poptime += window[min_win].Q.front();
		window[min_win].Q.push(time[index]);
		if(window[min_win].endtime >= 9*60) sorry[index] = true;
		window[min_win].endtime += time[index];
		result[index] = window[min_win].endtime;
		index++;
	}
	for(int i=0;i<Q;i++){
		int query;
		scanf("%d",&query);
		if(sorry[query]) printf("Sorry\n");
		else{
			int hour = result[query] /60 +8;
			int min = result[query] %60;
			printf("%02d:%02d\n",hour,min);
		}
	}
	return 0;
}
