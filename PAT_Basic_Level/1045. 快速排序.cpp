#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<int,int> a;
map<int,int>::iterator iter;
vector <int> b;
int pos_max[100000];
int main(){
  int count=0;
  int N;
  scanf("%d",&N);
  int arr[N];
  pos_max[0]=0;
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
    a.insert(pair<int,int>(arr[i],i));
    if(i!=0){
    	if(arr[i]>pos_max[i-1]){
    		pos_max[i]=arr[i];
		}
		else{
			pos_max[i]=pos_max[i-1];
		}
	}
  }
  sort(arr,arr+N);
  for(int i=0;i<N;i++){
    iter=a.find(arr[i]);
    if(i==iter->second&&pos_max[iter->second-1]<arr[i]){
      count++;
      b.push_back(arr[i]);
    }
  }
  printf("%d\n",count);
  if(count==0){
  	printf("\n");
  }
  for(int i=0;i<b.size();i++){
    printf("%d",b[i]);
    if(i!=b.size()-1){
      printf(" ");
    }
  }
  return 0;
}
