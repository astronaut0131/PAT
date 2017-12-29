#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
	long long int ID;
	int virtue;
	int talent;
};
bool cmpDec(struct student A,struct student B){
	if((A.talent+A.virtue)!=(B.talent+B.virtue)){
		return (A.talent+A.virtue)>(B.talent+B.virtue);
	}
	else if(A.virtue!=B.virtue){
		return A.virtue>B.virtue;
	}
	else{
		return A.ID<B.ID;
	}
}
vector <student> sages;
vector <student> noblemen;
vector <student> fool_men;
vector <student> rest;
int N,L,H;
int main(){
    scanf("%d %d %d",&N,&L,&H);
	for(int i=0;i<N;i++){
		struct student x;
		scanf("%lld %d %d",&x.ID,&x.virtue,&x.talent);
		if(x.talent>=L&&x.virtue>=L){
			if(x.talent>=H&&x.virtue>=H){
				sages.push_back(x);
			}
			else if(x.talent<H&&x.virtue>=H){
				noblemen.push_back(x);
			}
			else if(x.virtue>=x.talent){
				fool_men.push_back(x);
			}
			else{
				rest.push_back(x);
			}
		}   
	}
	sort(sages.begin(),sages.end(),cmpDec);
	sort(noblemen.begin(),noblemen.end(),cmpDec);
	sort(fool_men.begin(),fool_men.end(),cmpDec);
	sort(rest.begin(),rest.end(),cmpDec);
	printf("%d\n",sages.size()+noblemen.size()+fool_men.size()+rest.size());
	for(int i=0;i<sages.size();i++){
		printf("%lld %d %d\n",sages[i].ID,sages[i].virtue,sages[i].talent);
	}
	for(int i=0;i<noblemen.size();i++){
		printf("%lld %d %d\n",noblemen[i].ID,noblemen[i].virtue,noblemen[i].talent);
	}	
	for(int i=0;i<fool_men.size();i++){
		printf("%lld %d %d\n",fool_men[i].ID,fool_men[i].virtue,fool_men[i].talent);
	}
	for(int i=0;i<rest.size();i++){
		printf("%lld %d %d\n",rest[i].ID,rest[i].virtue,rest[i].talent);
	}
	return 0;
}
