#include <stdio.h>
#include <time.h>
#include "enquete.h"

#define CAPACITE_APPELS 1000

int main(void)
{
    Appel appels[CAPACITE_APPELS];
    int nbAppels = chargerAppels(appels, CAPACITE_APPELS);

    if (nbAppels < 0) {
        return 1;
    }

    // Chronomètre le tri par numéro avant le classement des correspondants
    time_t debut = time(NULL);
    triBulle(appels, nbAppels);
    time_t fin = time(NULL);

    printf("Duree du tri a bulles : %.0f s\n", difftime(fin, debut));
    printf("Nombre d'appels stockes : %d\n", nbAppels);

    afficherClassement(appels, nbAppels);

    return 0;
}
