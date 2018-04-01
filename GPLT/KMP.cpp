#include <stdio.h>
#include <string.h>
using namespace std;
void getNext(char *p,int *next)
{
	next[0] = -1;
	int i=0,j=-1;
	while(i<strlen(p))
	{
		if(j == -1 or p[i] == p[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}