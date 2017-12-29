#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
map <string,vector <int> > title_map;
map <string,vector <int> > author_map;
map <string,vector <int> > key_map;
map <string,vector <int> > pub_map;
map <string,vector <int> > year_map;
bool cmpInc(int a,int b){
	return a<b;
}
void handle_key_word(string x,int id){
	string temp = "";
	for(int i=0;i<x.length();i++){
		if(x[i] != ' '){
			temp += x[i];
		}
		else{
			key_map[temp].push_back(id);
			temp = "";
		}
	}
	key_map[temp].push_back(id);
}
void get_result(map <string,vector <int> > mapp,string query){
	if(mapp[query].size() == 0){
			cout<<"Not Found"<<endl;
		}
	else{
		sort(mapp[query].begin(),mapp[query].end(),cmpInc);
		for(int j=0;j<mapp[query].size();j++){
			printf("%07d\n",mapp[query][j]);
		}
	}
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int id;
		string year;
		string title;
		string author;
		string key_word;
		string publisher;
		cin>>id;
		getchar();
		getline(cin,title);
		getline(cin,author);
		getline(cin,key_word);
		getline(cin,publisher);
		cin>>year;
		title_map[title].push_back(id);
		author_map[author].push_back(id);
		pub_map[publisher].push_back(id);
		year_map[year].push_back(id);
		handle_key_word(key_word,id);
	}
	int M;
	cin>>M;
	getchar();
	for(int i=0;i<M;i++){
		int num;
		string query;
		getline(cin,query);
		num = query[0]-'0';
		cout<<query<<endl;
		query = query.substr(3,query.length()-3);
		if(num == 1) get_result(title_map,query);
		else if(num == 2) get_result(author_map,query);
		else if(num == 3) get_result(key_map,query);
		else if(num == 4) get_result(pub_map,query);
		else get_result(year_map,query);
	}
	return 0;
}
