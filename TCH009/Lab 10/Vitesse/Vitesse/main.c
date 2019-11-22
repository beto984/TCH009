//
//  main.c
//  Vitesse
//
//  Created by Humberto Villarino on 2019-11-21.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>

#define COL 8
#define LIGNE 2

void afficheTab2D(double Tab[][COL],int nb_ligne);

void kmh2ms(double Tab[][COL]);

double integrale(double Tab[][COL]);

double derive(double Tab[][COL],int idx_col);


int main(int argc, const char * argv[]) {
    double vitesse[LIGNE][COL]={{0,1,3,4,6,7,8,10},{0,1.9,13.2,21.7,44.3,58.5,74.5,100}};
    
    afficheTab2D(vitesse, LIGNE);
    kmh2ms(vitesse);
    afficheTab2D(vitesse, LIGNE);
    printf("Resultat de la fonction derive: %lf \n ",integrale(vitesse));
    
    return 0;
}

void afficheTab2D(double Tab[][COL],int nb_ligne){
    for (int i=0; i< nb_ligne; i++) {
        for (int j=0; j<COL; j++) {
            printf("%0.2lf | ", Tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void kmh2ms(double Tab[][COL]){
    for (int i=0; i<COL; i++) {
        Tab[1][i]/=3.6;
    }
}

double integrale(double Tab[][COL]){
    double aire=0;
    for (int i=0; i<COL-1; i++) {
        aire+=((Tab[0][i+1]-Tab[0][i])*Tab[1][i]); //Aire du rectangle
        aire+=(((Tab[0][i+1]-Tab[0][i])*(Tab[1][i+1]-Tab[1][i]))/2); // Aire du triangle
    }
    return aire;
}

double derive(double Tab[][COL],int idx_col){
    
    double deltaY=Tab[1][idx_col+1]-Tab[1][idx_col];
    double deltaX=Tab[0][idx_col+1]-Tab[0][idx_col];
    double acceleration=deltaY/deltaX;
    return acceleration;
}
