//
//  main.c
//  chuteLibre
//
//  Created by Humberto Villarino on 2019-11-08.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define DELTAT 0.1

void actualiser_temps(double * t, double deltaT);
void actualiser_vitesse(double *v, double a, double deltaT);
void actualiser_hauteur(double *h,double v, double deltaT);


int main(int argc, const char * argv[]) {
    double h=10.0;
    double t= 0.0;
    double v=0.0;
    double a=9.8;
    
    //On calcule le temps de chute avant de modifier les valeurs initiales;
    double temps_de_chute=sqrt((2*h)/a);
    
    printf("t= %lf, h=%lf, v=%lf\n",t,h,v);
    
    //On utilise do-while car on veut savoir la derniere valeur, meme si elle est negative
    do{
        actualiser_temps(&t, DELTAT);
        actualiser_vitesse(&v, a, DELTAT);
        actualiser_hauteur(&h, v, DELTAT);
        
        printf("t= %lf, h=%lf, v=%lf\n",t,h,v);
    }while (h>0);
    
    printf("-----------------------------------\n");
    printf("Le temps de chute est: %lf\n\n", temps_de_chute);
    
    return 0;
}

//On passe le temps comme pointeur afin de pouvoir le modifier
void actualiser_temps(double *t, double deltaT){
    *t += deltaT;
}

//On passe la vitesse comme pointeur afin de pouvoir le modifier
void actualiser_vitesse(double *v, double a, double deltaT){
    *v = *v+a*deltaT;
}

//On passe la hauteur comme pointeur afin de pouvoir le modifier
void actualiser_hauteur(double *h, double v, double deltaT){
    *h = *h-v*deltaT;
}
