#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
map <int,int> house_num;
map <int,int> house_size;
map <int,int> pre;
set <int> people;
map <int,int> total_house_size;
map <int,int> total_house_num;
map <int,int> people_num;
bool cmp(int A,int B){
	float avg_A = total_house_size[A]*1.0/people_num[A];
	float avg_B = total_house_size[B]*1.0/people_num[B];
	if(avg_A!=avg_B)
		return avg_A > avg_B;
	else
		return A<B;
}
int find(int x){
	while(pre[x] != 0){
		x = pre[x];
	}
	return x;
}
void merge(int x,int y){
	if(find(x) == find(y))
		return;
	int x_root = find(x);
	int y_root = find(y);
	if(x_root > y_root)
		y_root = pre[x_root];
	else
		x_root = pre[y_root];
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int id,f_id,m_id,num;
		people.insert(id);
		scanf("%d %d %d %d",&id,&f_id,&m_id,&num);
		if(f_id != -1){
			people.insert(f_id);
			merge(id,f_id);
		}
		if(m_id != -1){
			people.insert(m_id);
			merge(id,m_id);
		}
		for(int j=0;j<num;j++){
			int child;
			scanf("%d",&child);
			people.insert(child);
			merge(id,child);
		}
		int size;
		scanf("%d %d",&num,&size);
		house_num[id] += num;
		house_size[id] += size;
	}
	vector <int> heads;
	for(set <int>::iterator it=people.begin();it!=people.end();it++){
		if(pre[*it]==0){
			heads.push_back(*it);
		}
	}
	for(set <int>::iterator it=people.begin();it!=people.end();it++){
		int head = find(*it);
		people_num[head] += 1;
		total_house_num[head] += house_num[*it];
		total_house_size[head] += house_size[*it]; 
	}
	sort(heads.begin(),heads.end(),cmp);
	printf("%d\n",heads.size());
	for(int i=0;i<heads.size();i++){
		int head = heads[i];
		printf("%d %d %.3f %.3f\n",head,people_num[head],house_num[head]*1.0/people_num[head],house_size[head]*1.0/people_num[head]);
	}
	return 0;
}