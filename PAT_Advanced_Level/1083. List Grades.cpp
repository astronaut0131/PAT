#include <iostream>
#include <algorithm>
using namespace std;
struct student{
	string name;
	string major;
	int score;
};
bool cmpInc(struct student A,struct student B){
	return A.score>B.score;
}
int main(){
	int N;
	
    cin>>N;
    struct student s[N];
	for(int i=0;i<N;i++){
		cin>>s[i].name>>s[i].major>>s[i].score;
	}
	int a,b;
	cin>>a>>b;
	int flag=0;
	sort(s,s+N,cmpInc);
	for(int i=0;i<N;i++){
		if(s[i].score>=a&&s[i].score<=b){
			cout<<s[i].name<<" "<<s[i].major<<endl;
			flag=1;
		}
	}
	if(flag==0){
		cout<<"NONE";
	}
	return 0;
}
