#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(abs(a+b)<1000){
		printf("%d",a+b);
	}
	else{
		int arr[100];
		int cnt=0;
		int x=abs(a+b);
		while(1){
			int temp=x%10;
			arr[cnt]=temp;
			cnt++;
			if(temp==x){
				break;
			}
			x=(x-temp)/10;
		}
		if(a+b<0){
			printf("-");
		}
	    char result[100];
	    int count=0;
	    for(int i=0;i<cnt;i++){
	    	if(i%3==0&&i!=0){
	    		result[count]=',';
	    		count++;
			}
			result[count]=arr[i]+'0';
			count++;
		}
		for(int i=count-1;i>=0;i--){
			printf("%c",result[i]);
		}
	}
	return 0;
}
