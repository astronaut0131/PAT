#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int A[5];
	bool flag[5];
	fill(A,A+5,0);
	fill(flag,flag+5,false);
	int n;
	int temp=-1;
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x%5==0&&x%2==0){
			A[0]+=x;
			flag[0]=true;
		}
		else if(x%5==1){
			temp*=-1;
			A[1]+=temp*x;
			flag[1]=true;
		}
		else if(x%5==2){
			A[2]+=1;
			flag[2]=true;
		}
		else if(x%5==3){
			A[3]+=x;
			count++;
			flag[3]=true;
		}
		else if(x%5==4){
			if(x>A[4]){
				A[4]=x;
			}
			flag[4]=true;
		}
	}
	for(int i=0;i<=4;i++){
		if(flag[i]&&i!=3){
			printf("%d",A[i]);
		}
		else if(flag[i]&&i==3){
			printf("%.1f",A[i]*1.0/count);
		}
		else{
			printf("N");
		}
		if(i!=4){
			printf(" ");
		}
	}
	return 0;
}
