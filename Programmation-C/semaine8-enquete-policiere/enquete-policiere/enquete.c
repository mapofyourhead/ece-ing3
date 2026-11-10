#include<stdio.h>
#include <string.h>
#include "enquete.h"



int chargerAppels(Appel appels[], int capacite)
{
    // Ouvre le relevé en lecture depuis le dossier de travail du programme
    FILE *fichier = fopen("TP Police scientifique - releve telephonique.txt", "r");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le releve telephonique.\n");
        return -1;
    }

        char ligne[256];
    int nbAppels = 0;

    // Lit le relevé tant qu'il reste une place dans le tableau.
    while (nbAppels < capacite && fgets(ligne, sizeof ligne, fichier) != NULL) {
        Appel appel;

        // Extrait le numéro, le prénom, le nom et le sens de l'appel.
        int nbChamps = sscanf(ligne, "%12s %49s %49s %7s",
                              appel.numero, appel.prenom, appel.nom, appel.sens);

        if (nbChamps == 4) {
            // Copie l'appel complet dans la prochaine case libre.
            appels[nbAppels] = appel;
            nbAppels++;
        }
}

    fclose(fichier);
    return nbAppels;
}


void triBulle(Appel appels[], int nbAppels)
{
    //DDV
    int echange;
    //Traitement
    do {
    // Au début de chaque passage, aucun échange n'a encore eu lieu
    echange = 0;

    for (int i = 0; i < nbAppels - 1; i++) {
        if (strcmp(appels[i].numero, appels[i + 1].numero) > 0) {
            // Échange les appels entiers pour garder leurs champs ensemble
            Appel temporaire = appels[i];
            appels[i] = appels[i + 1];
            appels[i + 1] = temporaire;

            echange = 1;
        }
    }
    } while (echange == 1);
}


// Résume les appels d'un même numéro
typedef struct {
    int indicePremierAppel;
    int entrants;
    int sortants;
} BilanCorrespondant;

void afficherClassement(const Appel appels[], int nbAppels)
{
    if (nbAppels == 0) {
        printf("Aucun appel a classer\n");
        return;
    }

    // Il peut y avoir au maximum un correspondant par appel
    BilanCorrespondant bilans[nbAppels];
    int nbCorrespondants = 0;
    int debutGroupe = 0;

    while (debutGroupe < nbAppels) {
        BilanCorrespondant bilan = {debutGroupe, 0, 0};
        int suivant = debutGroupe;


        // Affiche le nombre total d'appels par correspondant
        printf("\nHistogramme des appels par correspondant\n");
        printf("Chaque # represente un appel\n");

        for (int i = 0; i < nbCorrespondants; i++) {
            int indice = bilans[i].indicePremierAppel;
            int total = bilans[i].entrants + bilans[i].sortants;

            printf("%s %s (%d) ", appels[indice].prenom, appels[indice].nom, total);

            // Dessine une barre dont la longueur correspond au total
            for (int j = 0; j < total; j++) {
                putchar('#');
            }
            putchar('\n');
        }

        // Compte les appels entrants et sortants du numéro courant
        while (suivant < nbAppels &&
               strcmp(appels[debutGroupe].numero, appels[suivant].numero) == 0) {
            if (strcmp(appels[suivant].sens, "Entrant") == 0) {
                bilan.entrants++;
            } else if (strcmp(appels[suivant].sens, "Sortant") == 0) {
                bilan.sortants++;
            }

            suivant++;
        }

        bilans[nbCorrespondants] = bilan;
        nbCorrespondants++;
        debutGroupe = suivant;
    }

    // Trie les bilans du plus grand au plus petit nombre d'appels entrants
    int echange;
    do {
        echange = 0;

        for (int i = 0; i < nbCorrespondants - 1; i++) {
            if (bilans[i].entrants < bilans[i + 1].entrants) {
                BilanCorrespondant temporaire = bilans[i];
                bilans[i] = bilans[i + 1];
                bilans[i + 1] = temporaire;
                echange = 1;
            }
        }
    } while (echange == 1);

    printf("\nClassement par appels entrants\n");

    int indiceMaxTotal = 0;
    int maxTotal = 0;

    for (int i = 0; i < nbCorrespondants; i++) {
        int indice = bilans[i].indicePremierAppel;
        int total = bilans[i].entrants + bilans[i].sortants;

        printf("%d. %s %s - %d entrants, %d sortants, %d au total\n",
               i + 1, appels[indice].prenom, appels[indice].nom,
               bilans[i].entrants, bilans[i].sortants, total);

        // Repère aussi le plus grand total demandé dans l'enquête
        if (total > maxTotal) {
            maxTotal = total;
            indiceMaxTotal = i;
        }
    }

    int indice = bilans[indiceMaxTotal].indicePremierAppel;
    printf("\nPlus d'echanges au total : %s %s (%d appels)\n",
           appels[indice].prenom, appels[indice].nom, maxTotal);
}
