#include <stack>
#include <stdio.h>
using namespace std;
stack <int> A,B;
int current_min = 999999999;
void stack_push(int x){
	A.push(x);
	if(A.size()==0 or x < current_min){
		current_min = x;
		B.push(x);
		printf("B top:%d\n",B.top());
	}
}
void stack_pop(){
	if(A.size() > 0){
		int temp = A.top();
		A.pop();
		if(temp == current_min){
			B.pop();
			if(B.size()>0)
				current_min = B.top();
		}
		return;
	}
	printf("Empty Stack!");
}
int get_min(){
	return current_min;
}
using namespace std;
int main(){
	stack_push(1);
	printf("%d\n",get_min());
	stack_push(-5);
	printf("%d\n",get_min());
	stack_pop();
	printf("%d\n",get_min());
	stack_pop();
	return 0;
}