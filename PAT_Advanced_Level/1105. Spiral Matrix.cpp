#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmpDec(int A,int B){
	return A>B;
}
int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N,cmpDec);
	int m,n;
	for(int i=sqrt(N);i>=1;i--){
		if(N%i == 0){
			n = i;
			m = N/i;
			break;
		}
	}
	int matrix[m][n];
	int level = n%2+n/2;
	int index = 0;
	for(int i = 0;i<level;i++){
		for(int j=i;j<=n-1-i and index<N;j++){
			matrix[i][j] = arr[index++];
		}
		for(int j=i+1;j<=m-1-i and index<N;j++){
			matrix[j][n-1-i] = arr[index++];
		}
		for(int j=n-2-i;j>=i and index<N;j--){
			matrix[m-1-i][j] = arr[index++];
		}
		for(int j=m-2-i;j>=i+1 and index<N;j--){
			matrix[j][i] = arr[index++];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",matrix[i][j]);
			if(j!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
