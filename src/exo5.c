#include "../include/imports.h"
#include "../include/exo5.h"


/* 29/12/21 by Saliou */

typedef struct s_liste {
        int state;	// Nom de l'etat
        struct s_liste* nxt;	// Etat suivant
} liste;

typedef struct {
         int size;
         int sizeAlpha;
         int* initial;
         int* final;
         liste*** trans;
} automate;


// Fonction qui ajouter un element à une liste
void ajouteListe2(liste** l,int q){
	liste* ptl;
	liste* tmp;
	ptl=*l;
	if(!ptl){
		ptl=(liste*) malloc(sizeof(liste));
		ptl->state=q;
		ptl->nxt=NULL;
		*l=ptl;
		return;
	}
	if(ptl->state == q){
		return;
	}
	if(q< ptl->state){
		tmp=*l;
		*l=(liste*) malloc(sizeof(liste));
		(*l)->state=q;
		(*l)->nxt=tmp;
		return;
	}
	while(ptl->nxt && ptl->nxt->state <q){
		ptl=ptl->nxt;
	}
	if(!ptl->nxt){
		ptl->nxt=(liste*) malloc(sizeof(liste));
		ptl=ptl->nxt;
		ptl->state=q;
		ptl->nxt=NULL;
		return;
	}
	if(ptl->nxt->state==q){
		return;
	}
	tmp=ptl->nxt;
	ptl->nxt=(liste*) malloc(sizeof(liste));
	ptl=ptl->nxt;
	ptl->state=q;
	ptl->nxt=tmp;
}


// Fonction qui ajoute une transition qui part de src vers targ, avec lettre alpha
void ajouteTransition2(automate* au, int src, int targ, char alpha){
	if (src >= au->size || src < 0 || targ >= au->size || targ < 0 || ((int)(alpha - 'a') >= au->sizeAlpha)){
		printf("L'Etat ou la lettre n'existe pas. \n");
		return;
	}
	ajouteListe2(&(au->trans[src][(int)(alpha - 97)]), targ);	
}



// Fonction qui complete l'automate passé en paramètre
void completer(automate* au) {
	liste*** tmp = (liste***) malloc((au->size + 1)*sizeof(liste**));
    int* newinit = (int*) malloc((au->size + 1)*sizeof(int));
    int* newfinal = (int*) malloc((au->size + 1)*sizeof(int));

    int i,j,db = au->size;

    for(i=0;i<au->size;i++) {
        tmp[i] = au->trans[i];
        newinit[i] = au->initial[i];
        newfinal[i] = au->final[i];
    }

    tmp[db] =(liste**) malloc(au->sizeAlpha*sizeof(liste*));

    for(j=0;j<au->sizeAlpha;j++) {
        tmp[db][j] = NULL;
    }
    newinit[db] = 0;
    newfinal[db] = 0;

    au->size = db + 1;
    au->trans = tmp;
    au->initial = newinit;
    au->final = newfinal;

    for(i=0;i<au->size;i++) {
        for(j=0;j<au->sizeAlpha;j++) {
            if(au->trans[i][j] == NULL) {
                ajouteTransition2(au,i,db,(char) j + 'a');
            }
        }
    }
}
// Affiche l'automate passé en paramètre
void afficheAutomate2(automate au){
	int i,j;
	unsigned char c;

	// affichage des états initiaux
	printf("\nLes etats initiaux\n");
	
	for (i=0; i<au.size; i++){
		if (au.initial[i] == 1){
			printf(" %d",i);
		}
	}

	// affichage des états finaux
	printf("\nLes etats finaux\n");
	for (i=0; i<au.size; i++){
		if(au.final[i] == 1){
			printf(" %d",i);
		}
	}

	// affichage des transitions
	printf("\nLes Transitions\n");
	
	for (i=0; i<au.size; i++){
	printf("------------------------------\n");
		printf("\nDepuis l'etat %d",i);
		for (j=0; j<au.sizeAlpha; j++){
			printf("\navec la lettre %c :\n", c = (unsigned char) j+97);	
			liste* tmp;
			tmp = au.trans[i][j];

			while (tmp != NULL){
				printf(" %d",tmp->state);
				tmp = tmp->nxt;
			}
			printf("\n");
		}
	}
	printf("\n");
	
}



void CompleteAu(void) {

   	int continuer = 1;
   	int continuer2 = 1;
	automate* au = (automate*) malloc(sizeof(automate));
        int choix = 0;
        int size, sizeAlpha;
        int i, k, j;
        int targ;
	char tran;
	

    while(continuer) {
    	printf("Construisez l'automate à compléter (Appuyer sur la Touche '1' pour continuer): \n");
    	scanf("%i", &choix);
    	switch(choix) {
    		
    		case 1:
    			printf("Taille?(size): \n");
    			scanf("%i", &size);
    			printf("Taille Alphabet(sizeAlpha, numérique): \n");
    			scanf("%i", &sizeAlpha);

    			au->size = size;
				au->sizeAlpha = sizeAlpha;

				au->initial = (int*) malloc(au->size*sizeof(int));

				for(i=0; i<au->size; i++) {
					printf("Etat:%d, Initial? Oui:1 | Non:0\n", i);
					scanf("%d",&k);
					au->initial[i] = k;
				}

				au->final = (int*) malloc(au->size*sizeof(int));

				for(i=0; i<au->size; i++) {
					printf("Etat:%d, Final? Oui:1 | Non:0\n", i);
					scanf ("%d",&k);
					au->final[i] = k;
				}

				// Creation/initialisations de transitions vides
				au->trans = (liste***) malloc(au->size*sizeof(liste***));
				for(i=0;i<au->size;i++){
					au->trans[i]=(liste**) malloc(au->sizeAlpha*sizeof(liste*));
					for(k=0;k<au->sizeAlpha;k++){
						au->trans[i][k]=NULL;
					}
				}

				for(i=0;i<au->size;i++) {
					printf("Etat: %d | ", i);
					printf("Combien de transitions voulez vous ajouter\n");
					scanf ("%d",&k);
					for(j=0; j<k; j++) {
						printf("\nEtat cible ? (de 0 à %d): ", au->size-1);
						scanf ("%d",&targ);
						printf("\nPar transition ? (a, ..., %c /!\\ à la valeur !)", au->sizeAlpha+96); // 97:a; -1 pour la taille
						scanf ("%s",&tran);
						printf("%c\n", tran);
						ajouteTransition2(au,i,targ,tran);
					}
				}
				printf("AFFICHAGE RECAPITULATIF DE L'AUTOMATE");
				afficheAutomate2(*au);

    			break;
    			
    		  default:
                	printf("Mauvaise entrée\n");
                       
                       break;	
    	}

 
    	while(continuer2) {
    		printf("Rendons l'automate saisi complet!\n (Appuyer sur '8' pour  le compléter\n '9' pour quitter: ");
			scanf("%i", &choix);

			switch(choix) {
			    
				case 8:
					printf("Completion:\n");
					completer(au);
					afficheAutomate2(*au);
					break;
                        case 9:
                	        continuer = 0;
                	        continuer2 = 0;
                	        break;     
                
                        default:
                	        printf("Mauvaise entrée\n");
                	        break;	
    	                       
    	    } 
    	
    	               	
		}
	
     
     
    	}
    }
