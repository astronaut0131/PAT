#include <stdio.h>
#include <vector>
using namespace std;
vector <int> v;
int main(){
    int L,N;
    scanf("%d %d",&L,&N);
    int x;
    N -= 1;
    while(1){
        if(N==0)
            break;
        x = N%26;
        v.push_back(x);
        N /= 26;
    }
    while(v.size()<L){
        v.push_back(0);
    }
    for(int i=v.size()-1;i>=0;i--){
        printf("%c",'z'-v[i]);
    }
    return 0;
}