#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  string Sa,Sb;
  int len;
  cin>>Sa>>Sb;
  if(Sa.length()>100||Sb.length()>100){
    return 0;
  }
  reverse(Sa.begin(),Sa.end());
  reverse(Sb.begin(),Sb.end());
  if(Sa.length()>Sb.length()){
  	string temp(Sa.length()-Sb.length(),'0');
  	Sb=Sb+temp;
  }
  else{
  	string temp(Sb.length()-Sa.length(),'0');
  	Sa=Sa+temp;
  }
  for(int i=0;i<Sb.length();i++){
    if((i+1)%2==0){
      int temp=(Sb[i]-'0')-(Sa[i]-'0');
      if(temp<0){
        temp+=10;
      }
      Sb[i]='0'+temp;
    }
    else{
      int temp=(Sb[i]-'0')+(Sa[i]-'0');
      temp=temp%13;
      if(temp<10&&temp>=0){
        Sb[i]='0'+temp;
      }
      else if(temp==10){
        Sb[i]='J';
      }
      else if(temp==11){
        Sb[i]='Q';
      }
      else{
        Sb[i]='K';
      }
    }
  }
  reverse(Sb.begin(),Sb.end());
  cout<<Sb;
  return 0;
}
