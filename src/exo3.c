#include "../include/imports.h"
#include "../include/exo3.h"

/*
 *fonction qui permet de vérifier si un mot est reconnu par l'automate
 */


void CheckWordRecognized(void){
		FILE *fp;
   		int states;
   		int i = 1;
   		int k = 0;
  		int trans = 0;
  		int fl_counter = 0;
		char line[256];
  		char start;
  		char *alphabet;
  		char *final;
  		char input[30];

		char *cs,*tr,*nw;
   		fp = fopen("automate.txt","r");
   		
   		if(fp == NULL)
   		{
   			perror("Erreur lors de l'ouverture du fichier");
      		return;
		}

    while (fgets(line, sizeof(line), fp))
	 {

 		if(i == 1)
      	{
      		states = atoi(line);
      		if(states >= 10) 
      		{
      			printf("L'automate doit avoir en dessous de 10 états (<10)!");
      			return;
			}
		}
 		
 		if(i == 2)
      	{
      		int cnt = 0;
      		int j = 0;

      		while(line[j] != '\n'){
				if(line[j] != ' '){
					cnt++;
					fl_counter++;
				}	
				j++;
			}
			
			alphabet = (char *)malloc(cnt * sizeof(char));
			
			j=0; cnt = 0;
      		while(line[j] != '\n') 
      		{
			  	if(line[j] != ' ')
					alphabet[cnt++] = line[j];
				j++;
			}
						
			if(cnt >= 10)
			{
				printf("L'alphabet doit avoir en dessous de 10 symboles différents (<10)!");
      			return;
			}
			
			trans = states * fl_counter;
    		
			cs = (char *)malloc(trans * sizeof(char));
    		tr = (char *)malloc(trans * sizeof(char));
    		nw = (char *)malloc(trans * sizeof(char));
		}
      	
      	if(i==3){
      		start = line[0];
		}
 	
 		if(i==4){
 			
 			int cnt = 0;
      		int j = 0;
      		
      		while(line[j] != '\n')
      		{	
				if(line[j] != ' '){ cnt++; }
				
				j++;
			}
 			
			final = (char *)malloc(cnt * sizeof(char));
			
			int k=0; j=0;

			while(line[j] != '\n') 
      		{
				if(line[j] != ' ')
				{ final[k++] = line[j]; }
				
				j++;
			}
		}

 		if(i > 4)
 		{	
			int j = 0;
 			while(line[j] != '\n') 
      		{
				if(line[j] != ' ')
				{
					if(j == 0)
						cs[k] = line[j];
					if(j == 2) 
						tr[k] = line[j];
					if(j == 4)
						nw[k] = line[j];
				}
				
					if(trans+4 == i && j == 4)
					break;
				
				j++;
			}
			
			k++;
		}

		i++;
    }



	char ch;
	do{

	fflush(stdin);
    printf("Donnez votre entrée:");
    fgets(input,30,stdin);

	if(CheckString(input,alphabet) == 0)
	  {
			printf("Mauvaise entrée!");
			return;
	  }
	  
    
    int length_in = strlen(input);
    char final_state = start;
    int flag = 0;
    
    for(i=0;i<length_in-1;i++)
	{
		int j = 0;
		flag = 0;

		for(j=0;j<trans;j++)
		{
			if(final_state == cs[j] && input[i] == tr[j])
			{
				printf("INPUT -> %c\nCURRENT_STATE -> q%c\n",input[i],final_state);
				final_state = nw[j];
				printf("NEW_STATE    -> 'q%c'\n\n",final_state);
				flag = 1;
			}
			
			if(flag==1)
			break;
		}		
	}
	
	fflush(stdin);
	
	flag = 0;
	
	for(i=0;i<strlen(final);i++)
	{
		if(final_state == final[i])
		flag = 1;	
	}    
	
	if(flag == 1)
	{
		printf("--------------------------");
		printf("\nEntrée acceptable!\n");
		printf("L'état final est :  q%c\n",final_state);
		printf("--------------------------");
	}
	else
	{
		printf("------------------------------");
		printf("\nVotre entrée est pas acceptable!\n");
		printf("L'état final est : q%c\n",final_state);
		printf("------------------------------");
	}
	
	printf ("\nVoulez-vous continuer? y/n: ");
	ch = getchar();
	system("clear");
	}while(ch == 'y' || ch == 'Y');
    
    free(final);
    free(alphabet);
    free(cs);
    free(tr);
    free(nw);
    
    fclose(fp);
    
	return;
}



/*
 *Vérification du mot
 *@param *string, *alphabet
 */

int CheckString(char *string,char *alphabet)
	{
        
		int i = 0, j = 0;
		int flag = 0;
		
        int s1 = strlen(string);
        int s2 = strlen(alphabet);
        
		for(i=0;i<s1-1;i++)
    	{
    		flag = 0;
    		for(j=0; j<s2; j++)
    		{	
    			if(string[i] == alphabet[j])
    			flag = 1;
			}
			  	
			if (flag == 0)
			return 0;

            
		}
		return 1;
	}
