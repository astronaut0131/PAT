#include <iostream>
using namespace std;
struct finger_guess{
	int win;
	int lose;
	int tied;
	int B;
	int C;
	int J;
};
struct finger_guess X;
struct finger_guess Y;
char findmax(int a,int b,int c){
	int x[3];
	x[0]=a;
	x[1]=b;
	x[2]=c;
	int max=0;
	int temp;
	for(int i=0;i<=2;i++){
		if(x[i]>max){
			max=x[i];
			temp=i;
		}
	}
	if(temp==0){
		return 'B';
	}
	else if(temp==1){
		return 'C';
	}
	else if(temp==2){
		return 'J';
	}
}
void judge(char a,char b){
	if(a=='C'&&b=='J'){
		X.win++;
		Y.lose++;
		X.C++;
		return ;
	}
	if(a=='J'&&b=='C'){
		X.lose++;
		Y.win++;
		Y.C++;
		return ;
	}
	if(a=='B'&&b=='C'){
		X.win++;
		Y.lose++;
		X.B++;
		return ;
	}
	if(a=='C'&&b=='B'){
		X.lose++;
		Y.win++;
		Y.B++;
		return ;
	}
	if(a=='J'&&b=='B'){
		X.win++;
		Y.lose++;
		X.J++;
		return ;
	}
	if(a=='B'&&b=='J'){
		X.lose++;
		Y.win++;
		Y.J++;
		return ;
	}
}
int main(){
	X.B=0;
	X.C=0;
	X.J=0;
	X.lose=0;
	X.tied=0;
	X.win=0;
	Y.B=0;
	Y.C=0;
	Y.J=0;
	Y.lose=0;
	Y.tied=0;
	Y.win=0;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		char a,b;
		cin>>a>>b;
		if(a==b){
			X.tied++;
			Y.tied++;
		}
		else{
			judge(a,b);
		}
	}
	cout<<X.win<<" "<<X.tied<<" "<<X.lose<<endl;
	cout<<Y.win<<" "<<Y.tied<<" "<<Y.lose<<endl;
	cout<<findmax(X.B,X.C,X.J)<<" "<<findmax(Y.B,Y.C,Y.J);
	return 0;
}
