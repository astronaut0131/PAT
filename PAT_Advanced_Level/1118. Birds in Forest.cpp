//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
map <int,int> mapp;
vector <int> v;
int pre[10005];
int Find(int x){
    if(pre[x]!=x){
        pre[x]=Find(pre[x]);
    }
    return pre[x];
}
void Union(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x!=y){
        pre[x]=y;
    }
}
int main(){
    for(int i=1;i<=10000;i++){
        pre[i]=i;
    }
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int num,x;
        scanf("%d %d",&num,&x);
        mapp[x]++;
        if(mapp[x]==1){
            v.push_back(x);
        }
        for(int j=0;j<num-1;j++){
            int temp;
            scanf("%d",&temp);
            mapp[temp]++;
            if(mapp[temp]==1){
                v.push_back(temp);
            }
            Union(temp,x);
        }
    }
    int count=0;
    for(int i=0;i<v.size();i++){
        if(pre[v[i]]==v[i]){
            count++;
        }
    }
    printf("%d %d\n",count,v.size());
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(Find(a)==Find(b)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}

