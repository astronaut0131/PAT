#include <stdio.h>
#include <queue>
using namespace std;
typedef struct tree *link;
bool is_complete = true;
bool after = false;
int cnt = 0;
int N;
struct tree{
	int val;
	link left,right;
};
link insert(link root,int x){
	if(root == NULL){
		root = new tree;
		root->val = x;
		root->left = root->right = NULL;
	}
	else if(x > root->val){
		root->left = insert(root->left,x);
	}
	else{
		root->right = insert(root->right,x);
	}
	return root;
}
void level_traversal(link root){
	queue <link> Q;
	Q.push(root);
	while(not Q.empty()){
		link v = Q.front();
		Q.pop();
		cnt++;
		printf("%d",v->val);
		if(cnt == N)
			printf("\n");
		else
			printf(" ");
		if(v->left != NULL){
			if(after)
				is_complete = false;
			Q.push(v->left);
		}
		else if(not after)
			after = true;
		if(v->right != NULL){
			if(after)
				is_complete = false;
			Q.push(v->right);
		}
		else if(not after)
			after = true;
	}
}
int main(){
	scanf("%d",&N);
	link root = NULL;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		root = insert(root,x);
	}
	level_traversal(root);
	if(is_complete)
		printf("YES");
	else
		printf("NO");
	return 0;
}