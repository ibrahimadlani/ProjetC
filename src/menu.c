#include "../include/menu.h"
#include "../include/fonction.h"

void menuPrincipale(void){
    
    int choi=1;
    int choi2;
    
    while (choi!=0 ) {
        choi=1;
        automateSlogo();
        // \033[34;01m pour changer la couleur  \033[0mm  pour revenir a la couleur par default
        printf ("\033[34;01m Menu Principale \033[00m\n");

        printf("   \033[34;01m|____ 1) \033[00mManipulation des mots d’un alphabet.\n");
        printf("   \033[34;01m|____ 2) \033[00mManipuler un AEF.  \n");
        printf("   \033[34;01m|____ 3) \033[00mVérifier si un mot est reconnu par un AEF.  \n");
        printf("   \033[34;01m|____ 4) \033[00mVérifier la complétude d'un AEF. \n");
        printf("   \033[34;01m|____ 5) \033[00mCompléter un AEF saisi.   \n");
        printf("   \033[34;01m|____ 6) \033[00m \n");
        printf("   \033[34;01m|____ 7) \033[00m \n");
        printf("   \033[34;01m|____ 8) \033[00m \n");
        printf("   \033[34;01m|____ 9) \033[00m \n");
        printf("   \033[34;01m|____ 10)\033[00m  \n");
        printf("   \033[34;01m|____ 11)\033[00m  \n");
        printf("   \033[34;01m|____ 0) \033[00Pour quitter   \n");
        printf("===> : ");
        scanf("%d",&choi);
        system("clear");
        
        
        switch (choi) {
            case 1:
                
                printf("   \033[34;01m |____1) \033[00mManipulation des mots d’un alphabet.\n");
                printf("        \033[36;01m|_____ 1) \033[00mVérifier si un mot appartient à X*.\n");
                printf("        \033[36;01m|_____ 2) \033[00mCalculer la puissance d’un mot.\n");
                printf("        \033[36;01m|_____ 3) \033[00mVérifier si un mot est vide.\n");
                printf("        \033[36;01m|_____ 4) \033[00mConcaténer deux mots.\n");
                printf("        \033[36;01m|_____ 5) \033[00mCalculer le miroir d’un mot.\n");
                printf("        \033[36;01m|_____ 6) \033[00mVérifier si une chaine de caractères représente un mot fini.\n");
                printf("        \033[36;01m|_____ 0) \033[00mPour revenir au menu principale.\n");
                printf("        \033[36;01m|_____ 9) \033[00mPour quiter.\n");
                printf("===> : ");
                scanf("%d",&choi2);
                
                appeleExo1(choi2);
                system("clear");
                break;
                
            case 2:
                
                printf("   \033[34;01m |____ 2) \033[00m Manipuler un AEF.   \n");
                printf("        \033[36;01m|_____ 1)\033[00m Saisir un AEF, \n");
                printf("        \033[36;01m|_____ 2)\033[00m Importer un AEF à partir d’un fichier,\n");
                printf("        \033[36;01m|_____ 3)\033[00m modifier un AEF,\n");
                // printf("        \033[36;01m|_____ 4)\033[00m sauvegarder un AEF dans un fichier.\n");
                printf("        \033[36;01m|_____ 0)\033[00m Pour revenir au menu principale \n");
                printf("        \033[36;01m|_____ 9)\033[00m Pour quiter \n");
                printf("===> : ");

                scanf("%d",&choi2);
                appeleExo2(choi2);

                system("clear");
                break;
                
            case 3:

                printf("   \033[34;01m |____ 3) \033[00m Vérifier si un mot est reconnu par un AEF.     \n");
                printf("        \033[36;01m|_____ 1)\033[00m Vérifier un AEF, \n");
                printf("        \033[36;01m|_____ 0)\033[00m Pour revenir au menu principale \n");
                printf("        \033[36;01m|_____ 9)\033[00m Pour quiter \n");
                printf("===> : ");
                
                scanf("%d",&choi2);
                appeleExo3(choi2);

                system("clear");
                break;   
                
                
             case 4: 
                
                printf("   \033[34;01m|____ 4) \033[00m Vérifier la complétude d'un AEF. \n");
                printf("        \033[36;01m|_____ 1)\033[00m Saisissez un AEF et vérifier sa complétude, \n");
                printf("        \033[36;01m|_____ 0)\033[00m Pour revenir au menu principale \n");
                printf("        \033[36;01m|_____ 9)\033[00m Pour quiter \n");
                printf("===> : ");

                scanf("%d",&choi2);
                appeleExo4(choi2);

                system("clear");
                
                break;
              
              case 5: 
                
                printf("   \033[34;01m|____ 5) \033[00m Compléter un AEF saisi. \n");
                printf("        \033[36;01m|_____ 1)\033[00m Saisissez un AEF non-complet et le compléter \n");
                printf("        \033[36;01m|_____ 0)\033[00m Pour revenir au menu principale \n");
                printf("        \033[36;01m|_____ 9)\033[00m Pour quiter \n");
                printf("===> : ");

                scanf("%d",&choi2);
                appeleExo5(choi2);

                system("clear");
                
                break;
                
            default:
                break;
        }
        
    }
    printf ("\033[34;01m au revoir \033[00m\n");
}

