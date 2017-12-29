#include <stdio.h>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <string> card;
string int2string(int x){
	stringstream s;
	s<<x;
	return s.str();
}
int main(){
	for(int i=1;i<=52;i++){
		if(i<=13) card.push_back("S"+ int2string(i));
		else if(i<=26) card.push_back("H" +int2string(i-13));
		else if(i<=39) card.push_back("C" + int2string(i-26));
		else if(i<=52) card.push_back("D" + int2string(i-39));
	}
	card.push_back("J1");
	card.push_back("J2");
	int N;
	scanf("%d",&N);
	int shuffle[54];
	for(int i=0;i<54;i++){
		scanf("%d",&shuffle[i]);
	}
	for(int i=0;i<N;i++){
		vector <string> v;
		v.resize(54);
		for(int j=0;j<54;j++){
			v[shuffle[j]-1] = card[j];
		}
		card = v;
	}
	for(int i=0;i<card.size();i++){
		if(i!=0) printf(" ");
		cout<<card[i];
	}
	return 0;
}

