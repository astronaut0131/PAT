#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> x;
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	a=a+b;
	int temp=a;
	while(1){
		x.push_back(temp%c);
		if(temp==temp%c){
			break;
		}
		temp=temp/c;
	}
	reverse(x.begin(),x.end());
	for(int i=0;i<x.size();i++){
		printf("%d",x[i]);
	}
	return 0;
}
