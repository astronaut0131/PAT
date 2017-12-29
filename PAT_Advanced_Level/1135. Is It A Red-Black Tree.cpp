#include <stdio.h>
#include <cmath>
using namespace std;
typedef struct tree *link;
struct tree{
	int data;
	link left;
	link right;
};
int get_height(link root){
	if(root == NULL){
		return 0;
	}
	else{
		int l,r;
		l = get_height(root->left);
		r = get_height(root->right);
		if(root->data > 0){
			l += 1;
			r += 1;
		}
		return (l>r)?l:r;
	}
}
bool judge_height(link root){
	if(root == NULL) return true;
	if(get_height(root->left) == get_height(root->right))
		return judge_height(root->left) and judge_height(root->right);
	else
		return false;	
}
bool is_black(link root){
	return root == NULL or root->data > 0;
}

bool judge_red_child(link root){
	if(root==NULL){
		return true;
	}
	if(root->data > 0){
		return judge_red_child(root->left) and judge_red_child(root->right);
	}
	else{
		if(is_black(root->left) and is_black(root->right)) return judge_red_child(root->left) and judge_red_child(root->right);
		else{
			return false;
		}
	}
}
link insert(link root,int data){
	if(root == NULL){
		root = new tree;
		root->left = NULL;
		root->right = NULL;
		root->data = data;
	}
	else if(abs(data) > abs(root->data)){
		root->right = insert(root->right,data);
	}
	else if(abs(data) < abs(root->data)){
		root->left = insert(root->left,data);
	}
	return root;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int len;
		scanf("%d",&len);
		link root = NULL;
		for(int j=0;j<len;j++){
			int data;
			scanf("%d",&data);
			root = insert(root,data);
		}
		if(root->data < 0){
			printf("No\n");
			continue;
		}
		bool red_child = judge_red_child(root);
		bool height_judge = judge_height(root);
		if(red_child and height_judge)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
