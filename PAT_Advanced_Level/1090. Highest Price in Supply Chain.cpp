//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    double P,r;
    int root=-1;
    scanf("%d %lf %lf",&N,&P,&r);
    vector <int> v[N];
    int level[N];
    int num[N];
    fill(num,num+N,0);
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        if(x!=-1){
            v[x].push_back(i);
        }
        else{
            root = i;
        }
    }
    queue <int> Q;
    Q.push(root);
    level[root]=0;
    int max=0;
    num[level[root]]=1;
    while(!Q.empty()){
        int temp = Q.front();
        if(level[temp]>max){
            max=level[temp];
        }
        Q.pop();
        for(int i=0;i<v[temp].size();i++){
            Q.push(v[temp][i]);
            level[v[temp][i]]=level[temp]+1;
            num[level[v[temp][i]]]++;
        }
    }
    double highest =P*pow(1.0+r/100,max);
    printf("%.2lf %d",highest,num[max]);
    return 0;
}
