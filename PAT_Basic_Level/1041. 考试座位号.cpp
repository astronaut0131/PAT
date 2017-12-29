#include <iostream>
#include <string>
using namespace std;
struct student{
	string a;
	int b;
}stu[1005];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int temp1,temp2;
		string temp;
		cin>>temp>>temp1>>temp2;
		stu[temp1].a=temp;
		stu[temp1].b=temp2;
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int x;
		cin>>x;
		cout<<stu[x].a<<" "<<stu[x].b<<endl;
	}
	return 0;
}
