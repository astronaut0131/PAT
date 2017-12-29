#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
string x;
void add(string s){
	string result = "";
	string L1 = s,L2 = x; //L1 len >= l2 len
	if(x.length() > s.length()){
		L1 = x;
		L2 = s;
	}
	int carry = 0;
	for(int i=0;i<L2.length();i++){
		int temp = (L1[i]-'0') + (L2[i]-'0') + carry;
		if(temp >= 10){
			carry = 1;
			result += (temp-10)+'0';
		}
		else{
			carry = 0;
			result +=temp+'0';
		}
	}
	for(int i=L2.length();i<L1.length();i++){
		int temp = (L1[i]-'0') + carry;
		if(temp >= 10){
			carry = 1;
			result += (temp-10)+'0';
		}
		else{
			carry = 0;
			result += temp+'0';
		}
	}
	if(carry == 1){
		result += '1';
	}
	reverse(result.begin(),result.end());
	x = result;
}
int main(){
	int n;
	cin>>x>>n;
	for(int i=0;i<=n;i++){
		string temp = x;
		reverse(temp.begin(),temp.end());
		if(temp == x||i==n){
			cout<<x<<endl<<i;
			break;
		}
		add(temp);
	}
}
