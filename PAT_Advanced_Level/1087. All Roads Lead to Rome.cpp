#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 9999999;
map <string,int> mapp;
map <int,string> mapo;
vector <string> vec;
int main(){
	int N,M;
	string S,D="ROM";
	cin>>N>>M>>S;
	int weight[N];
	int G[N][N];
	int dis[N];
	int w[N];
	int num[N];
	int pre[N];
	bool visit[N];
	fill(G[0],G[0]+N*N,INF);
	fill(dis,dis+N,INF);
	fill(w,w+N,0);
	fill(visit,visit+N,false);
	fill(num,num+N,0);
	mapp[S]=0;
	mapo[0]=S;
	for(int i=1;i<N;i++){
		string x;
		cin>>x>>weight[i];
		mapp[x]=i;
		mapo[i]=x;
	}
	for(int i=0;i<M;i++){
		string v1,v2;
		cin>>v1>>v2;
		cin>>G[mapp[v1]][mapp[v2]];
		G[mapp[v2]][mapp[v1]]=G[mapp[v1]][mapp[v2]];
	}
	dis[mapp[S]]=0;
	w[mapp[S]]=0;
	num[mapp[S]]=1;
	while(1){
		int u=-1,min=INF;
		for(int i=0;i<N;i++){
			if(visit[i]==false){
				if(dis[i]<min){
					min=dis[i];
					u=i;
				}
			}
		}
		if(u==-1){
			break;
		}
		visit[u]=true;
		for(int v=0;v<N;v++){
			if(visit[v]==false&&G[u][v]!=INF){
				if(G[u][v]+dis[u]<dis[v]){
					dis[v]=dis[u]+G[u][v];
					num[v]=num[u];
					w[v]=weight[v]+w[u];
					pre[v]=u;
				}
				else if(G[u][v]+dis[u]==dis[v]){
					num[v]+=num[u];
					if(w[v]<weight[v]+w[u]){
						w[v]=weight[v]+w[u];
						pre[v]=u;
					}
					else if(w[v]==weight[v]+w[u]){
						if(w[v]<(weight[v]+w[u])/2){
							pre[v]=u;
						}
					}
				}
			}
		}
	}
    for(int i=mapp[D];i!=mapp[S];i=pre[i]){
    	vec.push_back(mapo[i]);
	}
	vec.push_back(S);
	cout<<num[mapp[D]]<<" "<<dis[mapp[D]]<<" "<<w[mapp[D]]<<" "<<w[mapp[D]]/(vec.size()-1)<<endl;
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
		if(i!=0){
			cout<<"->";
		}
	}
	return 0;
}
