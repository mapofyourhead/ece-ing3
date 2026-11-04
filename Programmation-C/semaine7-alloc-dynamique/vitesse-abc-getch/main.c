#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>

// Exercice: vitesses relatives: c=4, a=2, b=1
//on modifie les positions de a en appuyant sur a etc

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
    int compte = 1;

    int xA = 0;
    int xB = 5;
    int xC = 0;

    int yA = 5;
    int yB = 10;
    int yC = 15;

    // 0 = deplacement horizontal,1 = deplacement vertical
    int directionA = 0; //non 0 = 1, non 1 = 0
    int directionB = 0;
    int directionC = 0;



    //initialisation + affichage matrice
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = '.';
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }

    //initialisation positions a,b,c

    gotoxy(xA,yA);
    printf("a");
    gotoxy(xB,yB);
    printf("b");
    gotoxy(xC,yC);
    printf("c");

    do{
            if (kbhit()){
                char touche = getch();

                if (touche == 'a'){
                    //change direction de a
                    directionA = !directionA;
                }
                if (touche == 'b'){
                    //change direction de b
                    directionB = !directionB;
                }
                if (touche == 'c'){
                    //change direction de c
                    directionC = !directionC;
                }
            }

            //tester si a doit avancer : modulo 2
                    //updater position de a
            if (compte%2 == 0){
                    gotoxy(xA,yA);
                    printf("."); // effacer l'ancienne position

                    if (directionA == 0){ // si direction horizontale

                        xA = (xA + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yA = (yA + 1) % lin;
                    }

                    gotoxy(xA,yA);
                    printf("a"); //afficher la nouvelle position de a

            }
            //tester si b doit avancer : modulo 4
                    //updater position de B
            if (compte%4 == 0){
                    gotoxy(xB,yB);
                    printf("."); // effacer l'ancienne position
                    if (directionB == 0){ // si direction horizontale

                        xB = (xB + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yB = (yB + 1) % lin;
                    }
                    gotoxy(xB,yB);
                    printf("b"); //afficher la nouvelle position de a

            }
            //tester si c doit avancer : modulo 1 (compte%1 == 0)
                    //updater position de C
            if (1){
                    gotoxy(xC,yC);
                    printf("."); // effacer l'ancienne position
                    if (directionC == 0){ // si direction horizontale

                        xC = (xC + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yC = (yC + 1) % lin;
                    }
                    gotoxy(xC,yC);
                    printf("c"); //afficher la nouvelle position de a
                    }

            //afficher a,b,c


            //incrementer compte
            compte++;
            //temporisation
            Sleep(100); // Pause de 100 millisecondes

               } while(1);

    return 0;
}
