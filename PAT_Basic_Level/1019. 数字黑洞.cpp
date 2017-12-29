#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmpDec(int a,int b){
	return a>b;
}
bool cmpInc(int a,int b){
	return a<b;
}
int main(){
	int N;
	int sDec[4],sInc[4];
	scanf("%d",&N);
	if(N%1111==0){
		printf("%d - %d = 0000",N,N);
	}
	else{
		while(1){
		int temp;
		int count=0;
		while(1){
			temp=N%10;
			sDec[count]=temp;
			sInc[count]=temp;
			count++;
			if(count==4){
				break;
			}
			N=(N-temp)/10;
		}
		int Dec=0,Inc=0;
		sort(sDec,sDec+4,cmpDec);
		sort(sInc,sInc+4,cmpInc);
		for(int i=0;i<4;i++){
			Dec+=sDec[i]*pow(10,3-i);
			Inc+=sInc[i]*pow(10,3-i);
		}
		printf("%04d - %04d = %04d\n",Dec,Inc,Dec-Inc);
		if(Dec-Inc==6174){
			break;
		}
		else{
			N=Dec-Inc;
		}
		}
	}
	return 0;
}
