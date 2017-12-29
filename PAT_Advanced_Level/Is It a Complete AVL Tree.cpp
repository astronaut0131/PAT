#include <stdio.h>
using namespace std;
typedef struct node *link;
struct node{
	int val;
	link left;
	link right;
};
link insert(link tree,int val){
	if(tree == NULL){
		tree = new node;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	link tree = NULL;
	for(int i=0;i<n;i++){
		int val;
		scanf("%d",&val);
		tree = insert(tree,val);
	} 
	return 0;
}
