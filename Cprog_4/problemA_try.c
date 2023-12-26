#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
        //the average prokaryote gene length is typically around 500-3000bp 
	char seq[3000];	
	while( scanf("%s",seq) == 1 )
	{
        	int lengthseq;
                lengthseq=strlen(seq);
              	int i, a,b, d;
		for(i=0; i<=lengthseq - 2; i++)
		{	
			if (seq[i] == 'A' & seq[i + 1] == 'T'  & seq[i + 2] == 'G')
                        {
                                char gene[lengthseq];
                               	int a, d;
                               	a = i + 3;
                               	for(d=a; d<=lengthseq; d++)
                               	{
                                       	int b;
                                       	if (seq[d] == 'T' && seq[d + 1] == 'A'  && seq[d + 2] == 'G' || seq[d + 2] == 'A')
                                       	{
                                               	for(b=a; b<=d+2; b++)
						{
							strncat(gene, &seq[d], 1);
						}
						printf("%s \n",gene);
                                        }
                                       	else if (seq[d] == 'T' && seq[d + 1] == 'G'  &&  seq[d + 2] == 'A')
                                       	{
                                               	for(b=a; b<=d+2; b++)
                                                       {
                                                               strncat(gene, &seq[d], 1);
                                                       }
                                                               printf("%s \n",gene);
                                       	}					
				}
                       	 }
		}
	}

}
