#include <stdio.h>
#include <map>
#include <set>
using namespace std;
struct node{
	int val,cnt;
	node(int a,int b):val(a),cnt(b){
	}
	bool operator < (const node &a) const{
		return cnt!=a.cnt? cnt>a.cnt:val<a.val;
	}
};
map<int,int> cnt;
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	set<node> s;
	for(int i=0;i<N;i++){
		int query;
		scanf("%d",&query);
		if(i!=0){
			printf("%d:",query);
			int tempCnt = 0;
			for(set<node>::iterator it = s.begin();it!=s.end() and tempCnt<K;it++){
				printf(" %d",it->val);
				tempCnt++;
			}
			printf("\n");
		}
		set<node>::iterator it = s.find(node(query,cnt[query]));
		if(it!=s.end()) s.erase(it);
		cnt[query]++;
		s.insert(node(query,cnt[query]));
	}
	return 0;
}
