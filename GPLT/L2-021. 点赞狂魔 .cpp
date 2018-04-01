#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
map <string,int> tag_count;
map <string,float> tag_avg;
vector <string> people;
bool cmp(string A, string B){
	if(tag_count[A] != tag_count[B])
		return tag_count[A] > tag_count[B];
	else
		return tag_avg[A] < tag_avg[B];
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		getchar();
		set <int> tag_set;
		string name;
		cin>>name;
		people.push_back(name);
		int tag_num;
		scanf("%d",&tag_num);
		for(int j=0;j<tag_num;j++){
			int tag;
			scanf("%d",&tag);
			tag_set.insert(tag);
		}
		tag_count[name] = tag_set.size();
		tag_avg[name] = 1.0*tag_num/tag_set.size();
	}
	sort(people.begin(), people.end(),cmp);
	if(people.size() < 3){
		for(int i=0;i<people.size();i++){
			if(i!=0) printf(" ");
			cout<<people[i];
		}
		for(int i=0;i<3-people.size();i++)
			cout<<" -";
	}
	else{
		for(int i=0;i<3;i++){
			if(i!=0) printf(" ");
			cout<<people[i];
		}
	}
	return 0;
}