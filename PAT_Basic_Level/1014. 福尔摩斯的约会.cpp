#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int find_min(int a,int b){
	return a<b?a:b;
}
int main(){
	int weekday;
	int hour,min;
	int flag=0;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<find_min(s1.length(),s2.length());i++){
		if(isupper(s1[i])&&s1[i]==s2[i]&&flag==0&&s1[i]<='G'){//注意小于等于G这个条件 
			weekday=s1[i]-'A'+1;
			flag=1;
			continue;
		}
		if(flag==1&&s1[i]==s2[i]){
			if(isdigit(s1[i])){
				hour=s1[i]-'0';
				break;
			}
			else if(s1[i]>='A'&&s1[i]<='N'){
				hour=s1[i]-'A'+10;
	            break;
			}
		}
	}
	for(int i=0;i<find_min(s3.length(),s4.length());i++){
		if(s3[i]==s4[i]&&isalpha(s3[i])){
			min=i;
			break;
		}
	}
	switch(weekday){
		case 1:printf("MON ");break;
		case 2:printf("TUE ");break;
		case 3:printf("WED ");break;
		case 4:printf("THU ");break;
		case 5:printf("FRI ");break;
		case 6:printf("SAT ");break;
		case 7:printf("SUN ");break;
	}
	printf("%02d:%02d",hour,min);
	return 0;
}
