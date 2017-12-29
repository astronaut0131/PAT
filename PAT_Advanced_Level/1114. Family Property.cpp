#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int pre[10000];
struct info_to_push{
	int id;
	int sets;
	int area;
};
struct family{
	int sets=0;
	int mem_num=0;
	int area=0;
};
map <int,family> root;
vector <info_to_push> v;
vector <bool> visit(10000,false);
vector <int> result;
int find(int x){
	while(x != pre[x]){
		pre[x] = pre[pre[x]];
		x = pre[x];
	}
	return x;
}
void Union(int x,int y){
	int x_root = find(x);
	int y_root = find(y);
	if(x_root == y_root) return;
	if(x_root < y_root){
		pre[y_root] = x_root;
	}
	else{
		pre[x_root] = y_root;
	}
}
bool cmp(int A,int B){
	float avg_A = 1.0*root[A].area / root[A].mem_num;
	float avg_B = 1.0*root[B].area / root[B].mem_num;
	if(avg_A != avg_B){
		return avg_A > avg_B;
	}
	else{
		return A < B;
	}
}
int main(){
	int N;
	for(int i=0;i<10000;i++){
		pre[i] = i;
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int id,fid,mid;
		scanf("%d",&id);
		visit[id] = true;
		scanf("%d %d",&fid,&mid);
		if(fid != -1){
			visit[fid] = true;
			Union(id,fid);
		}
		if(mid != -1){
			visit[mid] = true;
			Union(id,mid);	
		} 
		int cnum;
		scanf("%d",&cnum);
		for(int j=0;j<cnum;j++){
			int cid;
			scanf("%d",&cid);
			visit[cid] = true;
			Union(id,cid);
		}
		info_to_push temp;
		temp.id = id;
		scanf("%d %d",&temp.sets,&temp.area);
		v.push_back(temp);
	}
	for(int i=0;i<v.size();i++){
		int root_id = find(v[i].id);
		root[root_id].sets += v[i].sets;
		root[root_id].area += v[i].area;
	}
	for(int i=0;i<10000;i++){
		if(visit[i]){
			int root_id = find(i);
			root[root_id].mem_num++;
			if(root_id == i) result.push_back(i);
		}		
	}
	sort(result.begin(),result.end(),cmp);
	printf("%d\n",result.size());
	for(int i=0;i<result.size();i++){
		float avg_sets = root[result[i]].sets*1.0 / root[result[i]].mem_num;
		float avg_area = root[result[i]].area*1.0 / root[result[i]].mem_num;
		printf("%04d %d %.3f %.3f\n",result[i],root[result[i]].mem_num,avg_sets,avg_area);
	}
	return 0;
}
