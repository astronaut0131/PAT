//
// Created by gesangdianzi on 2017/3/31.
//
#include <iostream>
using namespace std;
int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int date,hour,minute;
    int flag=0;
    for(int i=0;i<min(s1.length(),s2.length());i++) {
        if (s1[i] == s2[i] && isupper(s1[i])&&flag==0&&s1[i]<='G') {
            date = s1[i];
            flag = 1;
            continue;
        }
        if (flag == 1 && s1[i] == s2[i]) {
            if(isdigit(s1[i])){
                hour = s1[i]-'0';
                break;
            }
            else if(isalpha(s1[i])&&'A'<=s1[i]&&s1[i]<='N') {
                hour = s1[i] - 'A' + 10;
                break;
            }
        }
    }
    for(int i=0;i<min(s3.length(),s4.length());i++){
        if(s3[i]==s4[i]&&isalpha(s3[i])){
            minute = i;
        }
    }
    switch(date-'A'+1){
        case 1:cout<<"MON";break;
        case 2:cout<<"TUE";break;
        case 3:cout<<"WED";break;
        case 4:cout<<"THU";break;
        case 5:cout<<"FRI";break;
        case 6:cout<<"SAT";break;
        default:cout<<"SUN";break;
    }
    printf(" %02d:%02d",hour,minute);
    return 0;
}
