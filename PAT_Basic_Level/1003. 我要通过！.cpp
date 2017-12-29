#include <iostream>
using namespace std;
bool judge(string s){
	int a=0,b=0,c=0;
	int pos_P,pos_T;
	for(int i=0;i<s.length();i++){
		if(s[i]!='P'&&s[i]!='A'&&s[i]!='T'){
			return false;
		}
		if(s[i]=='P'){
			a++;
			pos_P=i;
		}
		if(s[i]=='A'){
			b++;
		}
		if(s[i]=='T'){
			c++;
			pos_T=i;
		}
	}
	if(!(a==1&&b&&c==1)){
		return false;
	}
	if(!(pos_P<pos_T-1)){
		return false;
	}
	a=b=c=0;
	a=pos_P;
	b=pos_T-pos_P-1;
	c=s.length()-1-pos_T;
	if((a==0&&c==0)||(c==a*b)){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		if(judge(s)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
