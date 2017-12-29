//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmpDec(int a,int b){
    return a>b;
}
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N,cmpDec);
    int count=0;
    int flag=0;
    for(int i=0;i<N;i++){
        count++;
        if(arr[i]<=count){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("%d",count-1);
    }
    else{
        printf("%d",count);
    }
    return 0;
}
