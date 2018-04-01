#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector <int> in;
vector <int> pre;
typedef struct tree_node *link;
struct tree_node{
	int val;
	link left,right;
};
void construct_tree(link &node,int inL,int inR,int preL,int preR){
	if(inL > inR or preL > preR){
		node = NULL;
		return;
	}
	if(node == NULL){
		node = new tree_node;
		node->left = node->right = NULL;
		node->val = pre[preL];
	}
	int index;
	for(int i=inL;i<=inR;i++){
		if(in[i] == node->val){
			index = i;
			break;
		}
	}
	construct_tree(node->left,inL,index-1,preL+1,preL+index-inL);
	construct_tree(node->right,index+1,inR,preL+index-inL+1,preR);
}
void invert_level_traversal(link root){
	int cnt = 0;
	queue <link> Q;
	Q.push(root);
	while(!Q.empty()){
		link temp = Q.front();
		printf("%d%c",temp->val,++cnt==in.size()?('\n'):(' '));
		Q.pop();
		if(temp->right != NULL)
			Q.push(temp->right);
		if(temp->left != NULL)
			Q.push(temp->left);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	in.resize(N);
	pre.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	link root = NULL;
	construct_tree(root,0,N-1,0,N-1);
	invert_level_traversal(root);
	return 0;
}