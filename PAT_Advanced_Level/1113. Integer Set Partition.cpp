//
// Created by gesangdianzi on 2017/3/30.
//
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    int sum1=0;
    int sum2=0;
    if(N%2==0) {
        for (int i = 0; i < N / 2; i++) {
            sum1 += arr[i];
        }
        for (int i = N / 2; i < N; i++) {
            sum2 += arr[i];
        }
        printf("0 %d",sum2-sum1);
    }
    else{
        for(int i=0;i<N/2;i++){
            sum1+=arr[i];
        }
        for(int i=N/2+1;i<N;i++){
            sum2+=arr[i];
        }
        if(sum2+arr[N/2]-sum1>sum2-(sum1+arr[N/2])){
            printf("1 %d",sum2+arr[N/2]-sum1);
        }
        else{
            printf("1 %d",sum2-(sum1+arr[N/2]));
        }
    }
    return 0;
}
