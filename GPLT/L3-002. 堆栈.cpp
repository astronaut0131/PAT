#include <stdio.h>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
set <int> s1;
set <int> s2;
vector <int> stack;
int median_element;
void set_adjust(){
	while(s1.size() > s2.size()+1){
		set <int>::iterator s1_back = s1.end();
		s1_back--;
		s2.insert(*s1_back);
		s1.erase(s1_back);
	}
	while(s1.size() < s2.size()){
		set <int>::iterator s2_begin = s2.begin();
		s1.insert(*s2_begin);
		s2.erase(s2_begin);
	}
	set <int>::iterator back_it = s1.end();
	median_element = *(--back_it);
}
void set_delete(int x){
	set <int>::iterator it;
	if(x <= median_element){
		for(it = s1.begin();it!=s1.end();it++){
			if(*it == x){
				s1.erase(it);
				break;
			}
		}
	}
	else{
		for(it = s2.begin();it!=s2.end();it++){
			if(*it == x){
				s2.erase(it);
				break;
			}
		}
	}
	set_adjust();
}
void set_insert(int x){
	if(s1.size() == 0){
		s1.insert(x);
		median_element = x;
		return;
	}
	if(x <= median_element)
		s1.insert(x);
	else
		s2.insert(x);
	set_adjust();
}
int main(){
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		char s[15];
		scanf("%s",s);
		if(strcmp(s,"Pop") == 0){
			if(stack.size() == 0){
				printf("Invalid\n");
				continue;
			}
			int back = stack.back();
			stack.pop_back();
			printf("%d\n",back);
			set_delete(back);

		}
		else if(strcmp(s,"PeekMedian") == 0){
			if(s1.size() == 0)
				printf("Invalid\n");
			else
				printf("%d\n",median_element);
		}
		else{
			int x;
			scanf("%d",&x);
			getchar();
			stack.push_back(x);
			set_insert(x);
		}
	}
	return 0;
}