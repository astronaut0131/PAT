#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int sum = 0;
	int temp;
	int result[100];
	int count = 0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		sum+=s[i]-'0';
	}
    while(1){
    	temp = sum % 10;
    	result[count]=temp;
    	count++;
    	if(temp == sum){
    		break;
		}
		
    	sum=(sum-temp)/10;
	}
	for(int i=count-1;i>=0;i--){
		switch(result[i]){
			case 0:cout<<"ling";break;
			case 1:cout<<"yi";break;
			case 2:cout<<"er";break;
			case 3:cout<<"san";break;
			case 4:cout<<"si";break;
			case 5:cout<<"wu";break;
			case 6:cout<<"liu";break;
			case 7:cout<<"qi";break;
			case 8:cout<<"ba";break;
			case 9:cout<<"jiu";break;
		}
		if(i!=0){
			cout<<" ";
		}
	}
	return 0;
} 
