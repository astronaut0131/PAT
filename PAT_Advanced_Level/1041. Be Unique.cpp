#include <stdio.h>
#include <map>
using namespace std;
map <int,int> mapp;
int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	int flag=0;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		mapp[arr[i]]++;
	}
	for(int i=0;i<N;i++){
		if(mapp[arr[i]]==1){
			printf("%d",arr[i]);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("None");
	}
	return 0;
}
