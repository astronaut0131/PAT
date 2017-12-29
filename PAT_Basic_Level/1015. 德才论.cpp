#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct group{
	int ID;
	int Dmark;
	int Cmark;
};
vector <group> a,b,c,d;
bool cmpDec(group A,group B){
	int sumA=A.Cmark+A.Dmark;
	int sumB=B.Cmark+B.Dmark;
	if(sumA!=sumB){
		return sumA>sumB;
	}
	else if(A.Dmark!=B.Dmark){
		return A.Dmark>B.Dmark;
	}
	else{
		return A.ID<B.ID;
	}
}
int main(){
	int N,L,H;
	scanf("%d %d %d",&N,&L,&H);
	for(int i=0;i<N;i++){
		struct group temp;
		scanf("%d %d %d",&temp.ID,&temp.Dmark,&temp.Cmark);
		if(temp.Dmark>=L&&temp.Cmark>=L){
			if(temp.Dmark>=H&&temp.Cmark>=H){
				a.push_back(temp);
			}
			else if(temp.Dmark>=H){
				b.push_back(temp);
			}
			else if(temp.Cmark<H&&temp.Dmark<H&&temp.Dmark>=temp.Cmark){
				c.push_back(temp);
			}
			else{
				d.push_back(temp);
			}
		}
	}
	sort(a.begin(),a.end(),cmpDec);
	sort(b.begin(),b.end(),cmpDec);
	sort(c.begin(),c.end(),cmpDec);
	sort(d.begin(),d.end(),cmpDec);
	printf("%d\n",a.size()+b.size()+c.size()+d.size());
    for(int i=0;i<a.size();i++){
    	struct group temp=a[i];
    	printf("%d %d %d\n",temp.ID,temp.Dmark,temp.Cmark);
	}
	for(int i=0;i<b.size();i++){
		struct group temp=b[i];
		printf("%d %d %d\n",temp.ID,temp.Dmark,temp.Cmark);
	}
	for(int i=0;i<c.size();i++){
		struct group temp=c[i];
		printf("%d %d %d\n",temp.ID,temp.Dmark,temp.Cmark);
	}
	for(int i=0;i<d.size();i++){
		struct group temp=d[i];
		printf("%d %d %d\n",temp.ID,temp.Dmark,temp.Cmark);
	}
	return 0;
}
