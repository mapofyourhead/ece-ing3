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

void initialiserMat(int lin, int col, char mat[lin][col]){
    //initialisation + affichage matrice
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = '.';
            //printf("%c", mat[i][j]);
        }
        //printf("\n");
    }
}


void afficherMat(int lin, int col, char mat[lin][col]){
    gotoxy(0, 0); //pour qu'il commencer a imprimer au bon endroit

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

//Masquer le curseur qui clignote
void masquerCurseur() {
    CONSOLE_CURSOR_INFO info; // est la structure qui contient les prp du curseurs
    info.dwSize = 1; // taille du curseur
    info.bVisible = FALSE; // rend le curseur invisible

    SetConsoleCursorInfo( // applique ces parametres a la console
        GetStdHandle(STD_OUTPUT_HANDLE),
        &info
    );
}

int main()
{
    masquerCurseur();
    //DDV
    int lin = 20;
    int col = 40;
    char mat[lin][col];
    int compte = 1;

    int xA = 0; // position horizontale
    int xB = 0;
    int xC = 0;

    int yA = 5; //position verticale
    int yB = 10;
    int yC = 15;

    // 0 = deplacement horizontal,1 = deplacement vertical
    int directionA = 0; //non 0 = 1, non 1 = 0
    int directionB = 0;
    int directionC = 0;


    //initialisation matrice
    initialiserMat(lin,col,mat);

    //initialisation positions a,b,c
    mat[yA][xA] = 'a';
    mat[yB][xB] = 'b';
    mat[yC][xC] = 'c';

    afficherMat(lin, col, mat);

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

                    // 1. effacer l'ancienne position
                    mat[yA][xA] = '.';

                    //2. calculer sa nouvelle position
                    if (directionA == 0){ // si direction horizontale

                        xA = (xA + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yA = (yA + 1) % lin;
                    }
                    //3. enregistrer sa nouvelle position
                    mat[yA][xA] = 'a';
            }
            //tester si b doit avancer : modulo 4
                    //updater position de B
            if (compte%4 == 0){
                    // 1. effacer l'ancienne position
                    mat[yB][xB] = '.';
                    if (directionB == 0){ // si direction horizontale

                        xB = (xB + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yB = (yB + 1) % lin;
                    }
                    //3. enregistrer sa nouvelle position
                    mat[yB][xB] = 'b';

            }
            //tester si c doit avancer : modulo 1 (compte%1 == 0)
                    //updater position de C
            if (1){
                    // 1. effacer l'ancienne position
                    mat[yC][xC] = '.';
                    if (directionC == 0){ // si direction horizontale

                        xC = (xC + 1) % col;
                    }
                    else {
                        // Déplacement vertical
                        yC = (yC + 1) % lin;
                    }
                    //3. enregistrer sa nouvelle position
                    mat[yC][xC] = 'c';
            }

            //afficher a,b,c
            afficherMat(lin, col, mat);

            //incrementer compte
            compte++;
            //temporisation
            Sleep(100); // Pause de 100 millisecondes
               } while(1);

    return 0;
}
