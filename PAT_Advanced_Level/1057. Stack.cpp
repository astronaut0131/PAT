#include <stdio.h>
#include <stack>
#include <set>
#include <cstring>
using namespace std;
multiset <int> s1,s2;
stack <int> s;
int mid;
void adjust(){
	multiset<int>::iterator it;
	if(s1.size() < s2.size()){
		it = s2.begin();
		s1.insert(*it);
		s2.erase(it);
	}
	else if(s1.size() > s2.size() + 1){
		it = s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if(not s1.empty()){
		it = s1.end();
		mid = *(--it);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char x[15];
		scanf("%s",x);
		if(strcmp(x,"PeekMedian") == 0){
			if(s.empty()) printf("Invalid\n");
			else printf("%d\n",mid);
		}
		else if(strcmp(x,"Pop") == 0){
			if(s.empty()) printf("Invalid\n");
			else{
				int temp = s.top();
				printf("%d\n",temp);
				if(temp<=mid) s1.erase(s1.find(temp));
				else s2.erase(s2.find(temp));
				s.pop();
				adjust();
			}
		}
		else if(strcmp(x,"Push") == 0){
			int num;
			scanf("%d",&num);
			s.push(num);
			if(s1.empty() or num<=mid) s1.insert(num);
			else s2.insert(num);
			adjust();
		}
		else{
			printf("Invalid\n");
		}
	}
	return 0;
}
