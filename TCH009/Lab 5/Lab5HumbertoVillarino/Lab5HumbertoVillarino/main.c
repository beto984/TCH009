//
//  main.c
//  Lab5HumbertoVillarino
//
//  Created by Humberto Villarino on 2019-10-09.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>

void entierPairs(){
    int entier=1;
    
    while (entier<100) {
        if (entier%2==0) {
            printf("%d  ",entier);
        }
        
        entier++;
    }
}

void energie(){
    float masse;
    float vitesse;
    float energie;

    do {
         printf("\n\nEntrez la masse (kg)): ");
                  scanf("%f",&masse);
    } while (masse<0);
        

    printf("\n\nEntrez la vitesse (m/s):" );
    scanf("%f",&vitesse);

    energie=0.5*masse*vitesse*vitesse;
    printf("\n\nL'energie cinetique est: %f (J) \n",energie);
  
}

void atmosphere(){
    float altitude;

    // capture de l'altitude
    do {
    printf("\n\nEntrez l'altidute (km): ");
    scanf("%f",&altitude);

    // affichage de la couche atmosph�tique selon l'altitude
    
         if (altitude<12)
               printf("Troposphere");
           else if (altitude<50)
               printf("Stratosphere");
           else if (altitude<85)
               printf("Mesosphere");
           else if (altitude<500)
               printf("Thermosphere");
           else printf("Exosphere");
    } while (altitude!=0);
}

void stats(){
    float somme=0;
    int nombre;
    int compteur=0;//compte le nombre d'entiers donnés
    float moyenne;

    // capture des donn�es et calcul de la somme des nombres
    printf("\n\nEntrez le nombre #1: ");
    scanf("%d",&nombre);
    compteur++;
    
    while (nombre>=0) {
        somme+=nombre;
        compteur++;
        printf("Entrez le nombre #%d: ",compteur);
        scanf("%d",&nombre);
    };
    
    moyenne=somme/(compteur-1);//-1 pour ignorer le chiffre negatif dans notre moyenne
    
    printf("La moyenne est: %f",moyenne);
}

int main(int argc, const char * argv[]) {

    //entierPairs();
    //energie();
    //atmosphere();
    stats();
    return 0;
}
