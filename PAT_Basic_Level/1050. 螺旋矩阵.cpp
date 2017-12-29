#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool cmpDec(int a,int b){
	return a>b;
}
int main(){
	int N;
	int m,n;
	scanf("%d",&N);
	vector <int> a(N);
	for(int i=sqrt(N);i>=1;i--){
		if(N%i==0){
			n=i;
			m=N/i;
			break;
		}
	}
	vector < vector <int> > b(m,vector<int>(n));
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end(),cmpDec);
	int level = n%2+n/2;
	int cnt=0;
	for(int i=0;i<level;i++){
		for(int j=i;j<=n-1-i&&cnt<N;j++){
			b[i][j]=a[cnt];
			cnt++;
		}
		for(int j=i+1;j<=m-1-i&&cnt<N;j++){
			b[j][n-1-i]=a[cnt];
			cnt++;
		}
		for(int j=n-i-2;j>=i&&cnt<N;j--){
			b[m-1-i][j]=a[cnt];
			cnt++;
		}
		for(int j=m-i-2;j>=i+1&&cnt<N;j--){
			b[j][i]=a[cnt];
			cnt++;
		}
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",b[i][j]);
			if(j!=n-1){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
	return 0;
}
