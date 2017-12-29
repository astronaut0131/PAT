#include <stdio.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int cp1[N],cp2[N],halfed[N];
	for(int i=0;i<N;i++){
		scanf("%d",&cp1[i]);
		cp2[i]=cp1[i];
	}
	for(int i=0;i<N;i++){
		scanf("%d",&halfed[i]);
	}
	int point=N+1;
	for(int i=1;i<N;i++){
		if(cp1[i-1]>cp1[i]){
			int temp=cp1[i];
			int j=i;
			while(j>0&&cp1[j-1]>temp){
				cp1[j]=cp1[j-1];
				j--;
			}
			cp1[j]=temp;
		}
        if(point==N+1){
        	for(int j=0;j<N;j++){
		    	if(cp1[j]!=halfed[j]){
			    	break;
		    	}
	     	}
	     	if(j==N){
	    		point=i+1;
	     	}
		}
		if(i==point){
			for(int i=0;i<N;i++){
				printf("%d",cp1[i]);
				if(i!=N-1){
					printf(" ");
				}
			}
			return 0;
		}
	}
	for()
}
