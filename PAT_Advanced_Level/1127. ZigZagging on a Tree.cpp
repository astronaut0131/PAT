#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef struct node *link;
struct node{
	int val;
	link left,right;
};
vector <int> inorder;
vector <int> postorder;
vector <int> res;
map <link,int> level;
map <int,vector <int> > single_level;
int max_level = -1;
link build_tree(link tree,int inL,int inR,int postL,int postR){
	if(inL > inR or postL > postR) return NULL;
	tree = new node;
	tree->left = tree->right = NULL;
	tree->val = postorder[postR];
	int pos;
	for(int i=inL;i<=inR;i++){
		if(inorder[i] == tree->val){
			pos = i;
			break;
		}
	}
	tree->left = build_tree(tree->left,inL,pos-1,postL,postL+(pos-inL)-1);
	tree->right = build_tree(tree->right,pos+1,inR,postL+(pos-inL),postR-1);
	return tree;
}
void levelOrder(link tree){
	queue <link> q;
	q.push(tree);
	level[tree] = 0; 
	while(not q.empty()){
		link temp = q.front();
		single_level[level[temp]].push_back(temp->val);
		if(level[temp] > max_level){
			max_level = level[temp];
		}
		q.pop();
		if(temp->left != NULL){
			q.push(temp->left);
			level[temp->left] = level[temp] + 1;
		}
		if(temp->right != NULL){
			q.push(temp->right);
			level[temp->right] = level[temp] + 1;
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	inorder.resize(N);
	postorder.resize(N);
	link tree = NULL;
	for(int i=0;i<N;i++){
		scanf("%d",&inorder[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&postorder[i]);
	}
	tree = build_tree(tree,0,N-1,0,N-1);
	levelOrder(tree);
	int flag = 0;
	for(int i=0;i<=max_level;i++){
		if(i%2!=0){
			for(int j=0;j<single_level[i].size();j++){
				if(flag) printf(" ");
				printf("%d",single_level[i][j]);
				flag = 1;
			}
		}
		else{
			for(int j=single_level[i].size()-1;j>=0;j--){
				if(flag) printf(" ");
				printf("%d",single_level[i][j]);
				flag = 1;
			}
		}
	}
	return 0;
}
