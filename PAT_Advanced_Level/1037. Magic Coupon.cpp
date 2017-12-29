//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmpDec(int a,int b){
    return a>b;
}
vector <int> v1;
vector <int> v2;
vector <int> v3;
vector <int> v4;
int main(){
    int N,M;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        if(x>0){
            v1.push_back(x);
        }
        else if(x<0){
            v2.push_back(x);
        }
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int x;
        scanf("%d",&x);
        if(x>0){
            v3.push_back(x);
        }
        else if(x<0){
            v4.push_back(x);
        }
    }
    sort(v1.begin(),v1.end(),cmpDec);
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end(),cmpDec);
    sort(v4.begin(),v4.end());
    int sum=0;
    for(int i=0;i<min(v1.size(),v3.size());i++){
        sum+=v1[i]*v3[i];
    }
    for(int i=0;i<min(v2.size(),v4.size());i++){
        sum+=v2[i]*v4[i];
    }
    printf("%d",sum);
    return 0;
}
