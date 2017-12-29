#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		char temp[20];
		scanf("%s",temp);
		int num;
		sscanf(temp,"%d",&num);
		int half = strlen(temp) / 2;
		int left = num / int(pow(10,half));
		int right = num % int(pow(10,half));
		if(right != 0 and num % (left * right) == 0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
