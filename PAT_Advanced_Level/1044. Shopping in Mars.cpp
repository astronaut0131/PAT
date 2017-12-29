#include <stdio.h>
#include <vector>
using namespace std;
vector <int> sum;
vector <int> res;
vector <int> cost;
int min_cost = 999999999;
int flag = 0;
int N,M;
void binary_search(int low,int high,int target){
	int start = low - 1;
	int mid;
	while(low < high){
		mid = (low + high) / 2;
		if(sum[mid] - sum[start] >= target){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}
	int temp = sum[high] - sum[start];
	if(temp == M){
		res.push_back(start+1);
		res.push_back(high);
	}
	else if(temp-M <= min_cost and temp - M >0){
		if(temp-M < min_cost){
			min_cost = temp-M;
			cost.clear();
		}
		cost.push_back(start+1);
		cost.push_back(high);
	}
}
int main(){
	scanf("%d %d",&N,&M);
	sum.resize(N+1);
	sum[0] = 0;
	for(int i=1;i<=N;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	for(int i=1;i<=N;i++){
		binary_search(i,N,M);
	}
	if(res.size() == 0){
		for(int i=0;i<cost.size();i+=2){
			printf("%d-%d\n",cost[i],cost[i+1]);
		}
	}
	else{
		for(int i=0;i<res.size();i+=2){
			printf("%d-%d\n",res[i],res[i+1]);
		}
	}
	return 0;
}
