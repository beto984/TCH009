//
//  main.c
//  Exo1
//
//  Created by Humberto Villarino on 2019-11-05.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>

#define UNITE 0
#define DIZAINE 1
#define CENTAINE 2

void afficher_somme(int val, int u, int d, int c);

int chiffre_du_nombre(int nombre, int pos);

void unite_dizaine_centaine(int nombre, int* unite, int* dizaine, int* centaine);


int main(int argc, const char * argv[]) {
    int nombre=589;
    int u,d,c;
    
    //Utilisation sans pointeurs
    u=chiffre_du_nombre(nombre, UNITE);
    d=chiffre_du_nombre(nombre, DIZAINE);
    c=chiffre_du_nombre(nombre, CENTAINE);
    afficher_somme(nombre, u, d, c);
    
    //Utilisation avec pointeurs
    unite_dizaine_centaine(nombre, &u, &d, &c);
    afficher_somme(nombre, u, d, c);
    
    return 0;
    
}

void afficher_somme(int val, int u, int d, int c){
    printf("%d= %d + %dx10 + %dx100\n",val,u,d,c );
}

int chiffre_du_nombre(int nombre, int pos){
    for (int i=0; i<pos; i++) {
        nombre/=10;
    }
    nombre=nombre % 10;
    
    return nombre;
}

void unite_dizaine_centaine(int nombre, int* unite, int* dizaine, int* centaine){
    *unite = chiffre_du_nombre(nombre, UNITE);
    *dizaine = chiffre_du_nombre(nombre, DIZAINE);
    *centaine =chiffre_du_nombre(nombre, CENTAINE);
}
