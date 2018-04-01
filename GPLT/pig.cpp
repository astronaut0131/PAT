#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
float judge(string a,int &num){
	int i=0,flag=1,key=0;
	float output=0;
	if(a[0]=='-'){
		flag=-1;
		i++;
	}
	if(a[0]=='+'){
		flag=1;
		i++;
	}
	if(a[0]=='.')
	cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
	for(;i<a.length();i++){
		if(key==0&&(a[i])<='9'&&a[i]>='0'){
			output=output*10+a[i]-'0';
		}
		else if(a[i]=='.') {
			if((i<(a.length()-3))||key!=0){
			cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
			return 0;
			}
			else key=i;
		}
		else if(a[i]<='9'&&a[i]>='0'&&key!=0){
			output+=(a[i]-'0')/pow(10,i-key);
		}
		else {
			cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
			return 0;
		}
	}
	output*=flag;
	if(output>=-1000&&output<=1000) {
		num++;
		return output;
	}
	else{
		cout<<"ERROR: "<<output<<" is not a legal number"<<endl;
		return 0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int num=0;
	float sum=0;
	for(int i=0;i<n;i++){ 
		string a;
		cin>>a;
		sum+=judge(a,num);
	}
	if(num==1)
	printf("The average of 1 number is %.2f",sum);
	else if(num!=0)
	printf("The average of %d numbers is %.2f",num,sum/num);
	else 
	printf("The average of 0 numbers is Undefined");
}
