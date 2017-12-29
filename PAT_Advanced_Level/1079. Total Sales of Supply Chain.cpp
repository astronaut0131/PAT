//
// Created by gesangdianzi on 2017/4/6.
//
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
map <int,int> mapp;
int main(){
    int N;
    double P,r;
    scanf("%d %lf %lf",&N,&P,&r);
    vector <int> v[N];
    int level[N];
    for(int i=0;i<N;i++){
        int k;
        scanf("%d",&k);
        if(k!=0){
            for(int j=0;j<k;j++){
                int x;
                scanf("%d",&x);
                v[i].push_back(x);

            }
        }
        else{
            int x;
            scanf("%d",&x);
            mapp[i]=x;
        }
    }
    queue <int> Q;
    level[0]=0;
    Q.push(0);
    double sum=0;
    while(!Q.empty()){
        int temp=Q.front();
        if(mapp[temp]!=0){
            sum+=mapp[temp]*P*pow(1+r/100,level[temp]*1.0);
        }
        Q.pop();
        for(int i=0;i<v[temp].size();i++){
            Q.push(v[temp][i]);
            level[v[temp][i]]=level[temp]+1;
        }
    }
    printf("%.1lf",sum);
    return 0;
}
