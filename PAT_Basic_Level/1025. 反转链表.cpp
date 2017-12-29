#include <stdio.h>
using namespace std;
int data[100000];
int next[100000];
int List[100000];
int main(){
	int f_add,N=0,K,tempN;
	scanf("%d %d %d",&f_add,&tempN,&K);
	for(int i=0;i<tempN;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d %d",&data[temp],&next[temp]);
	}
	int temp=f_add;
    for(int i=0;i<tempN&&temp!=-1;i++){
    	List[i]=temp;
    	temp=next[temp];
    	N++;
	}
	for(int i=0;i<N/K;i++){
		for(int j=i*K+K-1;j>i*K;j--){
			next[List[j]]=List[j-1];
			printf("%05d %d %05d\n",List[j],data[List[j]],next[List[j]]);
		}
		if(i==N/K-1&&N%K!=0){
			next[List[i*K]]=List[i*K+K];
		}
		else if(i==N/K-1&&N%K==0){
			next[List[i*K]]=-1;
		}
		else if(i!=N/K-1){
			next[List[i*K]]=List[(i+2)*K-1];
		}
		if(next[List[i*K]]!=-1){
			printf("%05d %d %05d\n",List[i*K],data[List[i*K]],next[List[i*K]]);
		}
		else{
			printf("%05d %d -1\n",List[i*K],data[List[i*K]]);
		}
	}
	for(int i=(N/K)*K;i<N;i++){
		if(next[List[i]]!=-1){
			printf("%05d %d %05d\n",List[i],data[List[i]],next[List[i]]);
		}
		else{
			printf("%05d %d -1\n",List[i],data[List[i]]);
		}
	}
	return 0;
}
