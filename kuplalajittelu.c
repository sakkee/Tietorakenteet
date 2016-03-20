#include <stdio.h>
#include <stdlib.h>


int main (void) {
    int lista[20];
    for (int i=0;i<20;i++) {
        lista[i] = rand();
    }
    for (int i=0 ; i<20;i++) {
        printf("VANHA %d\n", lista[i]);
    }
    int changed=1;
    while(changed==1) {
        changed=0;
        for (int i=0;i<19;i++) {
            if (lista[i]>lista[i+1]) {
                
                int tmp=lista[i];
                lista[i]=lista[i+1];
                lista[i+1] = tmp;
                changed=1;
            }
        }
    }
    for (int i=0 ; i<20;i++) {
        printf("UUSI %d\n", lista[i]);
    }
}