//
// Created by gesangdianzi on 2017/4/5.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool IsPrime(int x){
    if(x==0||x==1){
        return false;
    }
    else{
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
}
int main(){
    while(1) {
        int x,y;
        scanf("%d",&x);
        if(x<0){
            break;
        }
        scanf("%d",&y);
        if(!IsPrime(x)){
            printf("No\n");
            continue;
        }
        vector <int> v;
        while(1){
            int temp=x%y;
            v.push_back(temp);
            if(temp==x){
                break;
            }
            x=x/y;
        }
        int num=0;
        for(int i=0;i<v.size();i++){
            num*=y;
            num+=v[i];
        }
        if(IsPrime(num)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
