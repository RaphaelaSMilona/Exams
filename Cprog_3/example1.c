#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char seq[ 1000 ];
	int length;
	scanf("%s", seq);
	length=strlen(seq);
	int count;
	count = 0;
	int i;
	for (i=0; i <=1000; i++)
	{
		if ( seq[i] == 'G'|| seq[i] =='C')
		{
			count++;
		}
	}
printf("=> %f\n",count*100.0/length);
}

