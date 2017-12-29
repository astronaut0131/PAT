#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int A,int B){
	return A < B;
}
int main(){
	int N;
	scanf("%d",&N);
	int a[N];
	int b[N];
	vector <int> unsort(N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		unsort[i] = a[i];
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	int pos = 0;
	for(int i=0;i<N-1;i++){
		if(b[i] > b[i+1]){
			pos = i+1;
			break;
		}
	}
	bool insertion_sort = 1;
	for(int i=pos;i<N;i++){
		if(a[i] != b[i]){
			insertion_sort = 0;
			break;
		}
	}
	if(insertion_sort){
		printf("Insertion Sort\n");
		sort(b,b+pos+1,cmp);
		for(int i=0;i<N;i++){
			if(i!=0) printf(" ");
			printf("%d",b[i]);
		}
	}
	else{
		printf("Heap Sort\n");
		vector<int>::iterator it = unsort.end();
		int flag;
		while(1){
			flag = 0;
			make_heap(unsort.begin(),it);
			pop_heap(unsort.begin(),it);
			for(int i=0;i<N;i++){
				if(unsort[i] != b[i]){
					flag = 1;
					break;
				}
			}
			it--;
			if(flag == 0){
				make_heap(unsort.begin(),it);
				pop_heap(unsort.begin(),it);
				break;
			}
		}
		for(int i=0;i<N;i++){
			if(i!= 0) printf(" ");
			printf("%d",unsort[i]);
		}
	}
	return 0;
}
