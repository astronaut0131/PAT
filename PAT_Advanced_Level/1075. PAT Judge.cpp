#include <stdio.h>
#include <algorithm>
using namespace std;
struct User{
	int user_id;
	int prob_sco[5];
	int sco_obt;
	bool exist;
	int pref_num;
	bool answered[5];
};
bool cmpSco(User A,User B){
	if(A.sco_obt!=B.sco_obt){
		return A.sco_obt > B.sco_obt;
	}
	else if(A.pref_num!=B.pref_num){
		return A.pref_num > B.pref_num;
	}
	else{
		return A.user_id < B.user_id;
	}
}
int main(){
	int user_num,prob_num,sub_num;
	scanf("%d %d %d",&user_num,&prob_num,&sub_num);
	User user[user_num];
	for(int i = 0;i<user_num;i++){
		user[i].user_id = i+1;
		user[i].sco_obt = 0;
		for(int j=0;j<prob_num;j++){
			user[i].prob_sco[j] = 0;
			user[i].answered[j] = false;
		}
		user[i].exist = false;
		user[i].pref_num = 0;
	}
	int prob_sco[prob_num];
	for(int i=0;i<prob_num;i++){
		scanf("%d",&prob_sco[i]);
	}
    for(int i=0;i<sub_num;i++){
    	int id,prob_id,score;
    	scanf("%d %d %d",&id,&prob_id,&score);
    	user[id-1].answered[prob_id-1] = true;
    	if(score!=-1){
    		user[id-1].exist = true;
		}
    	if(score>user[id-1].prob_sco[prob_id-1]){
    		user[id-1].sco_obt -= user[id-1].prob_sco[prob_id-1];
    		user[id-1].prob_sco[prob_id-1] = score;
    		user[id-1].sco_obt += score;
    		if(score == prob_sco[prob_id-1]){
    			user[id-1].pref_num++;
			}
		}
		
	}
	sort(user,user+user_num,cmpSco);
	int last_score = -1;
	int same_score = 1;
	int rank = 0;
	for(int i=0;i<user_num;i++){
		if(user[i].exist){
			if(user[i].sco_obt!= last_score){
				rank += same_score;			
				last_score = user[i].sco_obt;
				same_score = 1;      
			}
			else{
				same_score++;
			}
			printf("%d %05d %d",rank,user[i].user_id,user[i].sco_obt);
			for(int j=0;j<prob_num;j++){
				if(user[i].answered[j]){
					printf(" %d",user[i].prob_sco[j]);
				}
				else{
					printf(" -");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
