#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	//the average prokaryote gene length is typically around 500-3000bp
	char seq[3000];
	char identifier[3000];
	int countR,countI; // the counter makes sure in the program that the identifier printed is the one right before the sequence
	while( scanf("%s",seq) == 1 )
	{
		countR++;
        	int lengthseq;
                lengthseq=strlen(seq);
              	int i, a,b, d;
		char gene[lengthseq];
		char message[50];
		if( seq[0]=='>' || seq[0]=='@')//typical FASTA or FASTQ files have formats like >identifier or @identifier, but this can be modified
                {
                       strncpy(identifier,seq,lengthseq);
                       identifier[lengthseq]='\0';
			countI=countR;
                }
		//this turns all noucleotides to uppercase letters as this is the prerequisite in the if loops
		for(a=0; a<=lengthseq; a++)
                {
                        seq[a]=toupper(seq[a]);
                }
		for(i=0; i<lengthseq; i++)
                {
			//This makes sure that the algorithm reads nucleic acid sequences, N represents an ambiguous base 
			if(seq[i]=='A' || seq[i]=='T' || seq[i]=='G' || seq[i]=='C'|| seq[i]=='N') 
                	{ 
				//this is the main algorithm that finds the start and end codons and prints the coding sequence	
				for(i=0; i<=lengthseq - 2; i++)
				{
					if (seq[i] == 'A' && seq[i + 1] == 'T'  && seq[i + 2] == 'G') //start codon
                  	   		{
                  		             	for (d=i+3; d<=lengthseq; d++) //the codons consist of 3 nucleotidea
                        		       	{
							char codon[4];
							strncpy(codon, seq+d, 3);
							codon[3]='\0'; //this properly terminates the string
                                	       		if(strcmp(codon,"TGA") == 0 || strcmp(codon, "TAA") == 0 || strcmp(codon,"TAG")== 0 ) //strcmp compares the  lexical relationship of two string and returns 0 when they are the same
							{
									strncpy(gene, seq+i, d+2-i+1);
									gene[d+2-i+1]='\0'; //this properly terminates the string
									if(strlen(gene)%3 == 0) // prokaryotic sequences  do not have introns
									{
										if(strlen(gene)>100) // typically genes are larger than 100n
										{
											if(strlen(identifier) != 0 && (countR==countI+1)) // if the file of sequences provided doesn't contain identifiers the program shouldn't print anything there
											{
												printf("%s\n",identifier);
											}
											printf("%s \n", gene);
										}
										else
										{
 											if(strlen(identifier) != 0 && (countR==countI+1))
                                                                                        {
                                                                                                printf("%s\n",identifier);
                                                                                        }
											printf("%s *This is most likely not a gene \n", gene);
										}
									}
									else if(strlen(gene)%3 != 0)
									{
										if(strlen(gene)>100)
										{
											printf("The sequence ");
											if(strlen(identifier) != 0 && (countR==countI+1))
                                                                                        	{
                                                                                                	printf("with the identifier %s ",identifier);
                                                                                        	}
											printf("may be a gene containing introns and needs to be analazed with another tool.\n");
										}
										else
										{
											printf("The sequence ");
											if(strlen(identifier) != 0 && (countR==countI+1))
                                                                                        	{
                                                                                                	printf("with the identifier %s ",identifier);
                                                                                        	}
											printf("may be a gene containing introns and needs to be analazed with another tool. But it most likely is not a gene.\n");
											
										}
									}
									i=lengthseq;
									d=lengthseq;
									b=d+2;
							}
						}
                       	 		}
				}
			}
			else if (seq[0] != '>' && strlen(gene)==0) // The sequence is neither an identifier nor constains exclusively the 4 nucleotides
			{
				strcpy(message,"There are invalid characters in this sequence");
			}
		}
		if (strlen(message) != 0)
		{
			printf("%s\n", message);
		}
		gene[0]= '\0';
		message[0]= '\0';
	}
return 0;
}

