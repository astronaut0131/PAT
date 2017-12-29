#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int N,b;
	scanf("%d %d",&N,&b);
	vector <int> v;
	int flag = 1;
	if(N == 0){
		printf("Yes\n0");
	}
	else{
		while(N != 0){
			v.push_back(N%b);
			N = N/b;
		}	
		vector <int> v_copy = v;
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(v[i]!=v_copy[i]){
				flag = 0;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
		for(int i=0;i<v.size();i++){
			if(i!=0) printf(" ");
			printf("%d",v[i]);
		}
	}
	return 0;
}
