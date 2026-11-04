#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

// Exercice: vitesses relatives: c=4, a=2, b=1

//definition de gotoxy
void gotoxy(int x, int y) {
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


int verifierFin(int posB, int col){
    if (posB == col - 1){
        return 1;
    }
    return 0;
}


int main()
{
    //DDV
    int lin = 20;
    int col = 40;
    char mat[lin][col];
    int tempo = 100000;
    int compte = 1;
    int fin = 0;
    int posA = 0;
    int posB = 0;
    int posC = 0;



    //initialisation + affichage matrice
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = '.';
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }

    //initialisation positions a,b,c

    gotoxy(posA,5);
    printf("a");
    gotoxy(posB,10);
    printf("b");
    gotoxy(posC,15);
    printf("c");

    do{
            //tester si a doit avancer : modulo 2
                    //updater position de a
            if (compte%2 == 0 && posA < col - 1){
                    gotoxy(posA,5);
                    printf("."); // effacer l'ancienne position
                    posA++; // bouger d'une colonne vers la droite
                    gotoxy(posA,5);
                    printf("a"); //afficher la nouvelle position de a

            }
            //tester si b doit avancer : modulo 4
                    //updater position de B
            if (compte%4 == 0 && posB < col - 1){
                    gotoxy(posB,10);
                    printf("."); // effacer l'ancienne position
                    posB++; // bouger d'une colonne vers la droite
                    gotoxy(posB,10);
                    printf("b"); //afficher la nouvelle position de a

            }
            //tester si c doit avancer : modulo 1 (compte%1 == 0)
                    //updater position de C
            if (posC < col - 1){
                    gotoxy(posC,15);
                    printf("."); // effacer l'ancienne position
                    posC++; // bouger d'une colonne vers la droite
                    gotoxy(posC,15);
                    printf("c"); //afficher la nouvelle position de a

            }

            //afficher a,b,c


            //incrementer compte
            compte++;

            //temporisation
            //volatile empeche le ompilateur d'ignorer la boucle videyeah

            //for (volatile int i=0; i<tempo;i++){
                    //temporisation : ne fait rien}
            Sleep(100); // Pause de 100 millisecondes
            //verifier condition de fin
            fin = verifierFin(posB,col);
               } while(!fin);
    gotoxy(0,lin+1); //retourner le curseur en bas pour le message de fin
    return 0;
}
