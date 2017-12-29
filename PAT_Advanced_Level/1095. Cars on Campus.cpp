#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct car{
	string plate;
	int time;
	string state;
};
map <string,car> get_car;
map <string,bool> visit;
map <string,bool> in;
map <string,int> total_time;
bool cmp(car A,car B){
	return A.time < B.time;
}
bool cmp2(string A,string B){
	return A < B;
}
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	vector <car> v;
	vector <car> legal_cars;
	for(int i=0;i<N;i++){
		string a,b;
		int h,m,s;
		cin>>a;
		scanf("%d:%d:%d",&h,&m,&s);
		cin>>b;
		car temp;
		temp.plate = a;
		temp.state = b;
		temp.time = h*3600+m*60+s;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	int longest = -1;
	vector <string> longest_car;
	for(int j=0;j<v.size();j++){
		if(v[j].state == "in"){
			visit[v[j].plate] = true;
			get_car[v[j].plate] = v[j];
		}
		else if(v[j].state == "out" and visit[v[j].plate] == true){
			visit[v[j].plate] = false;
			legal_cars.push_back(get_car[v[j].plate]);
			legal_cars.push_back(v[j]);
			int temptime = v[j].time - get_car[v[j].plate].time;
			total_time[v[j].plate] += temptime;
			if(total_time[v[j].plate] > longest){
				longest_car.clear();
				longest = total_time[v[j].plate];
				longest_car.push_back(v[j].plate);
			}
			else if(total_time[v[j].plate] == longest){
				longest_car.push_back(v[j].plate);
			}
		}	
	}
	sort(legal_cars.begin(),legal_cars.end(),cmp);
	int last_cnt = 0;
	int last_j = 0;
	for(int i=0;i<K;i++){
		int h,m,s;
		int cnt = last_cnt;
		scanf("%d:%d:%d",&h,&m,&s);
		int query = h*3600+m*60+s;
		for(int j=last_j;j<legal_cars.size();j++){
			if(legal_cars[j].time > query) {
				last_j = j;
				break;
			}
			if(legal_cars[j].state == "in"){
				in[legal_cars[j].plate] = true;
				cnt++;
			}
			else{
				if(in[legal_cars[j].plate] == true){
					in[legal_cars[j].plate] = false;
					cnt--;
				}
			}
		}
		printf("%d\n",cnt);
		last_cnt = cnt;
	}
	sort(longest_car.begin(),longest_car.end(),cmp2);
	for(int i=0;i<longest_car.size();i++){
		cout<<longest_car[i]<<" ";
	}
	printf("%02d:%02d:%02d",longest/3600,(longest%3600)/60,(longest%3600)%60);
	return 0;
}
