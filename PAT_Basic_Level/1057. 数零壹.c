#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char s[100005];
char result[100000];
int main(){
	int num0=0,num1=0;
	int sum=0,i;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])){
			s[i]=tolower(s[i]);
			sum+=s[i]-'a'+1;
		}
	}
	itoa(sum,result,2);
	for(i=0;i<strlen(result);i++){
		if(result[i]=='0'){
			num0++;
		}
		else if(result[i]=='1'){
			num1++;
		}
	}
	printf("%d %d",num0,num1);
	return 0;
}
