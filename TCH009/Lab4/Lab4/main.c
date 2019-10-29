//
//  main.c
//  Lab4 TCH009
//
//  Created by Humberto Villarino on 2019-10-04.
//
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PRIX_DE_BASE 20
#define PRIX_PREMIERS_10_KWH 3
#define PRIX_KWH_SUPPLEMENTAIRES 2
#define MAX_INT 2147483647


void facture(){
    float consommation;
    float total;

    
    printf("Entrez votre consommation en KwH: ");
    scanf("%f", &consommation);
    
    if (consommation<=10) {
        total=PRIX_DE_BASE+consommation*PRIX_PREMIERS_10_KWH;
    }
    else if(consommation>10){
        total=PRIX_DE_BASE+10*PRIX_PREMIERS_10_KWH+(consommation-10)*PRIX_KWH_SUPPLEMENTAIRES;
    }
    
    printf("Votre solde a payer: %f \n", total);
}

    void energie(void)
    {
        float masse;
        float vitesse;
        float resultat;
        char choix;

        printf("\n\nEntrez la masse (kg)): ");
        scanf("%f",&masse);

        printf("\n\nEntrez la vitesse (m/s):" );
        scanf("%f",&vitesse);
        
        printf("Selectionnez le calcul a effectuer\n a) Energie cinétique\n b) Quantité de mouvement");
        scanf(" %c", &choix);
        
        if (choix=='a') {
            resultat=0.5*masse*vitesse*vitesse;
            printf("\n\nL'energie cinetique est: %f (J) ", resultat);
        }
        else if (choix=='b'){
            resultat=masse*vitesse;
            printf("\n\nLa quantité de mouvement est: %f (kg m/s) \n", resultat);
        }
    }

void atmosphere(){
    float hauteur;
    
    printf("Entrez l'altitude en km: \n");
    scanf("%f",&hauteur);
    
    if (hauteur<0) {
        printf("Erreur\n");
    }
    else if (hauteur>0 && hauteur<12){
        printf("Troposphère\n");
    }
    else if (hauteur>12 && hauteur<50){
        printf("Stratosphère\n");
    }
    else if (hauteur>50 && hauteur<85){
        printf("Mésosphère\n");
    }
    else if(hauteur>85 && hauteur<500){
        printf("Thermosphère\n");
    }
    else if (hauteur>500){
        printf("Exosphère\n");
    }
}

void stats(){
    int nombre, moyenne;
    int somme=0, plusGrand=0, plusPetit=MAX_INT, paire=0;
    int numerosUtilisateurs[4];
    
    
    
    for (int i =0; i<5;i++) {
        printf("Entrez le %de nombre",i+1);
        scanf("%d", &nombre);
        numerosUtilisateurs[i]=nombre;
    }
    
    for (int i=0; i<5; i++) {
        if (numerosUtilisateurs[i]>plusGrand) {
            plusGrand=numerosUtilisateurs[i];
        }
        if (numerosUtilisateurs[i]<plusPetit) {
            plusPetit=numerosUtilisateurs[i];
        }
        if (numerosUtilisateurs[i]%2==0) {
            paire++;
        }
        somme+=numerosUtilisateurs[i];
    }
    
    moyenne=somme/5;
    
    printf("La moyenne est: %d \n La somme est: %d \n Le plus grand entier est: %d \n Le plus petit entier est: %d \n Le nombre d'entiers pairs: %d\n",moyenne,somme,plusGrand,plusPetit,paire);
}



int main(int argc, const char * argv[]) {
    
    facture();
    energie();
    atmosphere();
    stats();
    
    return 0;
}
