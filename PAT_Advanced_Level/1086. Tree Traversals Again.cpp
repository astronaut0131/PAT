#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
int pre[35];
int in[35];
vector <int> v;
int N;
void postTraversal(int root,int start,int end){
	if(start>end){
		return;
	}
	int i=start;
	while(i<end&&in[i]!=pre[root]) i++;
	postTraversal(root+1,start,i-1);
	postTraversal(root+i-start+1,i+1,end);
	v.push_back(pre[root]);
}
int main(){
	scanf("%d",&N);
	getchar();
	int cnt_p=0;
	int cnt_i=0;
	stack <int> s;
	for(int i=0;i<2*N;i++){
		string x;
		getline(cin,x);
		if(x[1]=='u'){
			int num=0;
			for(int j=5;j<x.length();j++){
				num+=pow(10,x.length()-1-j)*(x[j]-'0');
			}
			pre[cnt_p]=num;
			cnt_p++;
			s.push(num);
		}
		else{
			in[cnt_i]=s.top();
			s.pop();
		    cnt_i++;
		}
	}
	postTraversal(0,0,N-1);
	for(int i=0;i<v.size();i++){
		printf("%d",v[i]);
		if(i!=v.size()-1){
			printf(" ");
		}
	}
	return 0;
}
