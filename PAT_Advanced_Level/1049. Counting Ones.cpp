#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	for(int i=1;i<=N;i++){
		stringstream s;
		s<<i;
		string x = s.str();
		cnt += count(x.begin(),x.end(),'1');
	}
	printf("%d",cnt);
	return 0;
}
