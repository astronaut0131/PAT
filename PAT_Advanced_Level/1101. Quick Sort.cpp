#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int A,int B){
	return A<B;
}
int main(){
	int N;
	scanf("%d",&N);
	int arr[N+2];
	int maxine[N+1];
	int minium[N+1];
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	maxine[0] = -1;
	arr[0] = -1;
	arr[N+1] = 999999999;
	int max = -1;
	int min = 999999999;
	for(int i=1;i<=N;i++){
		if(arr[i-1]>max){
			max = arr[i-1];
		}
		maxine[i] = max;
	}
	for(int i=N;i>=1;i--){
		if(arr[i+1]<min){
			min = arr[i+1];
		}
		minium[i] = min;
	}
	vector <int> result;
	for(int i=1;i<=N;i++){
		if(maxine[i] < arr[i] and arr[i] < minium[i]){
			result.push_back(arr[i]);
		}
	}
	sort(result.begin(),result.end(),cmp);
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++){
		if(i!=0) printf(" ");
		printf("%d",result[i]);
	}
	printf("\n");
}
