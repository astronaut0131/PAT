#include <stdio.h>
#include <vector>
using namespace std;
int MSize,N;
int h(int key){
	return key%MSize;
}
bool IsPrime(int x){
	if(x==1) return false;
	else{
		for(int i=2;i<x;i++){
			if(x%i == 0) return false;
		}
		return true;
	}
}
int main(){
	scanf("%d %d",&MSize,&N);
	while(not IsPrime(MSize)) MSize++;
	vector <bool> hash_map(MSize,false);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(hash_map[h(x)] == false){
			hash_map[h(x)] = true;
			printf("%d",h(x));
		}
		else{
			int flag = 0;
			for(int k=1;k<=MSize/2;k++){
				if(hash_map[h(x+k*k)] == false){
					hash_map[h(x+ k*k) ] = true;
					printf("%d",h(x+k*k));
					flag = 1;
					break;
				}
			}
			if(not flag) printf("-"); 
		}
		if(i!=N-1) printf(" ");
	}
	return 0;
}
