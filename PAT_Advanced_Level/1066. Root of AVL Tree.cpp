#include <stdio.h>
typedef struct node *link;
struct node{
	int val;
	link left;
	link right;
};
using namespace std;
int getHeight(link tree){
	if(tree == NULL) return 0;
	int l = getHeight(tree->left)+1;
	int r = getHeight(tree->right)+1;
	return l>r?l:r;
}
link leftRotate(link tree){
	link temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;
	return temp;
}
link rightRotate(link tree){
	link temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;
	return temp;
}
link leftRightRotate(link tree){
	tree->left = leftRotate(tree->left);
	tree = rightRotate(tree);
	return tree;
}
link rightLeftRotate(link tree){
	tree->right = rightRotate(tree->right);
	tree = leftRotate(tree);
	return tree;
}
link insert(link tree,int val){
	if(tree == NULL){
		tree = new node;
		tree->left = tree->right = NULL;
		tree->val = val;
	}
	else if(val > tree->val){
		tree->right = insert(tree->right,val);
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		if(r-l>=2){
			if(val > tree->right->val){
				tree = leftRotate(tree);
			}
			else{
				tree = rightLeftRotate(tree);
			}
		}
	}
	else{
		tree->left = insert(tree->left,val);
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		if(l-r>=2){
			if(val < tree->left->val){
				tree = rightRotate(tree);
			}
			else{
				tree = leftRightRotate(tree);
			}
		}
	}
	return tree;
}
int main(){
	link tree = NULL;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int val;
		scanf("%d",&val);
		tree = insert(tree,val);
	}
	printf("%d",tree->val);
	return 0;
}
