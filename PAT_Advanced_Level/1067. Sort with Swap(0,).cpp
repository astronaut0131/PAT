#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int pos = 1;
	int arr[N];
	int index[N];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		index[arr[i]] = i;
	}
	int cnt = 0;
	while(1){
		if(index[0] == 0){
			int flag = 0;
			for(int i=pos;i<N;i++){
				if(arr[i] != i){
					swap(index[0],index[arr[i]]);
					swap(arr[i],arr[0]);
					pos = i+1;
					flag = 1;
					break;
				}
			}
			if(flag == 0) break;
		}
		else{
			swap(arr[index[0]],arr[index[index[0]]]);
			swap(index[0],index[index[0]]);
		}
		cnt++;
	}
	printf("%d",cnt);
}
