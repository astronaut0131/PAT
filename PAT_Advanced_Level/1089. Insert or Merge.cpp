#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int A,int B){
	return A<B;
}
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	int b[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	int pos;
	for(int i=0;i<N-1;i++){
		if(b[i] > b[i+1]){
			pos = i+1;
			break;
		}
	}
	int is_insert = true;
	for(int i=pos;i<N;i++){
		if(a[i]!=b[i]){
			is_insert = false;
			break;
		}
	}
	if(is_insert){
		printf("Insertion Sort\n");
		sort(b,b+pos+1,cmp);
		for(int i=0;i<N;i++){
			if(i!=0) printf(" ");
			printf("%d",b[i]);
		}
	}
	else{
		printf("Merge Sort\n");
		int k=1,flag = 1;
		while(flag){
			flag = 0;
			for(int i=0;i<N;i++){
				if(a[i] != b[i]){
					flag = 1;
					break;
				}
			}
			k *= 2;
			for(int i=0;i<N/k;i++){
				sort(a+i*k,a+(i+1)*k,cmp);
			}
			sort(a+N/k*k,a+N,cmp);
		}
		for(int i=0;i<N;i++){
			if(i!=0) printf(" ");
			printf("%d",a[i]);
		}
	}
	return 0;
}
