#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct people{
	string name;
	int age;
	int worth;
};
bool cmpDec(struct people A,struct people B){
	if(A.worth!=B.worth){
		return A.worth>B.worth;
	}
	else{
		if(A.age!=B.age){
			return A.age<B.age;
		}
		else{
			return A.name<B.name;
		}
	}
}
vector <people> v;
vector <int> book(205,0);
int main(){
	int N,K;
	
	cin>>N>>K;
	struct people peo[N];
	for(int i=0;i<N;i++){
		cin>>peo[i].name>>peo[i].age>>peo[i].worth;
	}
	sort(peo,peo+N,cmpDec);
	for(int i=0;i<N;i++){
		if(book[peo[i].age]<100){
			v.push_back(peo[i]);
		}
		book[peo[i].age]++;
	}
	for(int i=0;i<K;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int cnt=0;
		cout<<"Case #"<<i+1<<":"<<endl;
		for(int j=0;j<N;j++){
			if(v[j].age>=b&&v[j].age<=c){
				cout<<v[j].name<<" "<<v[j].age<<" "<<v[j].worth<<endl;
				cnt++;
				if(cnt==a){
					break;
				}
			}
		}
		if(cnt==0){
			cout<<"None"<<endl;
		}
	}
	return 0;
}
