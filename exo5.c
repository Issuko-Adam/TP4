#include <stdio.h>
#pragma warning (disable : 4996)
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum { VALEURMAX = 999 };

int gamemode() {
    printf("Choisir votre mode de jeu: \n 1 - Player VS CPU \n 2 - CPU VS CPU \n 3 - HARDCORE CPU vs CPU");
    int gm;
    do {
        printf("Choissisez votre mode de jeu");
        scanf("%d", &gm);
    } while (gm < 1 || gm > 3);
    return gm;
    }

int generatenumber(){
    return rand() % VALEURMAX; 
} 

int arbitre(int justeprix, int entree){
    if (entree > justeprix)
    {
        printf("c'est moins ! \n");
        return 0;
    } 
    else if (entree < justeprix)
    {
        printf("c'est plus ! \n");
        return 1;
    }
    else 
    {
        printf("Et c'est gagné !!!");
        return 2;
    }
}

void joueurhumain() {
    int entree = -1;
    int justeprix = generatenumber();
    do {
        printf("Saisir une valeur de 0 a %d \n", VALEURMAX);
        scanf("%d", &entree);
        arbitre(justeprix, entree);
    } while (entree >= 0 && entree < VALEURMAX && entree != justeprix);
}

void ordicontreordi() {
    int entree = -1;
    int justeprix = generatenumber();

    do{
        printf("Saisir une valeur de 0 a %d \n", VALEURMAX);
        entree = generatenumber();
        printf("%d ? \n", entree);
        arbitre(justeprix, entree);
    } while (entree >= 0 && entree < VALEURMAX && entree != justeprix); 
}

void ordismart(){
    int entree = VALEURMAX / 2;
    int justeprix = generatenumber();
    int ret = 0;
    int min = 0;
    int max = VALEURMAX;
    do{
        printf("Saisir une valeur de 0 a %d \n", VALEURMAX);
        printf("%d ? \n", entree);
        ret = arbitre(justeprix, entree);
        if (ret == 0)
        {
            max = entree;

        }
        else if (ret == 1)
        {
            min = entree;
        }
        else
        {
            break;
        }
        
        entree = min + (max - min) / 2;
        sleep (1);

    } while (entree >= 0 && entree < VALEURMAX); 
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int gm = gamemode();
    switch (gm)
    {
    case 1:
        joueurhumain();
        break;
    
    case 2:
        ordicontreordi();
        break;
    case 3:
        ordismart();
        break;
    default:
        break;
    }
    return 0;
}
