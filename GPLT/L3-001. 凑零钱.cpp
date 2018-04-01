#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
vector <int> current_solution;
vector <int> best_solution;
int N,M;
bool smaller_vector(vector <int> A,vector <int> B){
	for(int i=0;i<min(A.size(),B.size());i++){
		if(A[i]>B[i])
			return false;
	}
	return true;
}
void find(int index,int current_sum){
	printf("%d %d\n",index,current_sum);
	if(current_sum == M){
		if(best_solution.size() == 0 or smaller_vector(current_solution,best_solution)){
			best_solution.clear();
			best_solution = current_solution;
			
		}
	}
	else if(current_sum<M and index < N and smaller_vector(current_solution,best_solution)){
		current_solution.push_back(v[index]);
		if(smaller_vector(current_solution,best_solution))
			find(index+1,current_sum+v[index]);
		current_solution.pop_back();
		find(index+1,current_sum);	
	}
	return;
}
int main(){
	scanf("%d %d",&N,&M);
	v.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());
	find(0,0);
	if(best_solution.size()!=0){
		for(int i=0;i<best_solution.size();i++){
			if(i!=0) printf(" ");
			printf("%d",best_solution[i]);
		}
	}
	else{
		printf("No Solution");
	}
	return 0;
}