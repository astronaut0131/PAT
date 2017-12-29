//
// Created by gesangdianzi on 2017/4/5.
//
#include <iostream>
#include <map>
using namespace std;
map <string,int> mapH;
map <string,int> mapL;
string higher[12]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string lower[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
void convert_to_mars(string x){
    int num=0;
     for(int i=0;i<x.length();i++){
         num*=10;
         num+=x[i]-'0';
     }
    int a = num/13;
    int b = num%13;
    if(a!=0&&b==0){
        cout<<higher[a-1]<<endl;
    }
    else if(a==0&&b!=0){
        cout<<lower[b]<<endl;
    }
    else if(a!=0&&b!=0){
        cout<<higher[a-1]<<" "<<lower[b]<<endl;
    }
    else{
        cout<<lower[b]<<endl;
    }

}
void convert_to_earth(string x){
     if(x.length()==4){
         cout<<"0"<<endl;
     }
    else if(x.length()==3){
         for(int i=1;i<13;i++){
             if(lower[i]==x){
                 printf("%d\n",i);
                 return;
             }
         }
         for(int i=0;i<12;i++){
             if(higher[i]==x){
                 printf("%d\n",(i+1)*13);
                 return;
             }
         }
     }
    else{
         int pos;
         string a="000",b="000";
         for(int i=0;i<x.length();i++){
             if(x[i]==' '){
                 pos=i;
                 break;
             }
         }
         for(int i=0;i<pos;i++){
             a[i]=x[i];
         }
         for(int i=pos+1;i<x.length();i++){
             b[i-pos-1]=x[i];
         }
         printf("%d\n",mapH[a]*13+mapL[b]);
     }
}
int main(){
    for(int i=0;i<12;i++){
        mapH[higher[i]]=i+1;
    }
    for(int i=0;i<13;i++){
        mapL[lower[i]]=i;
    }
    int N;
    scanf("%d",&N);
    getchar();
    for (int i=0;i<N;i++){
        string s;
        getline(cin,s);
        if(isdigit(s[0])){
            convert_to_mars(s);
        }
        else if(isalpha(s[0])){
            convert_to_earth(s);
        }
    }
    return 0;
}
