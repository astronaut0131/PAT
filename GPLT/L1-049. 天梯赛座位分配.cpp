#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector < vector <int> > member;
int main(){
    int N;
    scanf("%d",&N);
    int N_cpy = N;
    int mem_num[N+1];
    member.resize(N+1);
    for(int i=1;i<=N;i++){
        scanf("%d",&mem_num[i]);
        mem_num[i] *= 10;
    }
    int index = 1;
    while(1){
        for(int i=1;i<=N;i++){
            if(mem_num[i]!=0){
                member[i].push_back(index);
                if(N_cpy == 1)
                    index += 2;
                else
                    index += 1;
                mem_num[i]--;
                if(mem_num[i] == 0)
                    N_cpy--;
            }
        }
        if(N_cpy == 0)
            break;
    }
    for(int i=1;i<=N;i++){
        printf("#%d\n",i);
        for(int j=0;j<member[i].size()/10;j++){
            for(int k=0;k<10;k++){
                if(k!=0)
                    printf(" ");
                printf("%d",member[i][j*10+k]);
            }
            printf("\n");
        }
    }    
    return 0;
}