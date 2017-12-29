//
// Created by gesangdianzi on 2017/3/30.
//
#include <iostream>
#include <map>
using namespace std;
map <string,int> map1;
int main(){
    int M,N,S;
    cin>>M>>N>>S;
    if(M<S){
        printf("Keep going...");
    }
    else{
        for(int i=1;i<=M;i++){
            string x;
            cin>>x;
            if(i==S&&map1[x]==0){
                map1[x]=1;
                S+=N;
                cout<<x<<endl;
            }
            else if(i==S&&map1[x]==1){
                S+=1;
            }
        }
    }


    return 0;
}
