//
// Created by gesangdianzi on 2017/4/6.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N,L;
    scanf("%d %d",&N,&L);
    vector <int> v[N+1];
    bool visit[N+1];
    int level[N+1];
    for(int i=1;i<=N;i++){
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            int x;
            scanf("%d",&x);
            v[x].push_back(i);
        }
    }
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int x;
        scanf("%d",&x);
        int cnt = 0;
        queue <int> Q;
        Q.push(x);
        level[x]=0;
        fill(visit,visit+N+1, false);
        visit[x]=true;
        while(!Q.empty()){
            int temp = Q.front();
            Q.pop();
            if(level[temp]<=L&&level[temp]!=0){
                cnt++;
            }
            for(int j=0;j<v[temp].size();j++){
                if(!visit[v[temp][j]]){
                    Q.push(v[temp][j]);
                    visit[v[temp][j]]=true;
                    level[v[temp][j]]=level[temp]+1;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
