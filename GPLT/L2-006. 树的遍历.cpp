#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef struct tree_node *link;
struct tree_node{
	int value;
	link left,right;
};
vector <int> post;
vector <int> in;
link build_tree(link node,int inL,int inR,int postL,int postR){
	if(inL > inR or postL > postR)
		return NULL;
	if(node == NULL){
		node = new tree_node;
		node->left = node->right = NULL;
		node->value = post[postR];
	}
	int index;
	for(int i=inL;i<=inR;i++){
		if(in[i] == node->value){
			index = i;
			break;
		}
	}
	node->left = build_tree(node->left,inL,index-1,postL,postL+index-inL-1);
	node->right = build_tree(node->right,index+1,inR,postL+index-inL,postR-1);
	return node;
}
void level_traversal(link tree,int nodes_num){
	int cnt = 0;
	queue <link> Q;
	Q.push(tree);
	while(!Q.empty()){
		link temp = Q.front();
		Q.pop();
		printf("%d",temp->value);
		cnt++;
		if(cnt != nodes_num)
			printf(" ");
		if(temp->left != NULL)
			Q.push(temp->left);
		if(temp->right != NULL)
			Q.push(temp->right);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	post.resize(N);
	in.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	link tree = NULL;
	tree = build_tree(tree,0,N-1,0,N-1);
	level_traversal(tree,N);
	return 0;
}