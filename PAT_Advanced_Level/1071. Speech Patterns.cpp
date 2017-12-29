//
// Created by gesangdianzi on 2017/4/5.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map <string,int> mapp;
int main(){
    string s;
    int max=0;
    string result;
    getline(cin,s);
    string temp;
    s+="#";
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])||isalpha(s[i])){
            temp+=tolower(s[i]);
        }
        else{
            if(temp!=""){
                mapp[temp]++;
                if((mapp[temp]>max)||(mapp[temp]==max&&temp<result)){
                    max=mapp[temp];
                    result=temp;
                }
                temp="";
            }
        }
    }
    cout<<result<<" "<<max<<endl;
    return 0;
}
