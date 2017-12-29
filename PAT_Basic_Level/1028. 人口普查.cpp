#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int N;
    int max_y=0,max_m=0,max_d=0,min_y=9999,min_m=9999,min_d=9999;
    string max_n,min_n;
    int cnt=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string name;
		int year,month,day;
		cin>>name;
		scanf("%d/%d/%d",&year,&month,&day);
		if(i==0){
			min_n=name;
			max_n=name;
		}
		if((year>1814||(year==1814&&month>9)||(year==1814&&month==9&&day>=6))&&(year<2014||(year==2014&&month<9)||(year==2014&&month==9&&day<=6))){
			cnt++;
			if(year>max_y||(year==max_y&&month>max_m)||(year==max_y&&month==max_m&&day>max_d)){
				max_y=year;
				max_m=month;
				max_d=day;
				max_n=name;
			}
			if(year<min_y||(year==min_y&&month<min_m)||(year==min_y&&month==min_m&&day<min_d)){
				min_y=year;
				min_m=month;
				min_d=day;
				min_n=name;
			}
		}
	}
    cout<<cnt;
    if(cnt!=0){
    	cout<<" "<<min_n<<" "<<max_n;
	}
	return 0;
}   
