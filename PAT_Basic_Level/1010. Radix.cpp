#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map <char,int> mapp;
long long int get_decimal(string x,int radix){
	long long int res = 0;
	for(int i=0;i<x.length();i++){
		res = res*radix + mapp[x[i]];
	}
	if(res < 0) return -1;
	else return res;
}
long long  get_low(string x){
	long long res = -1;
	for(int i=0;i<x.length();i++){
		if(mapp[x[i]]>res) res = mapp[x[i]];
	}
	return res+1;
}
int binary_search(string x,long long low,long long high,long long target){
	int res = -1;
	while(low <= high){
		long long mid = (low + high)/2;
		long long temp = get_decimal(x,mid);
		if(temp == -1){
			high =mid - 1;
			continue;
		}
		if(temp == target){
			res = mid;
			break;
		}
		else if(temp > target){
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return res;
}
int main(){
	for(char i = '0';i<='9';i++){
		mapp[i] = i-'0';
	}
	for(char i = 'a';i<='z';i++){
		mapp[i] = i-'a' + 10;
	}
	string N1,N2;
	int tag,radix;
	cin>>N1>>N2>>tag>>radix;
	if(tag == 2){
		swap(N1,N2);
	}
	long long int deci = get_decimal(N1,radix);
	long long low = get_low(N2);
	int res = binary_search(N2,low,deci+1,deci);
	if(res != -1) printf("%d",res);
	else printf("Impossible");
	return 0;
}
