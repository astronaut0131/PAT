#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> mapp;
vector <int> v;
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		int sum=0;
		while(1){
			int temp=x%10;
			sum+=temp;
			if(temp==x){
				break;
			}
			x=(x-temp)/10;
		}
		if(mapp[sum]==0){
			v.push_back(sum);
			mapp[sum]=1;
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%d",v[i]);
		if(i!=v.size()-1){
			printf(" ");
		}
	}
	return 0;
}
