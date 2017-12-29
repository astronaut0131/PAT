#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <int,vector <int> > course;
int get_hash(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++) {
        id = 26 * id + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}
int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++){
    int course_id,num;
    scanf("%d %d",&course_id,&num);
    for(int j=0;j<num;j++){
      char name[5];
      scanf("%s",name);
      course[get_hash(name)].push_back(course_id);
    }
  }
  for(int i=0;i<N;i++){
    char query[5];
    scanf("%s",query);
    int stu_id = get_hash(query);
    sort(course[stu_id].begin(),course[stu_id].end());
    printf("%s %d",query,course[stu_id].size());
    for(int j=0;j<course[stu_id].size();j++){
      printf(" %d",course[stu_id][j]);
    }
    printf("\n");
  }
}