void appeleExo1(int choix){
    
    char langage[100];
    char alphabet[100];
    int power;
    
    switch (choix) {
        case 0:
            break;
        case 1:
            
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
            
            printf("\nentrer les alphabet du langage ex({a,b,c}) : ");
            scanf("%s",alphabet);
            
            appartient(langage,alphabet);
            sleep(2);
            break;
        case 2:
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
            
            printf("\nentrer votre power ex (1) : ");
            scanf("%d",&power);
            
            puis(langage,power);
            sleep(2);
            break;
        case 3:
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
            
            vide(langage);
            sleep(2);
            break;
        case 4:
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
            
            char langage2[100];
            
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage2);
            
            concat(langage,langage2);
            sleep(2);
            break;
        case 5:
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
        
            miroir(langage);
            sleep(2);
            break;
        case 6:
            printf("\nentrer votre langage ex(aaba) : ");
            scanf("%s",langage);
            
            estFini(langage);
            sleep(2);
            break;
        case 9:
            printf ("\033[34;01m au revoir \033[00m\n");
            exit(0);
        default:
            break;
    }
    
    
}

void appeleExo2(int choix){
    
    switch(choix){
        case 0:
            break;
        case 1:
            enterAEF();
            sleep(6);
            break;
        case 2:
            importAEF();
            sleep(6);
            break;
        case 3:
            editeAEF();
            sleep(6);
            break;
        case 9:
            printf ("\033[34;01m au revoir \033[00m\n");
            exit(0);
            break;
        default:
            break;
    }

}

void appeleExo3(int choix){
       switch(choix){
        case 0:
            break;
        case 1:
            CheckWordRecognized();
            sleep(6);
            break;
        case 9:
            printf ("\033[34;01m au revoir \033[00m\n");
            exit(0);
            break;
        default:
            break;
    } 
}



void appeleExo4(int choix){
    switch(choix){
        case 0:
            break;
        case 1:
            Completude();
            sleep(6);
            break;
        case 9:
            printf ("\033[34;01m au revoir \033[00m\n");
            exit(0);
            break;
        default:
            break;
}
}

void appeleExo5(int choix){
    switch(choix){
        case 0:
            break;
        case 1:
            CompleteAu();
            sleep(6);
            break;
        case 9:
            printf ("\033[34;01m au revoir \033[00m\n");
            exit(0);
            break;
        default:
            break;
}
}



void automateSlogo(void){
    
    printf("Bonjour 😀\n");
    printf("                  _                                 _                        _     __   _             _              __   _           _            __             ______   ______  __  \n");
    printf("                 | |                               | |                      | |   /_/  | |           | |            / _| (_)         (_)          / /     /\\     |  ____| |  ____| \\ \\ \n");
    printf("   __ _   _   _  | |_    ___    _ __ ___     __ _  | |_    ___   ___      __| |   ___  | |_    __ _  | |_   ___    | |_   _   _ __    _   ___    | |     /  \\    | |__    | |__     | |\n");
    printf("  / _` | | | | | | __|  / _ \\  | '_ ` _ \\   / _` | | __|  / _ \\ / __|    / _` |  / _ \\ | __|  / _` | | __| / __|   |  _| | | | '_ \\  | | / __|   | |    / /\\ \\   |  __|   |  __|    | |\n");
    printf(" | (_| | | |_| | | |_  | (_) | | | | | | | | (_| | | |_  |  __/ \\__ \\   | (_| | |  __/ | |_  | (_| | | |_  \\__ \\   | |   | | | | | | | | \\__ \\   | |   / ____ \\  | |____  | |       | |\n");
    printf("  \\__,_|  \\__,_|  \\__|  \\___/  |_| |_| |_|  \\__,_|  \\__|  \\___| |___/    \\__,_|  \\___|  \\__|  \\__,_|  \\__| |___/   |_|   |_| |_| |_| |_| |___/   | |  /_/    \\_\\ |______| |_|       | |\n");
    printf("                                                                                                                                                  \\_\\                              /_/ \n");
    printf("\n");
    
}
