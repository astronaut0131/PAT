#include <stdio.h>
using namespace std;
long int a[1000005];
long int b[1000005];
int main(){
  int N,M;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%ld",&a[i]);
  }
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    scanf("%ld",&b[i]);
  }
  int cnt = 0;
  int mid = (N+M)%2==0?(N+M)/2-1:(N+M)/2;
  int p1=0,p2=0;
  long int last_num;
  while(cnt <= mid){
    if(p1>=N){
      last_num = b[p2];
      p2++;  
    } 
    else if(p2>=M){
      last_num = a[p1];
      p1++;
    } 
    else if(a[p1] < b[p2]){
      last_num = a[p1];
      p1++;  
    } 
    else{
      last_num = b[p2];
      p2++;
    } 
    cnt++;
  }
  printf("%ld",last_num);
  return 0;
}
