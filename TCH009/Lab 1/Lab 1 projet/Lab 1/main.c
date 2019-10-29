//
//  main.c
//  Lab 1
//
//  Created by Humberto Villarino on 2019-09-20.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>

int main(void) {
   
    
    int nombreUt;//Entier fourni par l'utilisateur
    int nombreMult;// Entier resultant de la multiplication par 4
    printf("Entrez un nombre: ");
    scanf("%d", &nombreUt);
    nombreMult=nombreUt<<2;// Deplacement bit a bit
    printf("Le nouveau nombre est %d \n",nombreMult);
    return 0;
}


