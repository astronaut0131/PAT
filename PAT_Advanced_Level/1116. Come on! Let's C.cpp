//
// Created by gesangdianzi on 2017/3/30.
//
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map <int,int> map1;
map <int,int> map2;
bool IsPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        map1[x]=i;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        if(map2[x]==1){
            printf("%04d: Checked\n",x);
            continue;
        }
        else if(map1[x]!=0){
            map2[x]=1;
            if(map1[x]==1){
                printf("%04d: Mystery Award\n",x);
            }
            else if(IsPrime(map1[x])){
                printf("%04d: Minion\n",x);
            }
            else{
                printf("%04d: Chocolate\n",x);
            }
        }
        else{
            printf("%04d: Are you kidding?\n",x);
        }
    }
    return 0;
}
