/*
 * Calcul récursif d'une puissance x^y :
 * - On utilise la propriété x^y = x * x^(y-1).
 * - À chaque appel, on multiplie x par le résultat
 *   d'un nouvel appel avec y - 1.
 * - Condition d'arrêt : lorsque y == 1, on retourne x.
 * - Les multiplications s'effectuent lors du retour
 *   des appels récursifs.
 * - Récursivité non terminale : une multiplication reste
 *   à effectuer après chaque appel récursif.
 */

#include<stdio.h>
//#include<math.h>

int puissance(int x1, int y1){
	//DDV
	//suis-je terminal?
	if (y1 == 0) // ne rien faire
	{
		return 1;  //OU y1==0, return 1
	}
	else //je ne suis pas temrinal 
	{
		return(x1*puissance(x1,y1 - 1));
	}
}



int main()
{
	int res, x=5, y=4;
	res = puissance(x,y);
	printf("Resultat = %d\n", res);
	
	return 0;
}



// OR y1==1, return x1, but then limited in input