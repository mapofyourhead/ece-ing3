/*
Ecrire un programme qui trie en ordre roissant les 25 valeurs entieres entre 201 et 999 contenues dans un fichier texte. 
Le fichier de donnees aura ete cree par un ssg avec des valeurs aleatoires

Le main sera le chef d'orchestre. Il appelera entre autres un sspg "menu" qui permet de generer le fichier de donnees, d'afficher le tableau avant tri, d'afficher apres tri, de sauvegarder le tableau trie dans un 2e fichier

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>




//sspg generer un fichier avec des chiffres aleatoires

void generer_fichier(int *tab, const char *nom_fichier)
{
	FILE *favant = fopen(nom_fichier,"w"); // cree le premier fichier
	
	if(favant ==  NULL){ // verifie si le fichier a ete ouvert
		perror("Erreur de creation du fichier");
		return;
	}
	
	for(int i = 0; i < 25 ; i++){ 
		fprintf(favant, "%d\n",tab[i]);
	}
	fclose(favant);
}


// sspg afficher le tableau
void afficher(int *tab)
{
	for(int i = 0; i < 25 ; i++){ 
		printf("%3d ",tab[i]);
	}
	printf("\n");
}


//tri
void tri(int *tabavant, int *tabapres)
{
	//DDV
	int min = 0;
	int temp;
	//traitement
	for(int i = 0; i < 25 ; i++){
		
		tabapres[i] = tabavant[i];		
	}	
	
	for(int j = 0; j < 24 ; j++){ // j = position que je veux remplir
	// fin a 24 puisque le dernier elemet sera a sa place
		min = j; //hyp: le premier element restand est le min
		for(int i = j+1; i < 25 ; i++){ //commencer a int j+1 pour pas comparer j avec lui memee
			
			if(tabapres[i] < tabapres[min])
			{
				min = i;
			}
		}
	temp = tabapres[j];
	tabapres[j] = tabapres[min];
	tabapres[min] = temp;
	}
}


// sspg menu - done
int menu()
{
	///DDV
	int choice; //variable locale
	
	//traitement
	do
	{
		printf("\n Menu: \n 1. Generer un fichier de donnees\n 2. Afficher le tableau avant tri \n 3. Afficher le tableau apres tri \n 4. Sauvegarder le fichier trie dans un nv fichier \n 5. Quitter\n\n");
		printf("Votre choix: ");
		scanf("%d",&choice);
		if (choice > 5 || choice < 1 )
		{
			printf("\nVotre saisie est invalide. Veuillez reessayer.\n");
		}
	}
	while(choice > 5 || choice < 1 );
	
	// renvois la valeur scanee au main
	return choice;
}



int main()
{
	//declaration pour aleatoire
	srand(time(NULL));
	// DDV
	
	int choix;
	int tabavant[25];
	int tabapres[25];
	
	//rempli le tableau avec des valeurs aleatoires
	for(int i = 0; i < 25 ; i++){ 
		tabavant[i] = rand()%799 + 201; // 799 pcq 999-201 +1 = 799. Produit une valeur entre 0 et 798, puis rajoute 201;
		tabapres[i] = 0;
	}
	
	
	
	
	//1. affichage menu
	
	do{
		choix = menu();
		switch(choix)
	{
		case 1 : 
			generer_fichier(tabavant, "favant.txt"); // creer fichier avec les valeurs aleatoires du tableau non trie
			printf("Fichier cree!\n\n");
			break; 
			
		case 2 : 
			printf("Voici le tableau avant le tri:\n\n");
			afficher(tabavant); // afficher le tableau avant tri
			
			break;
		
		case 3 : 
			tri(tabavant,tabapres); // trier et afficher le tableau trie 
			printf("Voici le tableau trie:\n\n");
			afficher(tabapres);
			break;
		
		case 4 :
			generer_fichier(tabapres,"fapres.txt"); // 
			printf("Fichier cree!\n\n");
			break;
		
		case 5 :
			break;		
	}
	}
	while(choix !=5);
	
	
	return 0;
}

