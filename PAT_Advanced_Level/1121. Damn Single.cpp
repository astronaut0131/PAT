#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> mapp;
map<int,int> pairr;
vector <int> v;
int main(){
	for(int i=0;i<=99999;i++){
		pairr[i]=-1;
	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		pairr[a]=b;
		pairr[b]=a;
	}
	int M;
	scanf("%d",&M);
	int arr[M];
    for(int i=0;i<M;i++){
    	scanf("%d",&arr[i]);
    	mapp[arr[i]]=1;
	}
	for(int i=0;i<M;i++){
		if(mapp[pairr[arr[i]]]!=1||pairr[arr[i]]==-1){
			v.push_back(arr[i]);
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%05d",v[i]);
		if(i!=v.size()-1){
			printf(" ");
		}
	}
	return 0;
}
