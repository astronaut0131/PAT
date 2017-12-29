#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int row_move[] = {1,-1,1,-1};
	int col_move[] = {1,1,-1,-1};
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		int flag = 0;
		scanf("%d",&num);
		bool exist[num+1];
		int board[num+1][num+1];
		fill(board[0],board[0]+(num+1)*(num+1),0);
		for(int j=1;j<=num;j++){
			int row;
			scanf("%d",&row);
			if(board[num-row+1][j] == -1){
				flag = 1;
			}
			if(not flag){
				for(int k=1;k<=num;k++){
					board[num-row+1][k] = -1;
				}
				for(int k=0;k<6;k++){
					int a = num-row+1 + row_move[k];
					int b = j + col_move[k];
					while(a<=num and a>=1 and b<=num and b>=1){
						board[a][b] = -1;
						a += row_move[k];
						b += col_move[k];
					}
				}
			}
		}
		if(not flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}	
	}
	return 0;
}
