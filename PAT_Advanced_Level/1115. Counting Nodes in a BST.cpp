#include <stdio.h>
#include <vector>
using namespace std;
struct node{
	int value;
	struct node *left,*right;
};
node* build(node *root,int v){
	if(root == NULL){
		root = new node();
		root->value=v;
		root->left = root->right = NULL;
	}
	else if(root->value>=v){
		root->left = build(root->left,v);
	}
	else{
		root->right = build(root->right,v);
	}
	return root;
}
vector <int> num(1000);
int maxdepth = -1;
void dfs(node *root,int depth){
	if(root == NULL){
		maxdepth = max(depth,maxdepth);
		return ;
	}
	num[depth]++;
	dfs(root->left,depth+1);
	dfs(root->right,depth+1);
}
int main(){
	int N;
	scanf("%d",&N);
	node *root = NULL;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		root = build(root,x);
	}
	dfs(root,0);
	printf("%d + %d = %d",num[maxdepth-1],num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2]);
	return 0;
}
