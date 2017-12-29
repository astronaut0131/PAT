#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
	char s[105];
	scanf("%s",s);
	int sum=0;
	int cnt=0,result[105];
	for(int i=0;i<strlen(s);i++){
		sum+=s[i]-'0';
	}
	while(1){
		int temp=sum%10;
		result[cnt]=temp;
		cnt++;
		if(temp==sum){
			break;
		}
		sum=(sum-temp)/10;
	}
	for(int i=cnt-1;i>=0;i--){
		switch(result[i]){
			case 0:printf("zero");break;
			case 1:printf("one");break;
			case 2:printf("two");break;
			case 3:printf("three");break;
			case 4:printf("four");break;
			case 5:printf("five");break;
			case 6:printf("six");break;
			case 7:printf("seven");break;
			case 8:printf("eight");break;
			case 9:printf("nine");break;
		}
		if(i!=0){
			printf(" ");
		}
	}
	return 0;
}
