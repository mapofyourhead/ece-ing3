#ifndef ENQUETE_H
#define ENQUETE_H


// Regroupe les informations d'un appel pour les conserver ensemble lors du tri
typedef struct {
    char numero[13]; // 12 caractères pour le numéro avec +33, puis '\0'.
    char prenom[50];
    char nom[50];
    char sens[8];
} Appel;


// Charge les appels dans le tableau et renvoie le nombre d'appels lus
// Renvoie -1 si le relevé ne peut pas être ouvert
int chargerAppels(Appel appels[], int capacite);

// Trie les appels par numéro croissant directement dans le tableau
void triBulle(Appel appels[], int nbAppels);

// Affiche les correspondants par nombre décroissant d'appels entrants
// Le tableau des appels doit déjà être trié par numéro
void afficherClassement(const Appel appels[], int nbAppels);

#endif
