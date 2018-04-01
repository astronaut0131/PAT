#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	set <int> queue_back;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int train_id;
		scanf("%d",&train_id);
		bool queue_found = false;
		for(set <int>::iterator it=queue_back.begin();it!=queue_back.end();it++){
			if(train_id < *it){
				queue_found = true;
				*it = train_id;
				break;
			}
		}
		if(not queue_found){
			queue_back.push_back(train_id);
		}
	}
	printf("%lu",queue_back.size());
	return 0;
}