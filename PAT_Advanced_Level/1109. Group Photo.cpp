#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <string,int> height;
bool cmp(string A,string B){
	if(height[A] != height[B]) return height[A] > height[B];
	else return A < B;
}	

int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	getchar();
	vector <string> name(N);
	for(int i=0;i<N;i++){
		cin>>name[i];
		scanf("%d",&height[name[i]]);
		getchar();
	}
	sort(name.begin(),name.end(),cmp);
	int index = 0;
	for(int i=0;i<K;i++){
		int len;
		if(i == 0) len = N - N/K*(K-1);
		else len = N/K;
		vector <string> temp(len);
		int cnt = 0;
		int cur = len/2;
		while(cnt < len){
			temp[cur] = name[index];
			index++;
			cnt++;
			if(cnt % 2==0) cur += cnt; 
			else cur -= cnt;
		}
		for(int i=0;i<temp.size();i++){
			cout<<temp[i];
			if(i != temp.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
