#include <stdio.h>
#include <algorithm>
#include <cctype>
using namespace std;
struct Link{
	char key;
	int next;
	bool flag;
}node[100005];
int main(){
	int head1,head2,N;
	scanf("%d %d %d",&head1,&head2,&N);
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		getchar();
		scanf("%c %d",&node[temp].key,&node[temp].next);
	}
    bool find = false;
	for(int i=head1;i!=-1;i=node[i].next){
		node[i].flag = true;
	}
	for(int i=head2;i!=-1;i=node[i].next){
		if(node[i].flag){
			printf("%05d",i);
			find = true;
			break;
		}
	}
	if(not find){
		printf("-1");
	}
	return 0;
}
