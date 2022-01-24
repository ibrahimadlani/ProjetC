#include "../include/imports.h"
#include "../include/exo2.h"

char G_state[15]="";
char G_initialState[15];
char G_finiteState[15];
int G_transactionNbr;

void saveAEF(int nombredetat,char state[],char initialState[],char finiteState[],int transactionNbr){

    FILE *f = fopen("automate.txt", "w");
    
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f,"%d\n", nombredetat);

    fprintf(f, "%s\n", state);

    fprintf(f, "%s\n", initialState);

    fprintf(f, "%s\n", finiteState);

    char transaction[20];

    for(int i = 0 ; i < transactionNbr ; i++){

        printf("entrer votre transaction ex : ");
        scanf("%s",transaction);

        fprintf(f, "%s\n", transaction);
    }
    
    fclose(f);
}

void enterAEF(void){

    char state[15];
    char initialState[15];
    char finiteState[15];
    int transactionNbr = 0;
    int nombredetat = 0;

    printf("entrer le nombre d'etat : ");
    scanf("%d", &nombredetat);

    printf("entrer les symboles de l'automate ");
    scanf("%s", state);

    printf("entrer les etats iniale : ");
    scanf("%s",initialState);

    printf("entrer les etats final : ");
    scanf("%s", finiteState);

    printf("entrer le nombre de transaction : ");
    scanf("%d", &transactionNbr);

    saveAEF(nombredetat,state,initialState,finiteState,transactionNbr);

}


void importAEF(){

    FILE* f = fopen("automate.txt", "r");

    if(!f){
        printf("\n Unable to open : %s ", "automate.txt");
    }

    char line[500];
    int i=0;

    while (fgets(line, sizeof(line), f)) {
        if(i==0){
            printf("les etats de l'automate est : %s",line);
            strcpy(G_state,line);
        }else if(i==1){
            printf("les etats initiale est : %s",line);
            strcpy(G_initialState,line);
        }else if(i==2){
            printf("les etats de final est : %s",line);
            strcpy(G_finiteState,line);
        }else{
            printf("transaction %d : %s",i-2 ,line);
        }
        i++;
    }

    G_transactionNbr = i-2;
    
    fclose(f);
}

void editeAEF(){

    FILE* f = fopen("automate.txt", "r");

    if(!f){
        printf("\n Unable to open : %s ", "automate.txt");
    }

    char line[500];
    int i=0;
    char choix[5];

    while (fgets(line, sizeof(line), f)) {
        if(i==0){

            printf("\nles etats de l'automate est : %s tu veux changer (y/n): ",line);
            strcpy(G_state,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("\nentrer tous les etats ex : ");
                scanf("%s", G_state);
            }

        }else if(i==1){

            printf("\nles etats initiale est : %s tu veux changer (y/n): ",line);
            strcpy(G_initialState,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("\nentrer les etats initiale : ");
                scanf("%s", G_initialState);
            }
        }else if(i==2){

            printf("\nles etats de final est : %s tu veux changer (y/n): ",line);
            strcpy(G_finiteState,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("entrer les etats final : ");
                scanf("%s", G_finiteState);
            }

        }else{
            printf("\ntransaction %d : %s",i-2 ,line);
        }
        i++;
    }

    G_transactionNbr = i-3;
    printf("\nle nombre des transaction %d tu veux changer (y/n): ",G_transactionNbr);
    
    saveAEF(G_state,G_initialState,G_finiteState,G_transactionNbr);

    fclose(f);
}
