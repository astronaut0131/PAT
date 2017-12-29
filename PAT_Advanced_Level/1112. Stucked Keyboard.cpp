#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector <char> v;
map<char,int> mapp;
int main(){
	int K;
	cin>>K;
	string s;
	cin>>s;
	int cnt = 1;
	char former;
	for(int i=0;i<s.length();i++){
		if(i==0){
			former = s[i];
		}
		else if(former == s[i]){
			cnt++;
			if(i==s.length()-1 and cnt%K!=0){
				mapp[s[i]] = -1;
			}
		}
		else{
            if(cnt%K!=0){
            	mapp[former] = -1;
			}
			former = s[i];
			cnt = 1;
		}
	}
	cnt = 1;
    for(int i=0;i<s.length();i++){
    	if(i==0){
    		former = s[i]; 
		}
		else if(former == s[i]){
			cnt++;
			if(i==s.length()-1 and cnt%K == 0 and mapp[s[i]]!=-1){
				if(mapp[former]!=-1){
					v.push_back(s[i]);
					mapp[s[i]] = 1;
				}
				for(int j=1;j<=cnt - cnt/K;j++){
                	s[i-j] = '#';
				}
			}
		}
		else{
			if(cnt%K==0 and mapp[former]!=-1){
				if(mapp[former]!=1){
					v.push_back(former);
					mapp[former] = 1;
				}
                for(int j=1;j<=cnt - cnt/K;j++){
                	s[i-j] = '#';
				}
			}
			former = s[i];
			cnt = 1;
		}
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
	for(int i=0;i<s.length();i++){
		if(s[i]!='#'){
			cout<<s[i];
		}
	}
	return 0;
}
