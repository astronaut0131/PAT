//
// Created by gesangdianzi on 2017/4/6.
//
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    int flag1=0,flag2=N-1;
    while(arr[flag1]+arr[flag2]!=M&&flag1!=flag2){
        if(arr[flag1]+arr[flag2]>M){
            flag2--;
        }
        else{
            flag1++;
        }
    }
    if(flag1==flag2){
        printf("No Solution");
    }
    else{
        printf("%d %d",arr[flag1],arr[flag2]);
    }
    return 0;
}
