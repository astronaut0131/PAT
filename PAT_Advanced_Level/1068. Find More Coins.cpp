#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector <int> ans;
vector <int> arr;
vector <int> res;
void dfs(int index,int sum){
	if(index >= N) return;
	if(sum == M and res.size() == 0){
		res = ans;
		return;
	}
	else if(sum > M) return;
	else{
		ans.push_back(arr[index]);
		dfs(index+1,sum + arr[index]);
		ans.pop_back();
		dfs(index+1,sum);
	}	
}
int main(){
	scanf("%d %d",&N,&M);
	arr.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(),arr.end());
	dfs(0,0);
	if(res.size() == 0) printf("No Solution");
	else{
		for(int i=0;i<res.size();i++){
			if(i!=0) printf(" ");
			printf("%d",res[i]);
		}
	}
	return 0;
}
