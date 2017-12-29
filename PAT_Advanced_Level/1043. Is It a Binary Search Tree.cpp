#include <stdio.h>
#include <vector>
using namespace std;
typedef struct tree *link;
vector <int> img_pre;
vector <int> pre;
vector <int> given_pre;
vector <int> post;
vector <int> img_post;
struct tree{
	int data;
	link left;
	link right;
};
link insert(link root,int x){
	if(root == NULL){
		root = new tree;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
	else if(x >= root->data){
		root->right = insert(root->right,x);
	}
	else{
		root->left = insert(root->left,x);
	}
	return root;
}
link img_insert(link root,int x){
	if(root == NULL){
		root = new tree;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
	else if(x >= root->data){
		root->left = img_insert(root->left,x);
	}
	else{
		root->right = img_insert(root->right,x);
	}
	return root;
}
void preorder_traversal(link root,bool is_img){
	if(root == NULL) return;
	if(is_img) img_pre.push_back(root->data);
	else pre.push_back(root->data);
	preorder_traversal(root->left,is_img);
	preorder_traversal(root->right,is_img);
}
void postorder_traversal(link root,bool is_img){
	if(root == NULL) return;
	postorder_traversal(root->left,is_img);
	postorder_traversal(root->right,is_img);
	if(is_img) img_post.push_back(root->data);
	else post.push_back(root->data);
}
bool judge(bool is_img){
	if(is_img){
		for(int i=0;i<img_pre.size();i++){
			if(img_pre[i] != given_pre[i]){
				return false;
			}
		}
		return true;
	}
	else{
		for(int i=0;i<pre.size();i++){
			if(pre[i] != given_pre[i]){
				return false;
			}
		}
		return true;
	}
}
int main(){
	link root = NULL;
	link img_root = NULL;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		root = insert(root,x);
		img_root = img_insert(img_root,x);
		given_pre.push_back(x);
	}
	preorder_traversal(root,false);
	if(judge(false)){
		postorder_traversal(root,false);
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i!=post.size()-1) printf(" ");
		}
	}
	else{
		preorder_traversal(img_root,true);
		if(judge(true)){
			postorder_traversal(img_root,true);
			printf("YES\n");
			for(int i=0;i<img_post.size();i++){
				printf("%d",img_post[i]);
				if(i!=img_post.size()-1) printf(" ");
			}
		}
		else{
			printf("NO");
		}
	}
	return 0;
} 
