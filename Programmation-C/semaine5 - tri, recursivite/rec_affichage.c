/*
 * Affichage récursif d'un tableau :
 * - On commence à l'indice i = 0.
 * - À chaque appel, on affiche l'élément toto[i].
 * - La fonction s'appelle elle-même avec i + 1 pour passer
 *   à l'élément suivant.
 * - Condition d'arrêt : lorsque i == nbcases, tous les
 *   éléments ont été affichés et la récursion s'arrête.
 * - Récursivité terminale : aucun traitement après l'appel récursif.
 */

#include<stdio.h>


void afficher (int toto[9],int i, int nbcases)
{
	//DDV pas de variables locales
	
	//suis-je terminal?
	if(i !=nbcases)
	{
		printf("%d ", toto[i]);
		afficher(toto,i+1, nbcases);
	}
}


int main(){
	//DDV
	int nbcases = 9;
	int toto[9] = {8,-3,12,17,5,25,252,67,99};
	
	afficher(toto,0,nbcases);
	
	return 0;
}