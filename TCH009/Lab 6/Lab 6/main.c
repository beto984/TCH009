//
//  main.c
//  Lab 6
//
//  Created by Humberto Villarino on 2019-10-12.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void unite(){
    int exposant;
    
    printf("Entrez la valeur de l'exposant");
    scanf("%d",&exposant);
    
    switch (exposant) {
        case -15:
            printf("L'unité SI est : Femto\n");
            break;
            
        case -12:
            printf("L'unité SI est : Pico\n");
            break;
        
        case -9:
            printf("L'unité SI est : Nano\n");
            break;
        
        case -6:
            printf("L'unité SI est : Micor\n");
            break;
            
        case -3:
            printf("L'unité SI est : Milli\n");
            break;
            
        case 3:
            printf("L'unité SI est : Kilo\n");
            break;
            
        case 6:
            printf("L'unité SI est : Mega\n");
            break;
            
        case 9:
            printf("L'unité SI est : Giga\n");
            break;
            
        case 12:
            printf("L'unité SI est : Tera\n");
            break;
        
        case 15:
            printf("L'unité SI est : Peta\n");
            break;
        default:
            break;
    }
}

void puissance_do_while(){
    int i;                // compteur de boucle
    double x,resultat=1;// base et resultat de la puissance
    int n;              // exposant

    // saisie de la base et de l'exposant
    printf("\nValeur de base:");
    scanf("%lf",&x);
    printf("\nvaleur d'exposant:");
    scanf("%d",&n);

    // cas de la puissance nulle
    if (n==0)
      resultat=1;
    // cas de puissance positive
    else if (n>0){
      i=1;
      while(i<=n){
          resultat=resultat*x;
          i++;
      }
    }
    // cas de puissance negative
    else{
      i=1;
      do {
          resultat=resultat/x;
          i++;
      } while (i<-n+1);
    }

    // affichage du r�sultat
    printf("\n%f^%d=%f",x,n,resultat);
}

void puissance_for(){
    int i;                // compteur de boucle
    double x,resultat=1;// base et resultat de la puissance
    int n;              // exposant

    // saisie de la base et de l'exposant
    printf("\nValeur de base:");
    scanf("%lf",&x);
    printf("\nvaleur d'exposant:");
    scanf("%d",&n);

    // cas de la puissance nulle
    if (n==0)
      resultat=1;
    // cas de puissance positive
    else if (n>0){
      i=1;
      while(i<=n){
          resultat=resultat*x;
          i++;
      }
    }
    // cas de puissance negative
    else{
        
        for (int i=0; i<-n; i++) {
            resultat=resultat/x;
        }
        
    }

    // affichage du r�sultat
    printf("\n%f^%d=%f",x,n,resultat);
}

void resistance(){
    char choix;
    float resultat, choix1, choix2;// données pour calculer les resistances totales ou la tension
    
    
    printf("Selectionnez une de ces options: \n a) Résistances parallèles\n b) Résistances séries\n c) Tension \n q) Quitter\n");
    
    scanf("%c",&choix);
    
    while (choix!='q'){
        
        switch (choix) {
            case 'a':
                printf("Entrez la valeur de la premiere resistance");
                scanf("%f",&choix1);
                printf("Entrez la valeur de la deuxieme resistance");
                scanf("%f",&choix2);
                
                resultat=(choix1*choix2)/(choix1+choix2);
                
                printf("La resistance totale est: %f\n",resultat);
                
                break;
                
            case 'b':
                printf("Entrez la valeur de la premiere resistance");
                scanf("%f",&choix1);
                printf("Entrez la valeur de la deuxieme resistance");
                scanf("%f",&choix2);
                
                resultat=choix1+choix2;
                
                printf("La resistance totale est: %f\n",resultat);
                
                break;
                
            case 'c':
                printf("Entrez la valeur de la  resistance");
                scanf("%f",&choix1);
                printf("Entrez la valeur du courant");
                scanf("%f",&choix2);
                
                resultat=choix2*choix1;
                
                printf("La resistance totale est: %f\n",resultat);

                break;
            
            case 'q':
                break;
                
            default:
                printf("Choix invalide\n\n");
                break;
        }
        printf("Selectionnez une de ces options: \n a) Résistances parallèles\n b) Résistances séries\n c) Tension \n q) Quitter\n");
          
          scanf(" %c",&choix);
    }
    
    
    
}

int main() {
    unite();
    puissance_do_while();
    puissance_for();
    resistance();
    return 0;
}
