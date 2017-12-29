#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct info{
	string name;
	int month;
	int date;
	int hour;
	int minute;
	string state;
};
vector <info> v;
int rate[24];
bool cmp(info A,info B){
	if(A.name != B.name) return A.name < B.name;
	else if(A.date != B.date) return A.date < B.date;
	else if(A.hour != B.hour) return A.hour < B.hour;
	else return A.minute < B.minute;
}
int get_len(int a,int b,int c,int d,int e,int f){
	return (d*24*60 + e*60 +f) - (a*24*60 + b*60 +c);
}
float get_amount(int a,int b,int c,int d,int e,int f){
	if(a == d){
		if(b == e){
			return (rate[b] * (f-c))/100.0;
		}
		else{
			float sum = 0;
			sum += rate[b] * (60-c);
			for(int i=b+1;i<e;i++){
				sum += rate[i] * 60;
			}
			sum += rate[e] * f;
			return sum/100;
		}
	}
	else{
		float sum = 0;
		sum += rate[b] * (60-c);
		for(int i=b+1;i<24;i++){
			sum += rate[i] * 60;
		}
		for(int i=a+1;i<d;i++){
			for(int j=0;j<24;j++){
				sum += rate[j] * 60;
			}
		}
		for(int i=0;i<e;i++){
			sum += rate[i]*60;
		}
		sum += rate[e] * f;
		return sum/100;
	}
}
int main(){
	for(int i=0;i<24;i++){
		scanf("%d",&rate[i]);
	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string name;
		int month;
		int date;
		int hour;
		int minute;
		string state;
		cin>>name;
		scanf("%d:%d:%d:%d",&month,&date,&hour,&minute);
		cin>>state;
		struct info temp;
		temp.name = name;
		temp.month = month;
		temp.date = date;
		temp.hour = hour;
		temp.minute = minute;
		temp.state = state;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	string last = "";
	float total_sum = 0;
	for(int i = 0;i<v.size()-1;i++){
		if(v[i].name == v[i+1].name and v[i].state == "on-line" and v[i+1].state == "off-line"){
			if(v[i].name != last){
				if(last != "") printf("Total amount: $%.2f\n",total_sum);
				total_sum = 0;
				last = v[i].name;
				cout<<v[i].name<<" ";
				printf("%02d\n",v[i].month);
			}
			float amount = get_amount(v[i].date,v[i].hour,v[i].minute,v[i+1].date,v[i+1].hour,v[i+1].minute);
			int length = get_len(v[i].date,v[i].hour,v[i].minute,v[i+1].date,v[i+1].hour,v[i+1].minute);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",v[i].date,v[i].hour,v[i].minute,v[i+1].date,v[i+1].hour,v[i+1].minute,length,amount);
			total_sum += amount;
		}
	}
	printf("Total amount: $%.2f",total_sum);
	return 0;
}

		
