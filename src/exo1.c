#include "../include/imports.h"
#include "../include/exo1.h"


void appartient(char langage[],char alphabet[]){
    // "appar" est un booléen qui retourne si l'alphabet qu'utilise le langage est valide 
    bool appar = false;
    bool resu = true;
    int i,j;
    i = 0;
    // Boucle qui sert à recupperer l'alphabet
    while(i<strlen(alphabet))
    {
        if (alphabet[i]==','||alphabet[i]=='{'||alphabet[i]=='}')
        {
            for (j=i; j<strlen(alphabet); j++)
                alphabet[j]=alphabet[j+1];
        }
        else i++;
    }
    
    for (int i=0; i<strlen(langage); i++) {
        for (int j=0; j<strlen(alphabet); j++) {
            if ( alphabet[j] == langage[i] ) {
                appar = true;
            }
        }
        if (!appar) {
            printf("%c n'appartien pas a l'alphabet %s\n",langage[i],alphabet);
            resu = false;
            break;
            break;
        }
        appar = false;
    }
    
    if (resu) {
        printf("%s appartien a l'alphabet %s\n",langage,alphabet);
    }
}


/*
 * --- fonction puis ---
 */


void puis(char langage[],int power){
    
    char resu[100];
    
    for (int i=0; i<power; i++)
        strcat(resu, langage);
    
    printf("%s\n",resu);
}


/*
 * --- fonction vide ---
 */

void vide(char langage[]){
    
    printf("%s\n", strlen(langage)!=0 ? "false":"true");
}


/*
 * --- fonction concat ---
 */

void concat(char langage1[],char langage2[]){
    
    printf("%s\n",strcat(langage1, langage2));
}


/*
 * --- fonction miroir ---
 */

void miroir(char langage[]){
    
    int tmp;
    long len = strlen(langage);

    for (int i=0;i<len/2;i++) {
        
        tmp = langage[i];
        langage[i] = langage[len-i-1];
        langage[len-i-1] = tmp;
        
    }
    
    printf (" %s \n", langage);
    
}

/*
 * --- fonction estFini ---
 */


void estFini(char langage[]){
    
    printf("%s \n",strchr(langage, '*')==NULL?"true":"false");
}

