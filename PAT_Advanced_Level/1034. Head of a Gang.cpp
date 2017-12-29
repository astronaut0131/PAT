#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <string,int> s_to_i;
map <int,string> i_to_s;
map <string,int> gang_num;
vector <string> v;
vector <int> u;
const int MAXN = 2005;
int G[MAXN][MAXN];
int weight[MAXN];
bool visit[MAXN];
int p = 1;
bool cmpInc(string A,string B){
	return A<B;
}
void dfs(int x,int &total_weight,int &total_num,int &head){
	visit[x] = true;
	total_weight += weight[x];
	total_num++;
	if(weight[x] > weight[head]){
		head = x;
	}
	for(int i=1;i<p;i++){
		if(not visit[i] and G[i][x]!=0){
			dfs(i,total_weight,total_num,head);
			G[i][x] = G[x][i] = 0;
		}
	}
}
int get_id(string x){
	if(s_to_i[x] == 0){
		s_to_i[x] = p;
		i_to_s[p] = x;
		p++;
		return s_to_i[x]; 
	}
	else return s_to_i[x];
}
int main(){
	fill(G[0],G[0]+MAXN*MAXN,0);
	fill(visit,visit+MAXN,false);
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		string A,B;
		int w;
		cin>>A>>B>>w;
		int id_A = get_id(A);
		int id_B = get_id(B);
		G[id_A][id_B] = G[id_B][id_A] = w;
		weight[id_A] += w;
		weight[id_B] += w;
	}
	for(int i=1;i<p;i++){
		if(visit[i] == false){
			int total_weight = 0;
			int total_num = 0;
			int head = i;
			dfs(i,total_weight,total_num,head);
			if((total_weight/2) > K and total_num >2){
				v.push_back(i_to_s[head]);
				gang_num[i_to_s[head]] = total_num;
			}
		}
	}
	sort(v.begin(),v.end(),cmpInc);
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "<<gang_num[v[i]]<<endl;
	}
	return 0;
}
