//
//  bitMSB.c
//  Lab 1
//
//  Created by Humberto Villarino on 2019-09-20.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include "bitMSB.h"
#include <stdio.h>

void ex1(){
    int nombreUt;//Entier fourni par l'utilisateur
    int nombreMult;// Entier resultant de la multiplication par 4
    printf("Entrez un nombre: ");
    scanf("%d", &nombreUt);
    nombreMult=nombreUt<<2;// Deplacement bit a bit
    printf("Le nouveau nombre est %d \n",nombreMult);
    
};

void ex2(){
    int nombreUt; //Entier fourni par l'utilisateur
    int MSB;// Valeur du MSB
    
    printf("Entrez un nombre: ");
    scanf("%d", &nombreUt);
    if (nombreUt<0) {//Le MSB est le bit de signe, donc on peut l'evaluer en s'assurant que l'entier est positif ou negatif
        MSB=1;
        printf("le MSB est: %d \n",MSB);
    }
    else{
        MSB=0;
        printf("le MSB est: %d \n",MSB);
    }
    
    
}



int main(void) {
       ex1();
       ex2();


    return 0;
}
