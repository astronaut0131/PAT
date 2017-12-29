#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmpDec(int a, int b){
	return a>b;
}
int main(){
	int x;
	scanf("%d",&x);
	int num1,num2,temp;
	temp=x;
	while(1){
		int arr[4];
		arr[0]=temp/1000;
		arr[1]=(temp-arr[0]*1000)/100;
		arr[2]=(temp-arr[0]*1000-arr[1]*100)/10;
		arr[3]=temp%10;
		sort(arr,arr+4);
		num1=arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
		sort(arr,arr+4,cmpDec);
		num2=arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
	    printf("%04d - %04d = %04d\n",num2,num1,num2-num1);
		if(num2-num1==6174){
			break;
		}
	    temp=num2-num1;
	    if(temp==0){
	    	break;
		}
	}
	return 0;
}
