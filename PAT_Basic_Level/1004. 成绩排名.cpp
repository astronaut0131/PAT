#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	int max=0,min=100;
	cin>>n;
	string max_name,max_num;
	string min_name,min_num;
	for(int i=0;i<n;i++){
		string a,b;
		int c;
		cin>>a>>b>>c;
		if(c>max){
			max_name=a;
			max_num=b;;
			max=c;
		}
		if(c<min){
			min_name=a;
			min_num=b;
			min=c;
		}
	}
	cout<<max_name<<" "<<max_num<<endl<<min_name<<" "<<min_num;
	return 0;
}
