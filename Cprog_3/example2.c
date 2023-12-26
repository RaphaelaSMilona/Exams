#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char seq[ 1000 ];
	int length;
	while (scanf("%s", seq) ==1)
	{
 	int count;
        count =0;
		length=strlen(seq);
			int i;
			for (i=0; i <=length; i++)
			{
				if ( seq[i] == 'G'|| seq[i] =='C')
				{
					count++;
				}
			}
	printf("=> %.1f\n",(count*100.0)/length);
	}
}

