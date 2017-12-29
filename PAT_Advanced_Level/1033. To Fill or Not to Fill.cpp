#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 999999999;
struct gas_station{
	double dis,price;
};
bool cmp(gas_station A,gas_station B){
	return A.dis < B.dis;
}
int main(){
	double cmax,D,davg;
	int N;
	scanf("%lf %lf %lf %d",&cmax,&D,&davg,&N);
	vector <gas_station> station(N+1);
	for(int i=1;i<=N;i++){
		scanf("%lf %lf",&station[i].price,&station[i].dis);
	}
	station[0].price = 0;
	station[0].dis = D;
	sort(station.begin(),station.end(),cmp); 
	if(station[0].dis != 0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double current_dis = 0,current_price = station[0].price,total_cost = 0,left_dis = 0,max_dis = cmax*davg;
	while(current_dis < D){
		double min_price = INF,min_price_dis = -1,flag = 0;		
		for(int i=1;i<=N and station[i].dis <= max_dis + current_dis;i++){
			if(station[i].dis <= current_dis) continue;
			if(station[i].price < current_price){
				if(left_dis > station[i].dis - current_dis){
					left_dis -= station[i].dis - current_dis;
				}
				else{
					total_cost += (station[i].dis - current_dis - left_dis)/davg*current_price;
					left_dis = 0.0;
				}
				current_dis = station[i].dis;
				current_price = station[i].price;
				flag = 1;
				break;
			}
			if(station[i].price < min_price){
				min_price = station[i].price;
				min_price_dis = station[i].dis;
			}
		}
		if(not flag and min_price_dis == -1){
			current_dis += cmax*davg;
			printf("The maximum travel distance = %.2lf",current_dis);
			return 0;
		}
		else if(not flag and min_price_dis != -1){
			total_cost += (cmax-left_dis/davg) * current_price;
			left_dis = cmax*davg - (min_price_dis - current_dis);
			current_price = min_price;
			current_dis = min_price_dis;
		}
	}
	printf("%.2f",total_cost);
	return 0;
}
