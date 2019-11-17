//
//  main.c
//  Eolienne
//
//  Created by Humberto Villarino on 2019-11-15.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAILLETAB 10
#define PI 3.14159265358979323846
#define DENSITEAIR 1.2


//Declaration des fonctions
void afficheTab1D(double Tab[],int taille);
double interpoleTab1D(double Tab[], double x, int taille);
void rempliAleaTab1D(double Tab[], int taille, double min, double max);
void calcPuissHoraire(double tabPuiss[],double tabVent[],double tabEff[],double r,int tailleVent,int tailleEff);
void calcMoyTab1D(double Tab[], int taille);



int main(int argc, const char * argv[]) {
    //Declaration des tableaux
    double tabEff[10]={0.0,0.36,0.45,0.5,0.53,0.54,0.55,0.42,0.27,0.2};
    double tabVent[24];
    double tabPuiss[24];
    

    afficheTab1D(tabEff, TAILLETAB);

//  Verification du fonctionnement de la fonction interpoleTab1D
    printf("%lf \n",interpoleTab1D(tabEff, 0, TAILLETAB));
    printf("%lf \n",interpoleTab1D(tabEff, 2.5, TAILLETAB));
    printf("%lf \n",interpoleTab1D(tabEff, 9, TAILLETAB));
    
//  Remplissage et affichage du tableau tabVent
    rempliAleaTab1D(tabVent, 24, 0, 9);
    afficheTab1D(tabVent, 24);

//  Remplissage et affichage du tableau tabPuiss
    calcPuissHoraire(tabPuiss, tabVent, tabEff, 1, 24, TAILLETAB);
    afficheTab1D(tabPuiss, 24);
    
//  Calcul et affichage de la puissance moyenne
    calcMoyTab1D(tabPuiss, 24);
    return 0;
}

//  Fonction pour affichage d'un tableau d'une dimension
void afficheTab1D(double Tab[], int taille){
    for (int i=0; i<taille; i++) { //On parcourt le tableau
        printf("%d  %0.2lf\n\n",i, Tab[i]);
    }
}

// Fonction pour interpoler une valeur dans un tableau
double interpoleTab1D(double Tab[], double x, int taille){
    double efficacite;
    int y=floor(x); // On cree cette variable pour l'utiliser comme indice dans la formule plus loin
    
    if (x==0) {
        efficacite=Tab[0];
    }
    
    else if(x>=taille){
        efficacite=Tab[9];
    }
    
    else{
        efficacite=Tab[y]+(Tab[y+1]-Tab[y])*(x-y);// Formule fournie dans l'enoncé
    }
    
    return efficacite;
}

// Fonction pour remplir un tableau a 1 dimension avec des valeurs aleatoires entre 0 et 9
void rempliAleaTab1D(double Tab[], int taille, double min, double max){
    for (int i=0;i<taille;i++){
        Tab[i]=((double)(rand()%(int)((max-min)*100)+1))/100+min;// Formule tiree de l'enonce
    }
}

//Fonction pour calculer la puissance horaire
void calcPuissHoraire(double tabPuiss[],double tabVent[],double tabEff[],double r,int tailleVent,int tailleEff){
    for (int i=0; i<tailleVent; i++) {
        double x=tabVent[i];
        tabPuiss[i]=interpoleTab1D(tabEff, x, tailleEff)*0.5*pow(r, 2)*DENSITEAIR*PI*pow(x, 3);// Formule tiree de l'enonce
    }
}
// Fonction pour calculer la moyenne d'un tableau
void calcMoyTab1D(double Tab[], int taille){
    double somme=0, moyenne;
    
    for (int i=0; i<taille; i++) {
        somme+=Tab[i];
    }
    moyenne=somme/(double) taille;
    
    printf("La moyenne de puissance est: %lf\n",moyenne);
}

