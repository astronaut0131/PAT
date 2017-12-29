#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
typedef struct node *link;
vector <int> pre;
vector <int> post;
struct node{
	int val;
	link left;
	link right;
};
bool is_unique = true;
int N;
bool same_vector(vector <int> v1,vector <int> v2){
	map <int,int> mapp;
	for(int i=0;i<v1.size();i++){
		mapp[v1[i]] = 1;
	}
	for(int i=0;i<v2.size();i++){
		if(mapp[v2[i]]!=1) return false;
	}
	return true;
}
int compareElement(int a,int b,int c,int d){
	vector <int> v1;
	vector <int> v2;
	int num = 0;
	for(int i=0;i<=b-a;i++){
		v1.push_back(pre[a+i]);
		v2.push_back(post[c+i]);
		if(same_vector(v1,v2)){
			num = i;
			break;
		}
	}
	return num;
}
link buildTree(link root,int preLeft,int preRight,int postLeft,int postRight){
	if(preLeft > preRight or postLeft > postRight) return NULL;
	root = new node;
	root->left = root->right = NULL;
	root->val = pre[preLeft];
	if(preLeft == preRight or postLeft == postRight) return root;
	int mid = compareElement(preLeft+1,preRight,postLeft,postRight-1);
	if(mid + preLeft +1 == preRight){
		is_unique = false;
		root->right = buildTree(root->right,preLeft+1,preRight,postLeft,postRight-1);
	}
	else{
		root->left = buildTree(root->left,preLeft+1,preLeft+1+mid,postLeft,postLeft+mid);
		root->right = buildTree(root->right,preLeft+mid+2,preRight,postLeft+mid+1,postRight-1);
	}
	return root;
}
vector <int> res;
void InOrder(link tree){
	if(tree == NULL) return;
	InOrder(tree->left);
	res.push_back(tree->val);
	InOrder(tree->right);
}
int main(){
	scanf("%d",&N);
	pre.resize(N);
	post.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	link tree = NULL;
	tree = buildTree(tree,0,N-1,0,N-1);
	if(is_unique){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	InOrder(tree);
	for(int i=0;i<res.size();i++){
		if(i!=0) printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;
}
