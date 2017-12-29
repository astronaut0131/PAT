#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int main(){
	string a[13]={"###","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string b[13]={"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	int N;
	cin>>N;
	getchar();
	for(int i=0;i<N;i++){
		string s;
		getline(cin,s);
		if(isdigit(s[0])){
			int num=0;
			for(int j=0;j<s.length();j++){
				num+=(s[j]-'0')*pow(10,s.length()-j-1);
			}
			if(num<=12){
				cout<<b[num]<<endl;
			}
			else{
				if(num%13==0){
					cout<<a[num/13]<<endl;
				}
				else{
					cout<<a[num/13]<<" "<<b[num%13]<<endl;
				}
			}
		}
		else{
			if(s=="tret"){
				cout<<0<<endl;
			}
			else{
				int num=0;
				string temp="###";
				for(int j=0;j<3;j++){
					temp[j]=s[j];
				}
				for(int j=1;j<13;j++){
					if(b[j]==temp){
						num+=j;
						break;
					}
					if(a[j]==temp){
						num+=j*13;
						break;
					}
				}
				if(s.length()==3){
					cout<<num<<endl;
				}
				else{
					string temp2="###";
					for(int j=4;j<s.length();j++){
						temp2[j-4]=s[j];
					}
					for(int j=1;j<13;j++){
						if(temp2==b[j]){
							num+=j;
							break;
						}
					}
					cout<<num<<endl;
				}
			}
		}
	}
	return 0;
}
