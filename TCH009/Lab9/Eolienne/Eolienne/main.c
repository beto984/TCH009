//
//  main.c
//  Eolienne
//
//  Created by Humberto Villarino on 2019-11-15.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define TAILLETAB 10

void afficheTab1D(double Tab[],int taille);
double interpoleTab1D(double Tab[], double x, int taille);

int main(int argc, const char * argv[]) {
    double tabEff[10]={0.0,0.36,0.45,0.5,0.53,0.54,0.55,0.42,0.27,0.2};
    
    afficheTab1D(tabEff, TAILLETAB);
    
    printf("%lf \n",interpoleTab1D(tabEff, 0, TAILLETAB));
    printf("%lf \n",interpoleTab1D(tabEff, 2.5, TAILLETAB));
    printf("%lf \n",interpoleTab1D(tabEff, 9, TAILLETAB));
    
    return 0;
}

void afficheTab1D(double Tab[], int taille){
    for (int i=0; i<taille; i++) {
        printf("%d  %0.2lf\n\n",i, Tab[i]);
    }
}

double interpoleTab1D(double Tab[], double x, int taille){
    double efficacite;
    int y=floor(x);
    printf("%d ", y);
    if (x==0) {
        efficacite=Tab[0];
    }
    else if(x>=taille){
        efficacite=Tab[9];
    }
    else{
        efficacite=Tab[y]+((y+1)-y)*(x-y);
    }
    return efficacite;
}
