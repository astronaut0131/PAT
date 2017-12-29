#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
	int N;
	double max=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		double temp=sqrt(pow(x,2)+pow(y,2));
		if(temp>max){
			max=temp;
		}
	}
	if(max-((int)(max*1000))*1.0/1000>=0.005){
		max=((int)(max*1000))*1.0/1000+0.01;
	}
	else{
		max=((int)(max*1000))*1.0/1000;
	}
	printf("%.2lf",max);
	return 0;
}
