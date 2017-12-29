#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
  string name;
  string gender;
  string course;
  int mark;
};
int main(){
  int N;
  cin>>N;
  struct stu s[N];
  for(int i=0;i<N;i++){
      cin>>s[i].name>>s[i].gender>>s[i].course>>s[i].mark;
  }
  int maxx=-1;
  int minn=101;
  int m,f;
  for(int i=0;i<N;i++){
  	if(s[i].gender=="F"&&s[i].mark>maxx){
  		maxx=s[i].mark;
  		f=i;
	}
	if(s[i].gender=="M"&&s[i].mark<minn){
		minn=s[i].mark;
		m=i;
	}
  }
  if(maxx==-1){
  	cout<<"Absent"<<endl;
  }
  else{
  	cout<<s[f].name<<" "<<s[f].course<<endl;
  }
  if(minn==101){
  	cout<<"Absent"<<endl;
  }
  else{
  	cout<<s[m].name<<" "<<s[m].course<<endl;
  }
  if(minn==101||maxx==-1){
  	cout<<"NA";
  }
  else{
  	cout<<s[f].mark-s[m].mark;
  }
  return 0;
}
