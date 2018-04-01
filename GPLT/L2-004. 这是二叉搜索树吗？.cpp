#include <stdio.h>
#include <vector>
using namespace std;
vector <int> seq;
vector <int> in;
vector <int> post;
typedef struct tree_node *link;
typedef struct tree_node{
	int val;
	link left,right;
} tree;
link build_tree(int left,int right){
	if(left > right or left < 0 or right >=seq.size())
		return NULL;
	link root = new tree;
	root->val = seq[left];
	root->left = root->right = NULL;
	int i;
	for(i=left+1;i<=right and seq[i]<root->val;i++){
		;
	}
	root->left = build_tree(left+1,i-1);
	root->right = build_tree(i,right);
	return root;
}
link build_image_tree(int left,int right){
	if(left > right or left < 0 or right >=seq.size())
		return NULL;
	link root = new tree;
	root->val = seq[left];
	root->left = root->right = NULL;
	int i;
	for(i=left+1;i<=right and seq[i]>=root->val;i++){
		;
	}
	root->left = build_image_tree(left+1,i-1);
	root->right = build_image_tree(i,right);
	return root;
}
void in_order_traversal(link root){
	if(root == NULL) return;
	in_order_traversal(root->left);
	in.push_back(root->val);
	in_order_traversal(root->right);
}
void post_order_traversal(link root){
	if(root == NULL) return;
	post_order_traversal(root->left);
	post_order_traversal(root->right);
	post.push_back(root->val);
}
bool is_BST(){
	for(int i=1;i<in.size();i++){
		if(in[i]<in[i-1])
			return false;
	}
	return true;
}
bool is_img_BST(){
	for(int i=1;i<in.size();i++){
		if(in[i]>in[i-1])
			return false;
	}
	return true;
}
int main(){
	int N;
	scanf("%d",&N);
	seq.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&seq[i]);
	link root = build_tree(0,seq.size()-1);
	in_order_traversal(root);
	if(is_BST()){
		printf("YES\n");
		post_order_traversal(root);
		for(int i=0;i<post.size();i++){
			if(i!=0)
				printf(" ");
			printf("%d",post[i]);
		}
	}
	else{
		link img_root = build_image_tree(0,seq.size()-1);
		in.clear();
		in_order_traversal(img_root);
		if(is_img_BST()){
			printf("YES\n");
			post_order_traversal(img_root);
			for(int i=0;i<post.size();i++){
				if(i!=0)
					printf(" ");
				printf("%d",post[i]);
			}
		}
		else{
			printf("NO");
		}
	}
	return 0;
}