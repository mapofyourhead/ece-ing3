#include <stdio.h>
#define N 5
#define Tmax 50
//prototypes
void saisirMots(char tab[N][Tmax]);
void afficherTabMots(char tab[N][Tmax]);
void sauvegarderTabMots(char tab[N][Tmax],char nomFile[100]);
void chargerTabMots(char tab[N][Tmax],char nomFile[100]);
//Implémentation
void saisirMots(char tab[N][Tmax]){
	int i;
	printf("saisir vos %d mots\n",N);
	for(i=0;i<N;i++){
		scanf("%s",tab[i]);
	}
}
void afficherTabMots(char tab[N][Tmax]){
	int i;
	for(i=0;i<N;i++){
		printf("%s\n",tab[i]);
	}
}
void sauvegarderTabMots(char tab[N][Tmax],char nomFile[100]){
	FILE* fp;//pour manipuler un fichier
	int i;
	//tentative d'ouverture
	fp=fopen(nomFile,"w");
	//si pas ok
	if(fp==NULL){
		printf("erreur");
		return;
	}
	//si ok : on peut travailler dans le fichier
	else{
        fprintf(fp,"%d\n",N);
		for(i=0;i<N;i++){
			fprintf(fp,"%s\n",tab[i]);
		}
		//fermeture du fichier
		fclose(fp);
	}
}
void chargerTabMots(char tab[N][Tmax],char nomFile[100]){






}


int chercherMot()

int main(){
	char tab[N][Tmax];
	saisirMots(tab);
	afficherTabMots(tab);
	char nomFile[100]="essai.txt";
	sauvegarderTabMots(tab,nomFile);
	return 0;
}
