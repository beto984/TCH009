//
//  main.c
//  chaine
//
//  Created by Humberto Villarino on 2019-11-22.
//  Copyright © 2019 Humberto Villarino. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAILLETAB 50

int nbCaractere(char Tab[]);
void strupr(char Tab[]);// Creation de la fonction car la fonction strupr n'est pas dans la librarie string.h
void enMinuscule(char Tab[]);

int main(int argc, const char * argv[]) {
    
    char message[TAILLETAB];
    strcpy(message,"Whatever");
    
    printf("%s \n", message);
    
    printf("%d \n", nbCaractere(message));
    
    strupr(message);
    
    printf("%s \n", message);
    
    enMinuscule(message);
    
    printf("%s \n", message);
    
    return 0;
}

int nbCaractere(char Tab[]){
    int nb=0;
    for (int i=0; i<TAILLETAB; i++) {
        if(Tab[i]=='\0'){
            break;
        }
        else{
            nb++;
        }
    }
    return nb;
}

void strupr(char Tab[]){
    for (int i=0;i<TAILLETAB;i++){
        if (Tab[i]=='\0'){
            break;
        }
        else{
            Tab[i]=toupper(Tab[i]);
        }
    }
}

void enMinuscule(char Tab[]){
    for (int i=0;i<TAILLETAB;i++){
        if (Tab[i]=='\0'){
            break;
        }
        else{
            Tab[i]=tolower(Tab[i]);
        }
    }
}
