#include "../include/imports.h"
#include "../include/exo2.h"

char G_state[15]="";
char G_initialState[15];
char G_finiteState[15];
int G_transactionNbr;
/*
 *fonction qui permet de sauvegarder l'automate
 *@param nombredetat,state[], initialState[],  finiteState[], transactionNbr
 */
void saveAEF(int nombredetat,char state[],char initialState[],char finiteState[],int transactionNbr){

    FILE *f = fopen("automate.txt", "w");
    
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier!\n");
        exit(1);
    }
    fprintf(f,"%d\n", nombredetat);

    fprintf(f, "%s\n", state);

    fprintf(f, "%s\n", initialState);

    fprintf(f, "%s\n", finiteState);

    char transaction[20];

    for(int i = 0 ; i < transactionNbr ; i++){

        printf("Entrer votre transition : ");
        scanf("%s",transaction);

        fprintf(f, "%s\n", transaction);
    }
    
    fclose(f);
}

/*
 *fonction qui permet de saisir un automate wesh 
 *@param nombredetat,state[], initialState[],  finiteState[], transactionNbr
 */

void enterAEF(void){

    char state[15];
    char initialState[15];
    char finiteState[15];
    int transactionNbr = 0;
    int nombredetat = 0;

    printf("Entrer le nombre d'états : ");
    scanf("%d", &nombredetat);

    printf("Entrer les états/symboles de l'automate ");
    scanf("%s", state);

    printf("Entrer l'état initial : ");
    scanf("%s",initialState);

    printf("Entrez l'état final : ");
    scanf("%s", finiteState);

    printf("Entrez le nombre de transitions : ");
    scanf("%d", &transactionNbr);

    saveAEF(nombredetat,state,initialState,finiteState,transactionNbr);

}

/*
 *fonction qui permet d'importer un automate a partir d'un fichier
 */

void importAEF(){

    FILE* f = fopen("automate.txt", "r");

    if(!f){
        printf("\n Impossible d'ouvrir : %s ", "automate.txt");
    }

    char line[500];
    int i=0;

    while (fgets(line, sizeof(line), f)) {
        if(i==0){
            printf("Les états de l'automate sont : %s",line);
            strcpy(G_state,line);
        }else if(i==1){
            printf("Les états initiaux sont : %s",line);
            strcpy(G_initialState,line);
        }else if(i==2){
            printf("Les états finaux sont : %s",line);
            strcpy(G_finiteState,line);
        }else{
            printf("Transition %d : %s",i-2 ,line);
        }
        i++;
    }

    G_transactionNbr = i-2;
    
    fclose(f);
}

/*
 *fonction qui permet de modifier l'automate
 */

void editeAEF(){

    FILE* f = fopen("automate.txt", "r");

    if(!f){
        printf("\n Impossible d'ouvrir : %s ", "automate.txt");
    }

    char line[500];
    int i=0;
    char choix[5];

    while (fgets(line, sizeof(line), f)) {
        if(i==0){

            printf("\nLes états de l'automate sont : %s Voulez-vous les changer? (y/n): ",line);
            strcpy(G_state,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("\nEntrez tous les etats : ");
                scanf("%s", G_state);
            }

        }else if(i==1){

            printf("\nles états initiaux sont : %s Voulez-vous les changer? (y/n): ",line);
            strcpy(G_initialState,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("\nEntrez les états initiaux : ");
                scanf("%s", G_initialState);
            }
        }else if(i==2){

            printf("\nLes états finaux sont : %s Voulez-vous les changer? (y/n): ",line);
            strcpy(G_finiteState,line);
            scanf("%s",choix);

            if(strcmp(choix,"n")){
                printf("Entrez les états finaux : ");
                scanf("%s", G_finiteState);
            }

        }else{
            printf("\ntransition %d : %s",i-2 ,line);
        }
        i++;
    }

    G_transactionNbr = i-3;
    printf("\nLe nombre de transitions est: %d Voulez-vous les changer? (y/n): ",G_transactionNbr);
    
    saveAEF(G_state,G_initialState,G_finiteState,G_transactionNbr);

    fclose(f);
}
