//
// Created by gesangdianzi on 2017/4/5.
//
#include <stdio.h>
using namespace std;
int main(){
    double arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%lf",&arr[i][j]);
        }
    }
    double sum=1.0;
    for(int i=0;i<3;i++){
        double max=0;
        int u=0;
        for(int j=0;j<3;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
                u=j;
            }
        }
        sum*=arr[i][u];
        switch(u){
            case 0:printf("W");break;
            case 1:printf("T");break;
            case 2:printf("L");break;
            default:;
        }
        printf(" ");
    }
    printf("%.2lf",(sum*0.65-1)*2);
    return 0;
}
