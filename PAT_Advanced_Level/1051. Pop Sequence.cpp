//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
#include <stack>
#include <map>
using namespace std;
int main(){
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    for(int i=0;i<K;i++){
        int arr[N];
        for(int j=0;j<N;j++){
            scanf("%d",&arr[j]);
        }
        stack <int> s;
        int flag=0;
        map <int,int> mapp;
        for(int j=0;j<N;j++){
            for(int k=1;k<=arr[j];k++){
                if(mapp[k]==0){
                    s.push(k);
                    mapp[k]=1;
                }
            }
            if(s.size()>M||s.top()!=arr[j]){
                printf("NO\n");
                flag=1;
                break;
            }
            s.pop();
        }
        if(flag==0){
            printf("YES\n");
        }
    }
    return 0;
}
