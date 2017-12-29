#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    double sum=0;
    int cnt=0;
    for(int i=0;i<N;i++){
    	char a[100],b[100];
    	scanf("%s",a);
    	double temp;
    	sscanf(a,"%lf",&temp);
    	sprintf(b,"%.2lf",temp);
    	int flag=0;
    	for(int j=0;j<strlen(a);j++){
    		if(a[j]!=b[j]){
    			flag=1;
    			break;
			}
		}
		if(flag||temp>1000||temp<-1000){
			printf("ERROR: %s is not a legal number\n",a);
		}
		else{
			cnt++;
			sum+=temp;
		}
	}
	if(cnt==0){
		printf("The average of 0 numbers is Undefined");
	}
	else if(cnt>1){
		printf("The average of %d numbers is %.2lf",cnt,sum/cnt);
	}
	else if(cnt==1){
		printf("The average of 1 number is %.2lf",sum/cnt);
	}
	return 0;
}
