#include <vector>
#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;
typedef struct node *link; 
struct node{
	int val;
	link left;
	link right;
};
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
int getHeight(link tree){
	if(tree == NULL) return 0;
	int l = getHeight(tree->left) + 1;
	int r = getHeight(tree->right) + 1;
	return l>r?l:r;
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
		if(abs(l-r)>=2){
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
		if(abs(l-r)>=2){
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
int after = 0;
int is_complete = 1;
vector <int> levelOrder(link tree){
	queue <link> Q;
	Q.push(tree);
	vector <int> v;
	while(not Q.empty()){
		link temp = Q.front();
		Q.pop();
		v.push_back(temp->val);
		if(temp->left != NULL){
			if(after) is_complete = 0;
			Q.push(temp->left);
		}
		else after = 1;
		if(temp->right != NULL){
			if(after) is_complete = 0;
			Q.push(temp->right);
		}
		else after = 1;
	}
	return v;
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
	vector <int> result = levelOrder(tree);
	for(int i=0;i<result.size();i++){
		printf("%d",result[i]);
		if(i!=result.size()-1) printf(" ");
		else printf("\n");
	}
	if(is_complete) printf("YES");
	else printf("NO");
	return 0;
} 
